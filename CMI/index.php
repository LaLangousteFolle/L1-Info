<!DOCTYPE HTML>
<?php 
$sq = require 'config.php';
$number = file_get_contents("compteur.txt");
//$value = "0";
//file_put_contents("compteur.txt",$value);
?>


<html lang = 'en'>
<meta charset = 'UTF-8'>
<head>

  <title> Compteur de personnes </title>

  <meta http-equiv = "refresh" content ="1">

  <link rel = "stylesheet" href = "style.css">

</head>

<body>

<div class="container">

  <div id ="number"> 

    Il y a actuellement  
  
    <?php echo htmlspecialchars($number); ?>

    personnes dans cette salle.
    <?php echo $sq ?>

 </div>

</div>


</body>
</html>

