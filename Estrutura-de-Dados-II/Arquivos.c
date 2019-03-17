/*  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
 	┃ Este codigo pertence a Matheus Dias Negrão      ┃
	┃ Academico de Ciencia da Computação - 3ª Fase    ┃
	┃ Universidade Federal da Fronteira Sul - Chapecó ┃
	┃ Diciplina Estrutura de Dados II - Arquivos em C ┃
	┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct{
	int code;
	char name[20];
	float price;
}prod;

void menu(){
	system("clear");
	printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t┃   Sistema de armazenamento em Arquivos  ┃\n");
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t┃ ➊ ─ Cadastrar produto                   ┃\n");
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t┃ ➋ ─ Exibir produtos                     ┃\n");
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t┃ ➌ ─ Sair do programa                    ┃\n");
	printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\t\t  ");
}

void error(){
	printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t┃ Erro ao abrir arquivo...                ┃\n");
	printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	system("sleep 1");
}

void insertion(FILE *fp){
	prod p;
	if((fp = fopen("file.txt", "a")) != NULL){
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ Digite os dados do produto:             ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\t\t  Nome: ");
		__fpurge(stdin);
		fgets(p.name, 20, stdin);
		fwrite(p.name, strlen(p.name), 1, fp);
		printf("\t\t  Codigo: ");
		scanf("%d", &p.code);
		fprintf(fp, "%d\n", p.code);
		printf("\t\t  Preço: ");
		scanf("%f", &p.price);
		fprintf(fp, "%f\n\n", p.price);
		fclose(fp);
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ Produto inserido com sucesso!           ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		system("sleep 1");
	}
	else
		error();
}

void print(FILE *fp){
	prod p;
	if((fp = fopen("file.txt", "rt")) != NULL){
		rewind(fp);
		printf("\t\t┏━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━┓\n");
		printf("\t\t┃ Codigo ┃ Nome do Produto      ┃  Preço  ┃\n");
		while(!feof(fp)){
			fscanf(fp, "%s", p.name);
			fscanf(fp, "%d\n", &p.code);
			fscanf(fp, "%f\n", &p.price);
			int a1 = abs(p.price);
			p.price -= a1;
			int a2 = p.price * 100;
			printf("\t\t┣━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━┫\n");
			printf("\t\t┃ %6.d ┃ %20s ┃ %4d.%2d ┃\n", p.code, p.name, a1, a2);	
		}
		printf("\t\t┗━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━┛\n");	
		system("sleep 2");
		fclose(fp);
	}
	else
		error();
}

void main(void){
	int op;
	FILE *fp;
	do{
		menu();
		scanf("%d", &op);
		switch(op){
			case 1:
				insertion(fp);
				break;
			case 2:
				print(fp);
				break;
			case 3:
				printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("\t\t┃ Saindo do programa...                   ┃\n");
				printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
				break;
			default:
				printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("\t\t┃ Opção invalida digite novamente...      ┃\n");
				printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		}
	}while(op != 3);
}