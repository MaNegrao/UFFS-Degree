<?php
include "includes/conexao.php";
if(isset($_POST['confirmar'])){
	$nome = addslashes($_POST['nome']);
	$email = addslashes($_POST['email']);
	$endereco = addslashes($_POST['endereco']);
	$bairro = isset($_POST['bairro']) ? $_POST['bairro'] : 0;
	$perfil = isset($_POST['perfil']) ? 1 : 0;
	$empresa = addslashes(isset($_POST['empresa']) ? $_POST['empresa'] : 'NULL');
	$login = addslashes($_POST['login']);
	$senha = $_POST['senha'];
	$senha2 = $_POST['senha2'];
	$concordo = isset($_POST['concordo']) ? 1 : 0;

	$erros = array();

	if(empty($nome)){
		$erros[] = "O nome não pode ser vazio";
	}

	if(empty($email)){
		$erros[] = "O E-mail não pode ser vazio";
	}

	if(empty($endereco)){
		$erros[] = "O Endereço não pode ser vazio";
	}

	if(!$bairro){
		$erros[] = "É necessário selecionar o bairro";
	}

	if(!$perfil){
		$erros[] = "É necessário selecionar o perfil";
	}
	else{
		$perfil = $_POST['perfil'];
	}

	if(!$perfil | $perfil == 'c'){
		$empresa = 'NULL';
	}

	else if($perfil == 'p' && empty($empresa)){
		$erros[] = "Digite a Empresa";
	}

	if(empty($login)){
		$erros[] = "O login não pode estar vazio";
	}

	if(strlen($senha) < 6){
		$erros[] = "A Senha deve possuir pelo menos 6 caracteres";
	}

	if(strcmp($senha, $senha2)){
		$erros[] = "A senha não confere";
	}

	if(!$concordo){
		$erros[] = "Deve ler e concordar com os termos de uso";
	}

	$senha = md5($senha);

	if(count($erros) == 0){
		echo $sql = "INSERT INTO cliente (nome, email, endereco, bairro, perfil, nomeEmpresa, login, senha) VALUES ('$nome', '$email', '$endereco', '$bairro', '$perfil', '$empresa', '$login', '$senha')";

		$resultado = mysqli_query($conexao, $sql);
		if($resultado){
			$mensagem = "O usuario <strong>$nome</strong> foi inserido com sucesso";
		}
		else{
			$mensagem = "Erro. O usuario não pôde ser cadastrado. ";
			$mensagem .= mysqli_error($conexao); // para debug
		}

	}

}


include "includes/cabecalho.php";
?>
	<!-- area central com 3 colunas -->
	<div class="container">
		<?php
		include "includes/menu_lateral.php";
		?>

		<section class="col-2">
			<h2>Cadastre-se</h2>
			<?php
				if (isset($mensagem)){
					echo "<p>$mensagem</p>";
				}
				else{ // carrega form
					if(isset($erros)){
						echo "<ul>";
						foreach ($erros as $erro){
							echo "<li style='color: red;'>$erro</li>";
						}
						echo "</ul>";
					}
			?>
			<div>
				<form action="" method="post" id="form-contato" enctype="multipart/form-data">
				    <div class="form-item">
				      <label for="nome" class="label-alinhado">Nome:</label>
				      <input type="text" id="nome" name="nome" size="50" placeholder="Nome completo" value="<?=isset($_POST['nome']) ? $_POST['nome'] : '';?>">
				      <span class="msg-erro" id="msg-nome"></span>
				    </div>
				    <div class="form-item">
				      <label for="email" class="label-alinhado">E-mail:</label>
				      <input type="email" id="email" name="email" placeholder="fulano@dominio" size="50" value="<?=isset($_POST['email']) ? $_POST['email'] : '';?>">
				      <span class="msg-erro" id="msg-email"></span>
				    </div>					    
				    <div class="form-item">
				      <label for="endereco" class="label-alinhado">Endereço:</label>
				      <input type="text" id="endereco" name="endereco" placeholder="Rua, número, complemento" size="50" value="<?=isset($_POST['nome']) ? $_POST['nome'] : '';?>">
				      <span class="msg-erro" id="msg-endereco"></span>
				    </div>	
				    <div class="form-item">
				      <label for="bairro" class="label-alinhado">Bairro:</label>
				      <select name="bairro" id="bairro">
					    <option value="" disabled selected style="display: none;"></option>
					    <option value="centro">Centro</option>
					    <option value="efapi">Efapi</option>
					    <option value="presidente medice">Presidente Médici</option>
					    <option value="Jardim Itália">Jardim Itália</option>
					    <option value="Maria Goretti">Maria Goretti</option>
					  </select>
					  <span class="msg-erro" id="msg-bairro"></span>
				    </div>
				    <div class="form-item">
				      <label class="label-alinhado">Perfil:</label>
				      <?php
				      	if(isset($_POST['perfil'])){
				      		$perfil = $_POST['perfil'];
				      	}
				      	else{
				      		$perfil = '';
				      	}
				      ?>
				      <label><input type="radio" name="perfil" value="c" id="perfilC" <?= ($perfil == 'c') ? "checked" : ''?>>Consumidor final</label>
				      <label><input type="radio" name="perfil" value="p" id="perfilP" <?= ($perfil == 'p') ? "checked" : ''?>>Prestador de serviço</label>
					  <span class="msg-erro" id="msg-perfil"></span>
				    </div>
				    <div class="form-item">
				      <label for="empresa" class="label-alinhado">Nome da empresa:</label>
				      <input type="text" id="empresa" name="empresa" value="<?=isset($_POST['empresa']) ? $_POST['empresa'] : '';?>"><span id="mensagem-empresa" ></span>
				      <span class="msg-erro" id="msg-empresa"></span>
				    </div>					    
				    <div class="form-item">
				      <label for="login" class="label-alinhado">Login:</label>
				      <input type="text" id="login" name="login" placeholder="Mínimo 6 caracteres" value="<?=isset($_POST['login']) ? $_POST['login'] : '';?>">
				      <span class="msg-erro" id="msg-login"></span>
				    </div>				    
				    <div class="form-item">
				      <label for="senha" class="label-alinhado">Senha:</label>
				      <input type="password" id="senha" name="senha" placeholder="Mínimo 6 caracteres" value="<?=isset($_POST['senha']) ? $_POST['empresa'] : '';?>">
				      <span class="msg-erro" id="msg-senha"></span>
				    </div>
				    <div class="form-item">
				      <label for="senha2" class="label-alinhado">Repita a Senha:</label>
				      <input type="password" id="senha2" name="senha2" placeholder="Mínimo 6 caracteres">
				      <span class="msg-erro" id="msg-senha2"></span>
				    </div>
				    <div class="form-item">
				      <label class="label-alinhado"></label>
				      <label><input type="checkbox" id="concordo" name="concordo" value="1"> Li e estou de acordo com os termos de uso do site</label>
				      <span class="msg-erro" id="msg-concordo"></span>
				    </div>				    
				    <div class="form-item">
				    	<label class="label-alinhado"></label>
				    <input type="submit" id="botao" value="Confirmar" name="confirmar">
				    </div>
				</form>
			</div>
		<?php
			} // fecha else
		?>			
		</section>
	<?php
	include "includes/mais_pedidos.php";
	?>
	</div>
	<script src="js/cad_cliente.js"></script>
	<!-- fim area central -->
<?php
include "includes/rodape.php";
?>
