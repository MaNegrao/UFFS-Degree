#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define TAM 50

typedef struct{
	int cod;
	char nome[TAM];
	double preco;	
}produto;

typedef struct{
	produto *info;
	int topo;
}pilha;

void menu(void){
		system("clear");
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃                Pilha               ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➊ ─ Inserir um produto             ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➋ ─ Extrair um produto             ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➌ ─ Mostrar valores da pilha       ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ⓿ ─ Sair                           ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\t\t");
}

void push(pilha *pi, int n){
	if(pi->topo == (n-1)){
		printf("Pilha cheia\n");
		system("sleep 2");
		return;
	}
	pi->topo++;
	printf("Digite o nome do produto [%d] da pilha: \n", pi->topo);
	__fpurge(stdin);
	fgets((pi->info+pi->topo)->nome, 50, stdin);
	printf("Digite o valor do produto [%d] da pilha: \n", pi->topo);
	scanf("%lf", &(pi->info+pi->topo)->preco);
	printf("Digite o codigo do produto [%d] da pilha: \n", pi->topo);
	scanf("%d", &(pi->info+pi->topo)->cod);
}

void pop(pilha *pi){
	if(pi->topo == -1){
		printf("Pilha vazia\n");
		system("sleep 2");
		return;
	}
	printf("Produto da posição [%d] foi retirado da pilha!\n", pi->topo);
	pi->topo--;
	system("sleep 2");
}

void mostra(pilha *pi){
	if(pi->topo == -1){
		printf("Pilha vazia\n");
		system("sleep 2");
		return;
	}
	for(int i = pi->topo; i > -1; i--){
		//printf("Produto [%d]:\n\n", i);
		printf("Nome: %s", (pi->info+i)->nome);
		printf("Preço: R$ %.2lf\n", (pi->info+i)->preco);
		printf("Coigo do produto: %d\n\n", (pi->info+i)->cod);
		printf("Coigo do produto: %d\n", (pi->info+i)->cod);
	}
	system("sleep 5");
}
void main(){
	int op, n;
	pilha *pi = (pilha *)calloc(1, sizeof(pilha));
	pi->topo = -1;
	printf("Digite a Quantidade de produtos desejada: \n");
	scanf("%d", &n);
	pi->info = (produto *)calloc(n, sizeof(produto));
	do{
		menu();
		scanf("%d", &op);
		switch(op){
			case 1:
				push(pi, n);
				break;
			case 2:
				pop(pi);
				break;
			case 3:
				mostra(pi);
				break;
			case 0:
				printf("Saindo...\n");
				free(pi);
				break;
			default:
				printf("Opção invalida digite novamente\n");
				system("sleep 2");
				break;
		}
	}while(op != 0);
}
