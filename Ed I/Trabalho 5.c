#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct _produto{
	int codigo;
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
		printf("\t\t┃ ➌ ─ Mostrar Lista pelo First        ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➍ ─ Mostrar Lista pelo Last         ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ⓿ ─ Sair                            ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\t\t");
}

void selecao(){
	system("clear");
	printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t┃ Digite por onde irá começar a lista ┃\n");
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t┃ ➊ ─ Inserir na Lista pelo First     ┃\n");
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t┃ ⓿ ─ Inserir na Lista pelo Last      ┃\n");
	printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\t\t");

}

void *push(tp_lista *l, tp_nodo *u, int vrf){
	tp_nodo *v = (tp_nodo *)calloc(1, sizeof(tp_nodo));
	__fpurge(stdin);
	printf("\t\tDigite o nome do produto: \n\t\t");
	fgets(v->prod.nome, 100, stdin);
	printf("\t\tDigite o preço do produto: \n\t\t");
	scanf("%lf", &v->prod.preco);
	printf("\t\tDigite o codigo do produto: \n\t\t");
	scanf("%d", &v->prod.codigo);
	l->cont++;
	if(vrf){
		v->prev = u;
		l->last = v;
		if(l->cont == 1)
			l->first = v;
		else
			u->next = v;	
	}
	else{
		v->next = u;
		l->first = v;
		if(l->cont == 1)
			l->last = v;
		else
			u->prev = v;
	}	
	return v;
}

void *pop(tp_lista *l, tp_nodo *u, int vrf){
	int n;
	if(u == NULL){
		printf("\t\tLista vazia!\n");
		system("sleep 2");
		return u;
	}
	printf("\t\tDigite o codigo o produto que deseja excluir: \n\t\t");
	scanf("%d", &n);
	tp_nodo *aux = u;
	for( ; aux != NULL; aux = vrf ? aux->prev : aux->next){
		if(aux->prod.codigo == n)
			break;
	}
	if(aux == NULL){
		printf("\t\tNão encontrado!\n");
	}
	else if((aux == l->last) && !(aux == l->first)){
		l->last = l->last->prev;
		l->last->next = NULL;
	}
	else if((aux == l->first) && !(aux == l->last)){
		l->first = l->first->next;
		l->first->prev = NULL;
	}
	else if((aux == l->first) && (aux == l->last)){
		l->first = l->last = u = NULL;
	}
	else{
		aux->next->prev = aux->prev;
		aux->prev->next = aux->next;
	}
	l->cont--;
	free(aux);
	return u;
}

void listaLast(tp_nodo *u){
	if(u == NULL){
		printf("\t\tLista vazia! \n");
	} 
	for( ; u != NULL; u = u->prev){
		printf("\t\tNome: %s", u->prod.nome);
		printf("\t\tPreço: R$ %.2lf\n", u->prod.preco);
		printf("\t\tCodigo: %d\n\n", u->prod.codigo);
	}
	system("sleep 3");
}

void listaFirst(tp_nodo *u){
	if(u == NULL){
		printf("\t\tLista vazia! \n");
	} 
	for( ; u != NULL; u = u->next){
		printf("\t\tNome: %s", u->prod.nome);
		printf("\t\tPreço: R$ %.2lf\n", u->prod.preco);
		printf("\t\tCodigo: %d\n\n", u->prod.codigo);
	}
	system("sleep 3");
}


void main(void){
	tp_nodo *u = NULL;
	tp_lista *li = (tp_lista *)calloc(1, sizeof(tp_lista));
	li->first = li->last = NULL;
	li->cont = 0; 

	int op, n, vrf = 0;
	selecao();
	scanf("%d", &vrf);
	while(vrf != 0 && vrf != 1){
		printf("\t\tOpção invalida! Digite novamente\n\t\t");
		scanf("%d", &vrf);
	}

	do{
		menu();
		scanf("%d", &op);
		switch(op){
			case 1:
				u = push(li, u, vrf);
				break;
			case 2:
				u = pop(li, u, vrf);
				break;
			case 3:
				listaFirst(li->first);
				break;
			case 4:
				listaLast(li->last);
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