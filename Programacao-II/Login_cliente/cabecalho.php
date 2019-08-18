<?php
session_start();
?>
<!DOCTYPE html>
<html lang="pt-br">
<head>
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<meta charset="utf-8">
	<title>Rent a Tool</title>
	<link rel="stylesheet" type="text/css" href="css/rent.css">
	<link rel="stylesheet" type="text/css" href="css/forms.css">
	<link rel="stylesheet" type="text/css" href="css/produto_carrinho.css">

	<link href="https://fonts.googleapis.com/css?family=Lobster" rel="stylesheet"> <!-- web font Lobster -->
</head>
<body>
	<!-- cabeçalho -->
	<header>
		<h1>Rent a Tool</h1>
		<?php
			if(isset($_SESSION['id'])){
				echo "<p class='login'>Bem vindo, ".$_SESSION['login']."<a href='sair.php'> (Sair)</a></p>";
			}
			else{
				echo "<p class='login'><a href='login.php'>Login</a></p>";
			}

		?>
		<p class="carrinho"><a href="carrinho.php">Meu carrinho <img src="img/cart.png" width="32"></a></p>
		<p id="exibeMenu">Menu</p>
		<nav class="menu-opcoes">    
			<ul>
				<li><a href="#">Minha Conta</a></li>
				<li><a href="#">Programa de pontos</a></li>
				<li><a href="#">Consumo solidário</a></li>
				<li><a href="#">Quem somos</a></li>
				<li><a href="#">Ajuda</a></li>
			</ul>
		</nav>
	</header>
	<!-- fim cabeçalho -->