<?php
	
	function saudacao(){
		$hr = date(" H ");
		if($hr >= 12 && $hr<18) {
			$resp = "Boa tarde!";
		}
		else if($hr >= 6 && $hr <12 ){
			$resp = "Bom dia!";
		}
		else if($hr >= 0 && $hr < 6){
			$resp = "Boa Madrugada";
		}
		else{
			$resp = "Boa noite!";
		}
		return "$resp";
	}

	function diaSemana(){
		$day = date(" N ");	
		if($day == 1){
			$resps = "Segunda-Feira";
		}
		else if($day == 2){
			$resps = "Terça-Feira";
		}
		else if($day == 3){
			$resps = "Quarta-Feira";
		}
		else if($day == 4){
			$resps = "Quinta-Feira";
		}
		else if($day == 5){
			$resps = "Sexta-Feira";
		}
		else if($day == 6){
			$resps = "Sabado";
		}
		else if($day == 7){
			$resps = "Domingo";
		}	
		return "$resps";
	}
	$d = date(" d ");
	$m = date(" m ");
	$a = date(" Y ");

	$sa = saudacao();
	$ds = diaSemana();

	echo $sa. " Hoje é " .$ds. ", Dia" .$d. "/" .$m. "/" .$a. ".";
?>