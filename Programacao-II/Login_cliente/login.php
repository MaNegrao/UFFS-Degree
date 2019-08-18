<?php
include "includes/cabecalho.php";
?>
	<!-- area central com 3 colunas -->
	<div class="container">

		<?php
			include "includes/menu_lateral.php";
		?>
		<section class="col-2">
			<h2>Entre ou cadastre-se</h2>
			<br><br>
			<form action="verificacao_login.php" method="post">
		  		Login: <input type="text" name="login"><br><br>
		  		Senha: <input type="password" name="senha"><br><br>
		      <div style="color: red">
		        <?php
		        if(isset($_GET['erro'])){
		          if($_GET['erro'] == 1)
		            echo "Login incorreto";
		          elseif($_GET['erro'] == 2)
		            echo "Senha incorreta";
		        }
    	 	   ?>
    		</div>
    		<input type="submit" value="Entrar">
    		<a href="cad_cliente.php">Cadastre-se</a>
    		<p><a href="#">Esqueci minha</a></p>
		</section>
	
	<?php
	include "includes/mais_pedidos.php";
	?>	
	<!-- fim area central -->
<?php
include "includes/rodape.php";
?>	