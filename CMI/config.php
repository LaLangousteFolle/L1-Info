<?php

$host = "localhost";
$db   = "comptage";
$usr  = "admin";
$pass = "admin";

// Token partagé avec le Pi — à changer et garder secret
define('PUSH_TOKEN', 'changeme_token_secret');

try {
    $pdo = new PDO("mysql:host=$host;dbname=$db", $usr, $pass);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $pdo->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC);
} catch (PDOException $e) {
    die(json_encode(["error" => "Erreur de connexion : " . $e->getMessage()]));
}

return $pdo;
