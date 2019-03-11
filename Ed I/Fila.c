#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define TAM 100

typedef struct{
	int codigo;
	char nome[TAM];
	double preco;	
}produto;

typedef struct nodo{
	produto prod;
	struct nodo *prox;
}tp_nodo;

void *push(tp_nodo *u){
	tp_nodo *v = (tp_nodo *)calloc(1, sizeof(tp_nodo));
	v->prox = u;
	__fpurge(stdin);
	printf("\t\tDigite o nome do produto: \n\t\t");
	fgets(v->prod.nome, 100, stdin);
	printf("\t\tDigite o preço do produto: \n\t\t");
	scanf("%lf", &v->prod.preco);
	printf("\t\tDigite o codigo do produto: \n\t\t");
	scanf("%d", &v->prod.codigo);
	return v;
}

void *pop(tp_nodo *u){
	int i;
	tp_nodo *ant = NULL, *aux = u;
	if(u == NULL){
		printf("\t\tLista vazia!\n");
		system("sleep 2");
		return u;
	}
	for( ; aux->prox != NULL; ant = aux, aux = aux->prox);
	if(ant == NULL)
		u = NULL;
	else
		ant->prox = NULL;
	free(aux);
	return u;
}

void mostra(tp_nodo *u){
	if(u == NULL){
		printf("\t\tLista vazia! \n");
	} 
	for( ; u != NULL; u = u->prox){
		printf("\t\tNome: %s", u->prod.nome);
		printf("\t\tPreço: R$ %.2lf\n", u->prod.preco);
		printf("\t\tCodigo: %d\n\n", u->prod.codigo);
	}
	system("sleep 3");
}
void menu(void){
		system("clear");
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃                Fila                ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➊ ─ Inserir um produto na Fila     ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➋ ─ Extrair um produto da Fila     ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➌ ─ Mostrar produtos da Fila       ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ⓿ ─ Sair                           ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\t\t");
}

void main(void){
	int op, n;
	tp_nodo *u = NULL;
	do{
		menu();
		scanf("%d", &op);
		switch(op){
			case 1:
				u = push(u);
				break;
			case 2:
				u = pop(u);
				break;
			case 3:
				mostra(u);
				break;
			case 0:
				printf("Saindo...\n");
				free(u);
				break;
			default:
				printf("Opção invalida digite novamente\n");
				system("sleep 2");
				break;
		}
	}while(op != 0);
}
