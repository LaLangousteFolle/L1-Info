import csi
import ml
import utime
from ml.postprocessing.darknet import YoloLC

# ── Config ───────────────────────────────────────────────────────────────────
IMG_W      = 192
IMG_H      = 192
LINE_Y_IN  = int(IMG_H * 0.35)   # ~67 px
LINE_Y_OUT = int(IMG_H * 0.65)   # ~124 px
MAX_DIST2  = 50 * 50              # distance² (évite sqrt)
MAX_LOST   = 5

# ── Init caméra & modèle ─────────────────────────────────────────────────────
csi0 = csi.CSI(delays = False, fflush = False)
csi0.reset()
csi0.pixformat(csi.RGB565)
csi0.framesize(csi.QVGA)         # 320×240, recadré à 192×192 → plus rapide que VGA
csi0.window((IMG_W, IMG_H))

model  = ml.Model("/rom/yolo_lc_192.tflite", postprocess=YoloLC(threshold=0.4))
n      = len(model.labels)
colors = [(int(255 * i // n), int(255 * (n-i-1) // n), 255) for i in range(n)]
_img_buf = [None]                 # buffer réutilisé — évite une alloc par frame


# ── Tracking ─────────────────────────────────────────────────────────────────
def nearest_track(cx, cy, tracked):
    """Retourne l'ID du track le plus proche (distance², sans sqrt)."""
    best_id, best_d2 = None, MAX_DIST2
    for tid, t in tracked.items():
        px, py = t["pos"]
        d2 = (cx - px) * (cx - px) + (cy - py) * (cy - py)
        if d2 < best_d2:
            best_id, best_d2 = tid, d2
    return best_id


def update_tracks(centers, tracked, next_id, counts):
    matched  = set()
    used     = set()
    prev_in  = counts["in"]
    prev_out = counts["out"]

    for j, (cx, cy) in enumerate(centers):
        tid = nearest_track(cx, cy, tracked)
        if tid is None:
            continue

        t      = tracked[tid]
        prev_y = t["pos"][1]
        t["pos"]  = (cx, cy)
        t["lost"] = 0
        matched.add(tid)
        used.add(j)

        # ── Sens ENTRÉE : déplacement haut → bas ─────────────────────────
        # Étape 1 : franchit la ligne IN
        if not t["step_in"] and prev_y < LINE_Y_IN and cy >= LINE_Y_IN:
            t["step_in"] = True
        # Étape 2 : franchit ensuite la ligne OUT → comptage IN confirmé
        if t["step_in"] and not t["counted"] and prev_y < LINE_Y_OUT and cy >= LINE_Y_OUT:
            counts["in"] += 1
            t["counted"] = True

        # ── Sens SORTIE : déplacement bas → haut ─────────────────────────
        # Étape 1 : franchit la ligne OUT (en remontant)
        if not t["step_out"] and prev_y > LINE_Y_OUT and cy <= LINE_Y_OUT:
            t["step_out"] = True
        # Étape 2 : franchit ensuite la ligne IN → comptage OUT confirmé
        if t["step_out"] and not t["counted"] and prev_y > LINE_Y_IN and cy <= LINE_Y_IN:
            counts["out"] += 1
            t["counted"] = True

    # Nouveaux tracks — initialisés sans flags actifs
    for j, (cx, cy) in enumerate(centers):
        if j not in used:
            tracked[next_id] = {
                "pos":      (cx, cy),
                "step_in":  False,   # a-t-il franchi LINE_Y_IN vers le bas ?
                "step_out": False,   # a-t-il franchi LINE_Y_OUT vers le haut ?
                "counted":  False,   # déjà comptabilisé pour ce passage ?
                "lost":     0,
            }
            next_id += 1

    # Nettoyage
    for tid in [tid for tid, t in tracked.items() if tid not in matched]:
        tracked[tid]["lost"] += 1
    for tid in [tid for tid, t in tracked.items() if t["lost"] > MAX_LOST]:
        del tracked[tid]

    return next_id, counts["in"] - prev_in, counts["out"] - prev_out


# ── Détection ────────────────────────────────────────────────────────────────
def detect(img):
    centers = []
    _img_buf[0] = img                          # réutilisation du buffer liste
    for i, dets in enumerate(model.predict(_img_buf)):
        for (x, y, w, h), _ in dets:
            cx, cy = x + w // 2, y + h // 2
            centers.append((cx, cy))
            img.draw_rectangle(x, y, w, h, color=colors[i], thickness=2)
            img.draw_cross(cx, cy, color=colors[i])
    return centers


# ── UI image ─────────────────────────────────────────────────────────────────
def draw_ui(img, counts):
    img.draw_line(0, LINE_Y_IN,  IMG_W, LINE_Y_IN,  color=(0, 200, 0),   thickness=2)
    img.draw_line(0, LINE_Y_OUT, IMG_W, LINE_Y_OUT, color=(200, 50, 50), thickness=2)
    img.draw_string(2,  2, "IN : " + str(counts["in"]),  color=(0, 220, 0),   scale=2)
    img.draw_string(2, 22, "OUT: " + str(counts["out"]), color=(220, 60, 60), scale=2)


# ── Log série ────────────────────────────────────────────────────────────────
_t0 = utime.ticks_ms()

def log(counts, n_tracks, delta_in, delta_out):
    elapsed = utime.ticks_diff(utime.ticks_ms(), _t0) // 1000
    h, s    = divmod(elapsed, 3600)
    m, s    = divmod(s, 60)
    ts      = "{:02d}:{:02d}:{:02d}".format(h, m, s)

    tag_in  = " <<< ENTREE" if delta_in  > 0 else ""
    tag_out = " >>> SORTIE" if delta_out > 0 else ""

    print("[{}]  IN={:3d}{}  OUT={:3d}{}  (tracks actifs: {})".format(
        ts,
        counts["in"],  tag_in,
        counts["out"], tag_out,
        n_tracks
    ))


# ── Boucle principale ────────────────────────────────────────────────────────
def main():
    tracked = {}
    next_id = 0
    counts  = {"in": 0, "out": 0}
    INFER_EVERY = 2   # inférer 1 frame sur 2
    frame_count = 0
    last_centers = []
    while True:
        img = csi0.snapshot()
        frame_count += 1
        if frame_count % INFER_EVERY == 0:
           last_centers = detect(img)
           img              = csi0.snapshot()
           centers          = detect(img)
           next_id, di, do  = update_tracks(centers, tracked, next_id, counts)
           draw_ui(img, counts)
           log(counts, len(tracked), di, do)

main()
