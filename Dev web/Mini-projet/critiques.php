<?php

if (isset($_GET["suppr"])) {
    // methodes de verif trouvee sur stack egalement https://stackoverflow.com/a/3497060 permet de verifier que la variable existe
    $id_suppr = intval($_GET["suppr"]);
    $lignes = file("donnees.txt");
    $fp = fopen("donnees.txt", "w");
    foreach ($lignes as $ligne) {
        $d = explode("|", trim($ligne));
        if (intval($d[0]) != $id_suppr) {
            fwrite($fp, $ligne);
        }
    }
    fclose($fp);
}

$critiques = [];
$lignes = file("donnees.txt");
foreach ($lignes as $ligne) {
    if (trim($ligne) != "") {
        $d = explode("|", trim($ligne));
        $critiques[] = [
            "id" => $d[0],
            "nom" => $d[1],
            "type" => $d[2],
            "annee" => $d[3],
            "note" => $d[4],
            "texte" => $d[5],
        ];
    }
}
?>

<h2>Liste des critiques</h2>
<a href="index.php?page=editcritique" class="w3-button w3-pale-blue">+ Ajouter une critique</a>
<br><br>

<div class="w3-row-padding">
<?php foreach ($critiques as $c): ?>
    <div class="w3-third w3-margin-bottom">
        <div class="w3-card w3-white w3-padding w3-pale-yellow">
            <!--raccourcis trouve sur https://stackoverflow.com/questions/14876653/quickest-way-to-write-php-echo-->
            <h3 class="w3-bold"><?= $c["nom"] ?></h3>
            <p><?= $c["type"] ?> — <?= $c["annee"] ?></p>
            <p><?= str_repeat("⭐", $c["note"]) ?></p>
            <!--moyen de plus simple pour eviter une tonne d'if statement pour chaque etoile-->
            <p><?= $c["texte"] ?></p>
            <a href="index.php?page=editcritique&id=<?= $c[
                "id"
            ] ?>" class="w3-button w3-pale-blue w3-small">Modifier</a>
            <a href="index.php?page=critiques&suppr=<?= $c["id"] ?>"
               class="w3-button w3-pale-red w3-small"
               onclick="return confirm('Supprimer ?')">Supprimer</a>
        </div>
    </div>
<?php endforeach; ?>
</div>
