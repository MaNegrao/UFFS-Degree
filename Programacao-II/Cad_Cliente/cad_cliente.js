
document.getElementById("perfilP").onclick = function(){
	document.getElementById("empresa").disabled = false;
	document.getElementById("mensagem-empresa").innerHTML = "Entre em contato pra estabelecer uma parceria!";
};

document.getElementById("perfilC").onclick = function(){
	document.getElementById("empresa").value = "";
	document.getElementById("empresa").disabled = true;
	document.getElementById("mensagem-empresa").innerHTML = "";	
};

document.getElementById("form-contato").onsubmit = validaCadastro;

function validaCadastro(){
	var contErro = 0;

	// validação do campo nome
	var nome = document.getElementById("nome");
	var erro_nome = document.getElementById("msg-nome");
	if((nome.value == "") || (nome.value.indexOf(" ") == -1)){
		erro_nome.innerHTML = "Por favor digite o Nome completo";
		erro_nome.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_nome.style.display = "none";
	}

	// validação do campo email
	var email = document.getElementById("email");
	var erro_email = document.getElementById("msg-email");
	if((email.value == "") || (email.value.indexOf("@") == -1)){
		erro_email.innerHTML = "Por favor digite o E-mail";
		erro_email.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_email.style.display = 'none';
	}

	// validação do campo endereco
	var endereco = document.getElementById("endereco");
	var erro_endereco = document.getElementById("msg-endereco");
	if(endereco.value == ""){
		erro_endereco.innerHTML = "Por favor digite o Endereço completo";
		erro_endereco.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_endereco.style.display = "none";
	}

	// validação do campo bairro
	var bairro = document.getElementById("bairro");
	var erro_bairro = document.getElementById("msg-bairro");
	if((bairro.value == "")){
		erro_bairro.innerHTML = "Por favor selecione o Bairro";
		erro_bairro.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_bairro.style.display = 'none';
	}	

	// validação do campo perfil
	var perfilP = document.getElementById("perfilP");
	var perfilC = document.getElementById("perfilC");
	var erro_perfil = document.getElementById("msg-perfil");
	if(!perfilP.checked & !perfilC.checked){
		erro_perfil.innerHTML = "Por favor selecione o Perfil";
		erro_perfil.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_perfil.style.display = 'none';
	}		

	// validação do campo login
	var login = document.getElementById("login");
	var erro_login = document.getElementById("msg-login");
	if(login.value == ""){
		erro_login.innerHTML = "Por favor digite o login";
		erro_login.style.display = 'block';
		contErro+=1;
	}
	else if (login.value.length < 6){
		erro_login.innerHTML = "O Login deve possuir pelo menos 6 caracteres";
		erro_login.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_login.style.display = 'none';
	}

	// validação do campo senha
	var senha = document.getElementById("senha");
	var erro_senha = document.getElementById("msg-senha");
	if(senha.value == ""){
		erro_senha.innerHTML = "Por favor digite a Senha";
		erro_senha.style.display = 'block';
		contErro+=1;
	}
	else if (senha.value.length < 6){
		erro_senha.innerHTML = "A Senha deve possuir pelo menos 6 caracteres";
		erro_senha.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_senha.style.display = 'none';
	}

	// validação da repetição da senha
	var senha2 = document.getElementById("senha2");
	var erro_senha2 = document.getElementById("msg-senha2");
	if((senha2.value == "") || (senha.value != senha2.value)){
		erro_senha2.innerHTML = "A senha não confere";
		erro_senha2.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_senha2.style.display = 'none';
	}	

	// validação do checkbox
	var concordo = document.getElementById("concordo");
	var erro_concordo = document.getElementById("msg-concordo");
	if(!concordo.checked){
		erro_concordo.innerHTML = "Você precisa concordar com os termos de uso do site";
		erro_concordo.style.display = 'block';
		contErro+=1;
	}
	else{
		erro_concordo.style.display = 'none';
	}		

	if(contErro > 0)
		return false;
	else
		alert("Cadastro efetuado com sucesso"); // será removido posteriormente
}
