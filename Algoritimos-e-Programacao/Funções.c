#include <stdio.h>
#include <string.h>

typedef struct{
	char name[50];
	int age, age2;
	double sal;
}Cadastro;

Cadastro cadastraFuncionario(){
	Cadastro f1;
	printf("Digite seus dados:\n");
	printf("Nome: ");
	__fpurge(stdin);
	fgets(f1.name, 50, stdin);
	printf("Idade: ");
	scanf("%d", &f1.age);
	printf("Salario: ");
	scanf("%lf", &f1.sal);
	printf("Anos de empresa: ");
	scanf("%d", &f1.age2);
	return f1;
}

void verificaContrato(int id){
	if(id < 18){
		printf("O funcionario precisa ser jovem aprendiz\n");
	}
	else{
		printf("O funcionario não pode ser efetivo\n");
	}
}

double aumentaSalario(double sal){
	double aum;
	printf("Digite a porcentagem a ser aumentada:\n");
	scanf("%lf", &aum);
	//printf("%d\n", aum);
	aum=aum/100;
	//printf("%d\n", aum);
	sal=sal+(sal*aum);
	printf("Novo salario: R$ %.2lf\n", sal);
	return sal;
}
void exibeDados(Cadastro f1){
	printf("Nome: %sIdade: %d anos\nSalario: R$ %.2lf\nTempo de empresa: %d ano(s)\n", f1.name, f1.age, f1.sal, f1.age2);
}

double bonificaSalario(double sal, int age2){
	int cont=0, i;
	for(i=1; i<=age2; i++){
		if(i%5==0){
			cont++;
		}
	}
	sal=sal+(100*cont);
	printf("Salario atualizado: R$ %.2lf\n", sal);
	return sal;
} 

int main(void){
	int op;
	Cadastro fun;

	do{
		system("clear");
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃ Digite o número da função desejada: ┃\n");
		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("┃ 1 - Cadastrar novo funcionario      ┃\n");
		printf("┃ 2 - Verificar um contato            ┃\n");
		printf("┃ 3 - Aumentar salario                ┃\n");
		printf("┃ 4 - Exibir dados                    ┃\n");
		printf("┃ 5 - Bonificar salario               ┃\n");
		printf("┃ 0 - Sair                            ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		scanf("%d", &op);

		switch(op){
			case 1:
				fun = cadastraFuncionario();
				break;
			case 2:
				verificaContrato(fun.age);
				system("sleep 5");
				break;
			case 3:
				fun.sal = aumentaSalario(fun.sal);
				system("sleep 3");
				break;
			case 4:
				exibeDados(fun);
				system("sleep 10");
				break;
			case 5:
				fun.sal = bonificaSalario(fun.sal, fun.age2);
				system("sleep 3");
				break;
			case 0:
				printf("Saindo...\n");
				break;
			default:
				printf("Opção invalida, tente novamente...\n");
				system("sleep 3");
				break;
		}
	}while(op != 0);


	return 0;
}