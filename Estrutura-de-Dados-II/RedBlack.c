/*  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
 	┃ Este codigo pertence a Matheus Dias Negrão      ┃
	┃ Academico de Ciencia da Computação - 3ª Fase    ┃
	┃ Universidade Federal da Fronteira Sul - Chapecó ┃
	┃ Diciplina Estrutura de Dados II - RedBlack em C ┃
	┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
	int key, col;
	struct node *l, *r, *f; 
}node;

void *insertion(node *root, node *father, int v){
	if(root == NULL){ // A insersão ocorrerá sempre aqui, seja em folha ou em raiz
		root = (node *)calloc(1, sizeof(node));
		root->key = v;
		root->col = 1;
		root->f = father; 
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ Elemento inserido com sucesso!  ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		return root;
	}
	if(v < root->key) // insersão a esquerda
		root->l = insertion(root->l, root, v);
	else if(v > root->key) // insersão a direita
		root->r = insertion(root->r, root, v);
	else{ //Caso já haja esse valor na arvore
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ Este elemento já foi inserido!  ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	}
	return root;
}

void *fixup(node *root, int v){
	node *aux2, *unc, *granf, *aux = root;
	while(aux->key != v){ // Atribuindo a um auxiliar o ultimo nodo inserido
		if(aux->key > v)
			aux = aux->l;
		else
			aux = aux->r;
	}
	if((aux == root) || (aux->f->col == 0))
		return root;
	granf = aux->f->f;
	if(granf->key > v)
		unc = granf->r;
	else
		unc = granf->l;
	if((unc != NULL) && (unc->col == 1)){ //Caso 1, Tio é vermelho
		do{
			unc->col = aux->f->col = 0;
			granf->col = 1;
			if((granf->f != NULL) && (granf->f->col == 1)){ //Altera os ponteiros para nova verificação
				aux = granf;
				v = aux->key;
				granf = granf->f->f;
				if(granf->key > v)
					unc = granf->r;
				else
					unc = granf->l;
			}else
				return root;
		}while((unc != NULL) && (unc->col == 1)); // Verifica se há outras ocorrencias do Caso 1 na Arvore
	}
	if((aux->f)->key < v && (aux->f)->key < granf->key ||
		(aux->f)->key > v && (aux->f)->key > granf->key){ //Caso 2, Tio é preto e o nodo é do lado oposto do pai
		aux2 = aux->f;
		aux->f = aux2->f;
		aux2->f = aux;
		if(granf->key > v){ // Caso esteja na esquerda
			granf->l = aux;
			aux->l = aux2;
			aux2->r = NULL;
		}
		else{
			granf->r = aux; // Caso esteja na direita
			aux->r = aux2;
			aux2->l = NULL;
		}
		aux = aux2;
		v = aux->key;
	}
	aux = aux->f; //Caso chegue até aqui significa que está no Caso 3
	aux->f = granf->f;
	aux->col = 0;
	granf->col = 1;
	granf->f = aux;
	if(granf->key > v){
		aux->r = granf;
		granf->l = NULL;
	}
	else{
		aux->l = granf;
		granf->r = NULL;
	}
	if(aux->f != NULL){
		if(aux->f->key > v)
			aux->f->l = aux;
		else
			aux->f->r = aux;
	}
	else return aux;
	return root;
}

void print(node *root, int n){ //Usa recursão para printar
	if(root != NULL){ //Até chegar nas folhas
		if(root->col)
			printf("\t\t┃ \e[91;1mChave: %2.d ◉", root->key);
		else
			printf("\t\t┃ \e[30;1mChave: %2.d ◉", root->key);
		printf("\t\t Nivel: %d\e[0m ┃\n", n); // Através da recursão é possivel saber o nivel
		print(root->l, n+1);
		print(root->r, n+1);
	}
}

void menu(){
	system("clear");
	printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t┃     ❃   Arvore \e[91;1mRed\e[30;1mBlack\e[0m   ❃     ┃\n");
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t┃ ➊ ─ Inserir elemento            ┃\n");
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t┃ ➋ ─ Exibir elementos            ┃\n");
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t┃ ➌ ─ Sair do programa            ┃\n");
	printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\t\t  ");
}

void main(void){
	node *tree = NULL;
	int op, v;
	do{
		menu();
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("\t\t┃ Digite a chave do elemento:     ┃\n");
				printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\t\t  ");
				scanf("%d", &v);
				tree = insertion(tree, NULL, v);
				tree = fixup(tree, v);
				tree->col = 0;
				system("sleep .5");
				break;
			case 2:
				printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("\t\t┃    ❃   Imprimindo Arvore   ❃    ┃\n");
				printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
				print(tree, 0);
				printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
				system("sleep 3");
				break;
			case 3:
				printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("\t\t┃ Saindo do programa...           ┃\n");
				printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
				free(tree);
				break;
			default:
				printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("\t\t┃ Opção invalida digite novamente ┃\n");
				printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
				system("sleep 1");
				break;
		}
	}while(op != 3);
}
