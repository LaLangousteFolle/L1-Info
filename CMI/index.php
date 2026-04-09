<?php
$pdo = require 'config.php';
ini_set('display_errors', 1);
error_reporting(E_ALL);

const SALLE_ID    = 133;
const COUNTER_FILE = 'compteur.txt';

function readCount(): int { return (int) file_get_contents(COUNTER_FILE); }
function writeCount(int $v): void { file_put_contents(COUNTER_FILE, max(0, $v)); }

function increase(): void { writeCount(readCount() + 1); }
function decrease(): void { writeCount(readCount() - 1); }
function resetting(): void { writeCount(0); }

function commit($pdo): void
{
    $stmt = $pdo->prepare(
        "INSERT INTO compte_personnes (id_salle, nb_entree, nb_sorties, date)
         VALUES (?, ?, ?, NOW())"
    );
    // nb_entree = valeur courante, nb_sorties = 0 (on enregistre le net)
    $stmt->execute([SALLE_ID, readCount(), 0]);
}

function pushCount($pdo, int $count): void
{
    writeCount($count);
    // Pas d'INSERT ici — commit() reste la seule action qui écrit l'historique
}

// ── Routeur ───────────────────────────────────────────────────────────────
if ($_SERVER['REQUEST_METHOD'] === 'POST')
{
    $action = $_POST['action'] ?? '';

    if ($action === 'push') {
        // Vérification du token
        $token = $_POST['token'] ?? '';
        if (!hash_equals(PUSH_TOKEN, $token)) {
            http_response_code(403);
            echo json_encode(['error' => 'forbidden']);
            exit;
        }
        pushCount($pdo, (int) ($_POST['count'] ?? 0));
        header('Content-Type: application/json');
        echo json_encode(['status' => 'ok', 'count' => readCount()]);
        exit;
    }

    if ($action === 'poll') {
        header('Content-Type: application/json');
        echo json_encode(['count' => readCount()]);
        exit;
    }

    if ($action === 'increase')     increase();
    elseif ($action === 'decrease') decrease();
    elseif ($action === 'commit')   commit($pdo);
    elseif ($action === 'reset')    resetting();

    if (!empty($_SERVER['HTTP_X_REQUESTED_WITH'])) {
        header('Content-Type: application/json');
        echo json_encode(['count' => readCount()]);
        exit;
    }

    header('Location: ' . $_SERVER['PHP_SELF']);
    exit;
}

$history = $pdo
    ->query("SELECT nb_entree, nb_sorties, date FROM compte_personnes
             WHERE id_salle = " . SALLE_ID . "
             ORDER BY date DESC LIMIT 5")
    ->fetchAll();

$compteur = readCount();
?>
<!DOCTYPE HTML>
<html lang="fr">
<head>
  <meta charset="UTF-8">
  <title>Compteur de personnes</title>
  <link rel="stylesheet" href="style.css">
</head>
<body>

<div class="controls">

  <p class="label">Personnes présentes</p>
  <p class="value" id="counter"><?= $compteur ?></p>

  <div class="buttons">
    <button class="btn btn-increase" onclick="action('increase')">＋ Entrée</button>
    <button class="btn btn-decrease" onclick="action('decrease')">－ Sortie</button>
  </div>
  <div class="buttons">
    <button class="btn btn-commit" onclick="action('commit')">💾 Sauvegarder</button>
    <button class="btn btn-reset"  onclick="action('reset')">↺ Reset</button>
  </div>

  <?php if ($history): ?>
  <table class="history">
    <thead><tr><th>Date</th><th>Net sauvegardé</th></tr></thead>
    <tbody>
    <?php foreach ($history as $row): ?>
      <tr>
        <td><?= htmlspecialchars($row['date']) ?></td>
        <td><?= $row['nb_entree'] - $row['nb_sorties'] ?></td>
      </tr>
    <?php endforeach; ?>
    </tbody>
  </table>
  <?php endif; ?>

</div>

<script>
async function action(name) {
  const fd = new FormData();
  fd.append('action', name);
  const res  = await fetch('', {
    method: 'POST',
    headers: { 'X-Requested-With': 'XMLHttpRequest' },
    body: fd
  });
  const data = await res.json();
  document.getElementById('counter').textContent = data.count;
}

setInterval(async () => {
  const fd = new FormData();
  fd.append('action', 'poll');
  const res  = await fetch('', { method: 'POST', body: fd });
  const data = await res.json();
  document.getElementById('counter').textContent = data.count;
}, 2000);
</script>

</body>
</html>
