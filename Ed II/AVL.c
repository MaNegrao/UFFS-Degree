/*  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
 	┃ Este codigo pertence a Matheus Dias Negrão      ┃
	┃ Academico de Ciencia da Computação - 3ª Fase    ┃
	┃ Universidade Federal da Fronteira Sul - Chapecó ┃
	┃ Diciplina Estrutura de Dados II - AVL Tree em C ┃
	┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
	int key, alt; 
	struct node *r, *l;
}node;

int altn(node *a){
	if(a == NULL)
		return -1;
	return a->alt;
}

int max(int a, int b){
	return (a > b) ? a : b;
}

int ver(node *a){
	return abs(altn(a->l) - altn(a->r));
}

void rotRR(node **ra){
	node *aux = (*ra)->l;
	(*ra)->l = aux->r;
	aux->r = (*ra);
	(*ra)->alt = max(altn((*ra)->l), altn((*ra)->r)) + 1;
	aux->alt = max(altn(aux->l), (*ra)->alt) + 1;
	(*ra) = aux;
}

void rotLL(node **ra){
	node *aux = (*ra)->r;
	(*ra)->r = aux->l;
	aux->l = (*ra);
	(*ra)->alt = max(altn((*ra)->l), altn((*ra)->r) + 1);
	aux->alt = max((*ra)->alt, altn(aux->r) + 1);
	(*ra) = aux;
}

void rotRL(node **ra){
	rotRR(&(*ra)->r);
	rotLL(ra);
}

void rotLR(node **ra){
	rotLL(&(*ra)->l);
	rotRR(ra);
}

int insertion(node **root, int v){
	int res = 0;
	if((*root) == NULL){
		(*root) = (node *)calloc(1, sizeof(node));
		(*root)->key = v;
		(*root)->l = NULL;
		(*root)->r = NULL;
		(*root)->alt = 0;
		return 1;
	}
	node *ax = (*root);
	if(v < (*root)->key){
		if((res = insertion(&(a->l), v)) == 1){
			if(ver(a) >= 2){
				if(v < (*root)->l->key){
					rotRR(root);
				}
				else{
					rotLR(root);
				}
			}
		}
	}
	else if(v > (*root)->key){
		if((res = insertion(&(a->r), v)) == 1){
			if(ver(a) >= 2){
				if(v > (*root)->r->key){
					rotLL(root);
				}
				else{
					rotRL(root);
				}
			}
		}
	}
	else{
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ Este elemento já foi inserido!  ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		return 0;
	}
	a->alt = max(altn(a->l), altn(a->r)) + 1;
	return res;
}

void print(node *root, int n){
	int i;
	if(root != NULL){
		printf("\t\t┃ Nivel: %d", n);
		printf("\t\tChave: %2.d ┃\n", root->key);
		print(root->l, n+1);
		print(root->r, n+1);
	}
}

void menu(){
		system("clear");
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃            Arvore AVL           ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➊ ─ Inserir elemento            ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➋ ─ Exibir elementos            ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ⓿ ─ Sair                        ┃\n");
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
				if(insertion(&tree, v)){
					printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
					printf("\t\t┃ Elemento inserido com sucesso!  ┃\n");
					printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
				}
				system("sleep 1");
				break;
			case 2:
				printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("\t\t┃        Imprimindo Arvore        ┃\n");
				printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
				print(tree, 0);
				printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
				system("sleep 3");
				break;
			case 0:
				printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("\t\t┃ Saindo...                       ┃\n");
				printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
				free(tree);
				break;
			default:
				printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("\t\t┃ Opção invalida digite novamente ┃\n");
				printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
				system("sleep 2");
				break;
		}
	}while(op != 0);
}
