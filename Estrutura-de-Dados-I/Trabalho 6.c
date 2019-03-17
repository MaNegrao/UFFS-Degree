#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct _produto{
	int cod;
	char nome[20];
	double preco;
}tp_produto;

typedef struct _nodo{
	tp_produto prod;
	struct _nodo *next;
	struct _nodo *prev;
}tp_nodo;

typedef struct _lista{
	int cont;
	tp_nodo *first;
	tp_nodo *last;
}tp_lista;

void menu(){
		system("clear");
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃      Lista Duplamente Encadeada     ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➊ ─ Inserir produto na Lista        ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➋ ─ Extrair produto da Lista        ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➌ ─ Ordenar Lista com Insertion     ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➍ ─ Ordenar Lista com Selection     ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➎ ─ Mostrar Lista                   ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ⓿ ─ Sair                            ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\t\t");
}

void *push(tp_lista *l){
	tp_nodo *v = (tp_nodo *)calloc(1, sizeof(tp_nodo));
	__fpurge(stdin);
	printf("\t\tDigite o nome do produto: \n\t\t");
	fgets(v->prod.nome, 100, stdin);
	printf("\t\tDigite o preço do produto: \n\t\t");
	scanf("%lf", &v->prod.preco);
	printf("\t\tDigite o codigo do produto: \n\t\t");
	scanf("%d", &v->prod.cod);
	l->cont++;
	if(l->cont == 1){
		l->first = l->last = v;
		v->next = v->prev = NULL;
	}
	else{
		l->last->next = v;
		v->next = NULL;
		v->prev = l->last;
		l->last = v;
	}
	return l;
}

void *pop(tp_lista *l){
	int n;
	if(l->first == NULL){
		printf("\t\tLista vazia!\n");
		system("sleep 2");
		return l;
	}
	printf("\t\tDigite o codigo o produto que deseja excluir: \n\t\t");
	scanf("%d", &n);
	tp_nodo *aux = l->first;
	for( ; aux != NULL; aux = aux->next){
		if(aux->prod.cod == n)
			break;
	}
	if(aux == NULL){
		printf("\t\tNão encontrado!\n");
	}
	else if(l->cont == 1){
		l->first = l->last = NULL;
	}
	else if(aux == l->last){
		l->last = aux->prev;
		l->last->next = NULL;
	}
	else if(aux == l->first){
		l->first = aux->next;
		l->first->prev = NULL;
	}
	else{
		aux->next->prev = aux->prev;
		aux->prev->next = aux->next;
	}
	l->cont--;
	free(aux);
	return l;
}

void insertionSort(tp_lista *l){
	tp_nodo *i, *j, *aux;
	if(l->first == NULL){
		printf("\t\tLista vazia!\n");
		system("sleep 2");
		return;
	}
	for(i = l->first->next; i != NULL; i = i->next){
		for(j = i->prev, aux = i; j!= NULL; j = j->prev){
			if(aux->prod.cod < j->prod.cod){
				if(l->cont == 2){
					l->first = j->prev = aux;
					l->last = aux->next = j;
					aux->prev = j->next = NULL;
				}
				else if(j == l->first){
					l->first = j->prev = aux;
					aux->next->prev = j;
					j->next = aux->next;
					aux->next = j;
					aux->prev = NULL;
				}
				else if(aux == l->last){
					l->last = aux->next = j;
					j->prev->next = aux;
					aux->prev = j->prev;
					aux->next = j;
					j->next = NULL;
				}
				else{
					aux->next->prev = j;
					j->prev->next = aux;
					j->next = aux->next;
					aux->prev = j->prev;
					aux->next = j;
					j->prev = aux;
				}
			}
		}
	}
}

void selectionSort(tp_lista *l){
	tp_nodo *i, *j, *aux, *aux2, *aux3, *aux4;
	if(l->first == NULL){
		printf("\t\tLista vazia!\n");
		system("sleep 2");
		return;
	}
	for(i = l->first; i != NULL; i = i->next){
		aux = aux2 = i;
		for(j = i; j != NULL; j = j->next){
			if(j->prod.cod < aux->prod.cod){
				aux = j;
			}
		}
		if(aux == aux2)
			continue;
		else if((aux2 == l->first) && (aux == l->last)){
			l->first = aux2->next->prev = aux;
			l->last = aux->prev->next = aux2;
			aux->next = aux2->next;
			aux2->prev = aux->prev;
			aux2->next = aux->prev = NULL;
		}
		else if((aux2 == l->first) && (aux == l->first->next)){
			l->first = aux2->prev = aux;
			aux2->next = aux->next;
			aux->next = aux2->next->prev = aux2;
			aux->prev = NULL;
		}
		else if((aux == l->last) && (aux2 == l->last->prev)){
			l->last = aux->next = aux2;
			aux->prev = aux2->prev;
			aux2->prev = aux2->prev->next = aux;
			aux2->next = NULL;
		}
		else if(aux2 == l->first){
			aux3 = aux->prev;
			aux4 = aux->next;
			l->first = aux2->next->prev = aux;
			aux->next = aux2->next;
			aux2->prev = aux3;
			aux2->next = aux4;
			aux3->next = aux4->prev = aux2;
			aux->prev = NULL;
		}
		else if(aux == l->last){
			aux3 = aux2->prev;
			aux4 = aux2->next;
			l->last = aux->prev->next = aux2;
			aux2->prev = aux->prev;
			aux2->next = NULL;
			aux->prev = aux3;
			aux->next = aux4;
			aux3->next = aux4->prev = aux;
		}
		else if(aux == aux2->next){
			aux->next->prev = aux2;
			aux2->prev->next = aux;
			aux2->next = aux->next;
			aux->prev = aux2->prev;
			aux->next = aux2;
			aux2->prev = aux;
		}
		else{
			aux3 = aux->prev;
			aux4 = aux->next;
			aux->next = aux2->next;
			aux->prev = aux2->prev;
			aux->next->prev = aux->prev->next = aux;
			aux2->next = aux4;
			aux2->prev = aux3;
			aux3->next = aux4->prev = aux2;
		}
		i = aux;
	}
}

void main(void){
	tp_lista *li = (tp_lista *)calloc(1, sizeof(tp_lista));
	li->first = li->last = NULL;
	li->cont = 0;

	int op, n;

	do{
		menu();
		scanf("%d", &op);
		switch(op){
			case 1:
				li = push(li);
				break;
			case 2:
				li = pop(li);
				break;
			case 3:
				insertionSort(li);
				break;
			case 4:
				selectionSort(li);
				break;
			case 5:
				lista(li->first);
				break;
			case 0:
				printf("Saindo...\n");
				free(li);
				break;
			default:
				printf("Opção invalida digite novamente\n");
				system("sleep 2");
				break;
		}
	}while(op != 0);
}