#include <stdio.h>
#include <string.h>

int main (void){
	double sal,salt;
	char ca[20];
	printf("Digite o cargo desejado e o salario relacionado\n");
	fgets(ca, 20, stdin);
	scanf("%lf",&sal);
	
	if((ca[0] =='G' || ca[0] == 'g') && ca[1] == 'e'){
		salt=sal+(sal*.1);
		printf("Reajuste para Gerente\nAntigo salario: R$ %2.lf\nNovo salario: R$ %.2lf\nDiferença: R$ %.2lf\n", sal, salt, salt-sal);
	}
	else if((ca[0] == 'E' || ca[0] == 'e') && ca[1] == 'n'){
		salt=sal+(sal*.2);
		printf("Reajuste para Engenehiro\nAntigo salario: R$ %2.lf\nNovo salario: R$ %.2lf\nDiferença: R$ %.2lf\n", sal, salt, salt-sal);
	}
	else if((ca[0] == 'T' || ca[0] == 't') && ca[1] == 'e'){
		salt=sal+(sal*.3);
		printf("Reajuste para Tecnico\nAntigo salario: R$ %2.lf\nNovo salario: R$ %.2lf\nDiferença: R$ %.2lf\n", sal, salt, salt-sal);		
	}else{
		salt=sal+(sal*.4);
		printf("Reajuste para %sAntigo salario: R$ %2.lf\nNovo salario: R$ %.2lf\nDiferença: R$ %.2lf\n", ca, sal, salt, salt-sal);				
	}

	return 0;
}