<?php
$id = "";
$nom = "";
$type = "restaurant";
$annee = date("Y");
$note = 0;
$texte = "";
$confirm = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $nom = $_POST["nom"];
    $type = $_POST["type"];
    $annee = $_POST["annee"];
    $note = $_POST["note"];
    $texte = $_POST["texte"];
    $id_post = $_POST["id"];

    if ($id_post == "") {
        $max_id = 0;
        $lignes = file("donnees.txt");
        foreach ($lignes as $ligne) {
            $d = explode("|", $ligne);
            if (intval($d[0]) > $max_id) {
                $max_id = intval($d[0]);
            }
        }
        $new_id = $max_id + 1;
        $fp = fopen("donnees.txt", "a");
        fwrite($fp, "$new_id|$nom|$type|$annee|$note|$texte\n");
        fclose($fp);
        $confirm = "ajoutée";
    } else {
        $lignes = file("donnees.txt");
        $fp = fopen("donnees.txt", "w");
        foreach ($lignes as $ligne) {
            $d = explode("|", trim($ligne));
            if (intval($d[0]) == intval($id_post)) {
                fwrite($fp, "$id_post|$nom|$type|$annee|$note|$texte\n");
            } else {
                fwrite($fp, $ligne);
            }
        }
        fclose($fp);
        $confirm = "modifiée";
    }
}

if ($confirm == "" && isset($_GET["id"])) {
    $lignes = file("donnees.txt");
    foreach ($lignes as $ligne) {
        $d = explode("|", trim($ligne));
        if (intval($d[0]) == intval($_GET["id"])) {
            $id = $d[0];
            $nom = $d[1];
            $type = $d[2];
            $annee = $d[3];
            $note = $d[4];
            $texte = $d[5];
        }
    }
}
?>

<?php if ($confirm != ""): ?>
    <p>Critique <?= $confirm ?> avec succès !</p>
    <a href="index.php?page=critiques" class="w3-button w3-pale-yellow">Retour aux critiques</a>

<?php else: ?>
    <h2><?= $id == "" ? "Ajouter" : "Modifier" ?> une critique</h2>

    <form method="post" action="index.php?page=editcritique<?= isset(
        $_GET["id"],
    )
        ? "&id=" . $_GET["id"]
        : "" ?>"
          onsubmit="
            if (document.getElementById('nom').value == '') {
                alert('Le nom est obligatoire !');
                return false;
            }
            if (document.getElementById('texte').value == '') {
                alert('La critique est obligatoire !');
                return false;
            }
          ">

        <input type="hidden" name="id" value="<?= $id ?>">

        <?php if ($id != ""): ?>
            <p>ID : <strong><?= $id ?></strong></p>
        <?php endif; ?>

        <label>Nom</label>
        <input class="w3-input w3-border w3-pale-yellow" type="text" name="nom" id="nom" value="<?= $nom ?>">

        <label>Type</label>
        <select class="w3-select w3-border w3-pale-yellow" name="type">
            <option value="restaurant" <?= $type == "restaurant"
                ? "selected"
                : "" ?>>Restaurant</option>
            <option value="bar"        <?= $type == "bar"
                ? "selected"
                : "" ?>>Bar</option>
        </select>

        <label>Année</label>
        <input class="w3-input w3-border w3-pale-yellow" type="number" name="annee" id="annee" value="<?= $annee ?>">

        <label>Note</label>
        <select class="w3-select w3-border w3-pale-yellow" name="note">
            <option value="0" <?= $note == 0 ? "selected" : "" ?>>0 </option>
            <option value="1" <?= $note == 1 ? "selected" : "" ?>>1 ⭐</option>
            <option value="2" <?= $note == 2
                ? "selected"
                : "" ?>>2 ⭐⭐</option>
            <option value="3" <?= $note == 3
                ? "selected"
                : "" ?>>3 ⭐⭐⭐</option>
            <option value="4" <?= $note == 4
                ? "selected"
                : "" ?>>4 ⭐⭐⭐⭐</option>
        </select>

        <label>Critique</label>
        <textarea class="w3-input w3-border w3-pale-yellow" name="texte" id="texte" rows="4"><?= $texte ?></textarea>

        <br>
        <button class="w3-button w3-pale-yellow" type="submit">Enregistrer</button>
    </form>
<?php endif; ?>
