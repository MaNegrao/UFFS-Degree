#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct nodo{
 	int key;
	struct nodo *next;
}nodo;

typedef struct{
	nodo **table;
	int size;
}hash;

void *inicializa(hash *h){
	h = (hash *)malloc(sizeof(hash));
	h->table = (nodo **)calloc(8, sizeof(nodo));
	for(int i = 0; i < 8; i++){
		h->table[i] = (nodo *)malloc(sizeof(nodo));
	}
	return h;
}

void menu(){
		system("clear");
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃          Tabela Hash          ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➊ ─ Inserir chave             ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➋ ─ Buscar chave              ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➌ ─ Mostrar chaves            ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ⓿ ─ Sair                      ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\t\t");
}

void mostra(hash *h, int n){
	if(n == -1){
		printf("\t\tDigite qual posição da tabela deseja ver: ");
		scanf("%d", &n);
	}
	nodo *aux = h->table[n];
	printf("\n");
	for(int i = 0 ; aux != NULL; aux = aux->next, i++){
		printf("\t\tTabela[%d]\tKey[%d]: %d\n", n, i, aux->key);
	}
	system("sleep 2");
}

void push(hash *h){
	int n, res;
	printf("\t\tDigite a Key: ");
	scanf("%d", &n);
	res = n % 8;
	if(h->table[res]->key == 0){
		h->table[res]->key = n;
	}
	else{
		nodo *nv = (nodo *)calloc(1, sizeof(nodo));
		nv->key = n;
		nodo *aux = h->table[res];
		for( ; aux->next != NULL; aux = aux->next);
		aux->next = nv;
	}
	mostra(h, res);
}

void busca(hash *h){
	int n, p;
	printf("\t\tDigite o valor que deseja buscar: ");
	scanf("%d", &n);
	printf("\n");
	p = n % 8;
	nodo *aux = h->table[p];
	for(int i = 0 ; aux != NULL; aux = aux->next, i++){
		if(aux->key == n){
			printf("\t\tPosição da Tabela: %d\tPosição da Key: %d\n", p, i);
			break;
		}
	}
	if(aux == NULL){
		printf("\t\tElemento não encontrado!\n");
	}
	system("sleep 2");
}

void main(void){
	hash *h = inicializa(h);
	int op, n;

	do{
		menu();
		scanf("%d", &op);
		switch(op){
			case 1:
				push(h);
				break;
			case 2:
				busca(h);
				break;
			case 3:
				mostra(h, -1);
				break;
			case 0:
				printf("\t\tSaindo...\n");
				free(h);
				break;
			default:
				printf("\t\tOpção invalida digite novamente\n");
				system("sleep 2");
				break;
		}
	}while(op != 0);
}