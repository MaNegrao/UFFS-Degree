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

tp_nodo *push(tp_nodo *u){
	tp_nodo *v = (tp_nodo *)calloc(1, sizeof(tp_nodo));
	v->prox = u;
	__fpurge(stdin);
	printf("Digite o nome do produto: \n");
	fgets(v->prod.nome, 100, stdin);
	printf("Digite o codigo do produto: \n");
	scanf("%d", &v->prod.codigo);
	printf("Digite o preço do produto: \n");
	scanf("%lf", &v->prod.preco);
	return v;
}

void *pop(tp_nodo *u){
	int i, n;
	printf("Digite o codigo do produto que deseja extrair: \n");
	scanf("%d", &n);
	tp_nodo *ant = NULL, *aux;
	for(aux = u ; aux != NULL; aux = aux->prox){
		if(aux->prod.codigo == n){
			break;
		}
		ant = aux;
	}
	if(aux == NULL){
		printf("Não encontrado!\n");
	}
	else if(aux == u){
		u = u->prox;
		printf("Elemento de codigo [%d] extraido com sucesso!\n", n);
	}
	else{
		ant->prox = aux->prox;
		printf("Elemento de codigo [%d] extraido com sucesso!\n", n);
	}
	system("sleep 2");
	return u;
}

void mostra(tp_nodo *u){
	int i;
	if(u == NULL){
		printf("Lista vazia! \n");
	} 
	for( ; u != NULL; u = u->prox){
		printf("Nome: %s", u->prod.nome);
		printf("Preço: R$ %.2lf\n", u->prod.preco);
		printf("Codigo: %d\n\n", u->prod.codigo);
	}
	system("sleep 3");
}
void menu(void){
		system("clear");
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃     Lista Simplesmente Encadeada   ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➊ ─ Inserir um produto             ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➋ ─ Extrair um produto             ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➌ ─ Mostrar valores da Lista       ┃\n");
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
