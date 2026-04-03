<?php

$host = "localhost";
$db = "comptage";
$usr = "admin";
$pass =  "admin";

try {

$pdo =  new PDO("mysql:host = $host; dbname = $db;", $usr, $pass);

$pdo ->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

}

catch (PDOException $a)
{
die("Erreur de co : " . $a -> getMessage());
}

return $pdo;

?>
