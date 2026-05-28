<?php
$page = isset($_GET["page"]) ? $_GET["page"] : "presentation"; ?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>The Only Truth  Restaurants & Bars</title>
    <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
</head>

<body class="w3-pale-blue">
  <div class="w3-top w3-pale-green w3-card" style="padding: 20px 20px; text-align: center;">
    <span style="font-size: 140%; font-weight: bold; color: grey;">
      <span>The Only Truth</span>
      <img src="logo.png" style="width: 60px; vertical-align: middle; padding: 0px;">
      Restaurants &amp; Bars
    </span>
  </div>

  <nav class="w3-sidebar w3-card w3-round-large w3-pale-yellow w3-bar-block" style="width: 200px; height: 34%; position: fixed; top: 0; left: 0;">
      <div class="w3-container w3-margin-bottom w3-pale-green" style="padding: 1.3vh; text-Align:center;">
      <h3>The Only Truth</h3>
      </div>
      <a href="index.php?page=presentation" class="w3-bar-item w3-button w3-hover-pale-blue w3-ripple"
          style="display: block; text-align: center;">
          Accueil</a>
      <a href="index.php?page=critiques"    class="w3-bar-item w3-button w3-hover-pale-blue w3-ripple"
          style="display: block; text-align: center;">
          Critiques</a>
      <a href="index.php?page=editcritique" class="w3-bar-item w3-button w3-hover-pale-blue w3-ripple" style="display: block; text-align: center;">
          Ajouter</a>
  </nav>



<div style="margin-top: 80px;"></div>

<main style="margin-left: 200px; padding: 16px;">
  <?php if ($page == "presentation") {
      include "presentation.php";
  } elseif ($page == "critiques") {
      include "critiques.php";
  } elseif ($page == "editcritique") {
      include "editcritique.php";
  } ?>
</main>

<footer class="w3-pale-green w3-padding w3-footer w3-bottom" style="text-align: center;">
    <p style="color: black; margin: 0; font-size: 0.9;">
        Auteur : Noe SEILER Eleve de L1 au CERI
        Date : Mai 2026
    </p>
</footer>

</body>
</html>
