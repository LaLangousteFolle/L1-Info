import csi
import pyb
import ml
from ml.postprocessing.darknet import YoloLC

IMG_W      = 192
IMG_H      = 192
LINE_Y_IN  = int(IMG_H * 0.35)
LINE_Y_OUT = int(IMG_H * 0.65)
MAX_DIST2  = 50 * 50
MAX_LOST   = 5

usb   = pyb.USB_VCP()
csi0  = csi.CSI(delays=False, fflush=False)
csi0.reset()
csi0.pixformat(csi.RGB565)
csi0.framesize(csi.QVGA)
csi0.window((IMG_W, IMG_H))

model    = ml.Model("/rom/yolo_lc_192.tflite", postprocess=YoloLC(threshold=0.4))
_img_buf = [None]

tracked      = {}
next_id      = 0
counts       = {"in": 0, "out": 0}
frame_count  = 0
last_centers = []

while True:
    img = csi0.snapshot()
    frame_count += 1

    if frame_count % 2 == 0:
        last_centers = []
        _img_buf[0] = img
        for i, dets in enumerate(model.predict(_img_buf)):
            for (x, y, w, h), _ in dets:
                last_centers.append((x + w // 2, y + h // 2))

    # ── Tracking ─────────────────────────────────────────────────────────
    matched_tids = set()   # tracks déjà assignés ce frame
    used_dets    = set()   # détections déjà assignées ce frame

    # Construire toutes les paires (dist², tid, det_idx) et trier
    pairs = []
    for j, (cx, cy) in enumerate(last_centers):
        for tid, t in tracked.items():
            px, py = t["pos"]
            d2 = (cx - px) * (cx - px) + (cy - py) * (cy - py)
            if d2 < MAX_DIST2:
                pairs.append((d2, tid, j, cx, cy))
    pairs.sort()

    di = do = 0

    for d2, tid, j, cx, cy in pairs:
        if tid in matched_tids or j in used_dets:
            continue

        matched_tids.add(tid)
        used_dets.add(j)

        t      = tracked[tid]
        prev_y = t["pos"][1]
        t["pos"]  = (cx, cy)
        t["lost"] = 0

        if not t["step_in"] and prev_y < LINE_Y_IN and cy >= LINE_Y_IN:
            t["step_in"] = True
        if t["step_in"] and not t["counted"] and prev_y < LINE_Y_OUT and cy >= LINE_Y_OUT:
            counts["in"] += 1
            t["counted"] = True
            di += 1

        if not t["step_out"] and prev_y > LINE_Y_OUT and cy <= LINE_Y_OUT:
            t["step_out"] = True
        if t["step_out"] and not t["counted"] and prev_y > LINE_Y_IN and cy <= LINE_Y_IN:
            counts["out"] += 1
            t["counted"] = True
            do += 1

    # Nouvelles détections non matchées → nouveaux tracks
    for j, (cx, cy) in enumerate(last_centers):
        if j not in used_dets:
            tracked[next_id] = {
                "pos": (cx, cy), "step_in": False, "step_out": False,
                "counted": False, "lost": 0
            }
            next_id += 1

    for tid in [tid for tid, t in tracked.items() if tid not in matched_tids]:
        tracked[tid]["lost"] += 1
    for tid in [tid for tid, t in tracked.items() if t["lost"] > MAX_LOST]:
        del tracked[tid]

    if di or do:
        people_count = counts["in"] - counts["out"]
        usb.send("{}\r\n".format(people_count))
