<?php
	include "includes/conexao.php";
	include "../includes/functions.php";
	
	$sql = "SELECT c.id, c.login, c.senha from cliente c where c.login = '{$_POST['login']}'";

	$resultado = mysqli_query($conexao, $sql);
	$log = mysqli_fetch_array($resultado);

	$sen = md5($_POST['senha']);

	if($_POST['login'] != $log['login']){
		header("Location: login.php?erro=1");	
	}
	else{
		if($log['senha'] != $sen){
			header("Location: login.php?erro=2");
		}
		else{ // login e senha corretos
			session_start(); // abre uma nova sessao
			$_SESSION['id'] = $log['id'];
			$_SESSION['login'] = $_POST['login'];
			$_SESSION['inicio'] = date("H:i:s");
			header("Location: index.php");
		}
	}
?>