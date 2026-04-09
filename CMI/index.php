<!DOCTYPE HTML>
<?php 
//$pdo = require 'config.php';
ini_set('display_errors',1);
error_reporting(E_ALL);

function readIn()
{
	return file_get_contents('compteur_in.txt');
}

function readOut()
{
	return file_get_contents('compteur_out.txt');
}

function writeIn($val)
{
	file_put_contents('compteur_in.txt',max(0,$val));
}

function writeOut($val)
{
	file_put_contents('compteur_out.txt',max(0,$val));
}

function increase()
{
	writeIn(readIn() + 1);
}

function decrease()
{
	if( readIn() > readOut())
	{
		writeOut(readOut() + 1);
	}
}

function resetting()
{
	writeOut(0);
	writeIn(0);
}

function commit($pdo, $id)
{
	$number_in = readIn();
	$number_out = readOut();
	$time = date('Y-m-d H:i:s');

	$quer = $pdo->prepare("INSERT INTO compte_personnes (id_salle, nb_entree, nb_sorties, date) VALUES (?,?,?,?)");
	$quer->execute([$id, $number_in, $number_out, $time]);
}

if($_SERVER['REQUEST_METHOD'] === 'POST')
{
	$action = $_POST['action'] ?? '';
	if($action === 'increase') increase();
	elseif($action === 'decrease') decrease();
	elseif($action === 'commit') commit($pdo,133);
	elseif($action === 'reset') resetting();

	header('Location: ' . $_SERVER['PHP_SELF']);
	exit;
}

$compteur = readIn() - readOut();
?>




<html lang = 'en'>
<meta charset = 'UTF-8'>
<head>

  <title> Compteur de personnes </title>

  <meta http-equiv = "refresh" content ="1">

  <link rel = "stylesheet" href = "style.css">

</head>

<body>

<div class='controls'> 
	<p class='value'> <?php echo $compteur; ?> </p>	
	<form method='POST'>
	<input type='hidden' name='action' value='increase'>
	<button type='submit' class='btn btn-increase'> Augmenter </button>
<div class='button'>
	</form>

	<form method='POST'>
	
	<input type='hidden' name='action' value='decrease'>
	<button type='submit' class='btn btn-decrease'> Diminuer </button>
</form>

<form method='POST'>
	<input type='hidden' name='action' value='commit'>
	<button type='submit' class='btn btn-commit'> Sauvegarder </button>
</form>

<form method='POST'>
	<input type='hidden' name='action' value='reset'>
	<button type='submit' class='btn btn-reset'> Reset </button>
</form>
</div>
</div>

</body>

</html>

