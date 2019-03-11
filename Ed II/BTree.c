#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
	int ckey, *keys;
	struct node **child;
}node;

void *makeNode(int t){
	node *new = (node *)calloc(1, sizeof(node));
	new->child = (node **)calloc((2 * t), sizeof(node));
	new->keys = (int *)calloc(((2 * t) - 1), sizeof(int));
	new->ckey = 0;
	return new;
}

int bSearch(node *root, int key, int t){
	int mid, i = 0, f;
	f = root->ckey-1;
	
	while(i <= f){
		mid = (i + f)/2;
		if(root->keys[mid] == key)
			return mid;
		else if(root->keys[mid] > key)
			f = mid - 1;
		else
			i = mid + 1;
	}
	return i;
}

void iKey(node *root, int key, node *child_r, int t){
	int k, pos;
	pos = bSearch(root, key, t);
	k = root->ckey;
	while(k > pos && key < root->keys[k-1]){
		root->keys[k] = root->keys[k-1];
		root->child[k+1] = root->child[k];
		k--;
	}
	root->keys[pos] = key;
	root->child[pos+1] = child_r;
	root->ckey++;
}

void *insertion(node *root, int key, bool *h, int *ret, int t){
	int i, j, pos, kmed, aux;
	node *temp = makeNode(t);
	node *child_r = makeNode(t);

	if(root == NULL){
		*h = true;
		*ret = key;
		return NULL;
	}
	else{
		pos = bSearch(root, key, t);
		if(root->ckey > pos && root->keys[pos] == key)
			*h = false;
		else{
			child_r = insertion(root->child[pos], key, h, ret, t);
			if(*h){
				if(root->ckey < ((2 * t) - 1)){
					iKey(root, *ret, child_r, t);
					*h = false;
				}
				else{
					for(i = 0; i < ((t * 2) - 1); i++)
						temp->child[i] = NULL;
					kmed = root->keys[t-1];
					temp->child[0] = root->child[t];
					for(i = t; i < ((t * 2) - 1); i++){
						iKey(temp, root->keys[i], root->child[i+1], t);
					}
					for(i = t-1; i < ((t * 2) - 1); i++){
						root->keys[i] = 0;
						root->child[i+1] = NULL; 
					}
					root->ckey = t-1;
					if(pos <= t-1)
						iKey(root, *ret, child_r, t);
					else
						iKey(temp, *ret, child_r, t);
					*ret = kmed;
					return temp;
				}
			}
		}
	}
}

void *iBtree(node *root, int key, int t){
	bool h;
	int ret, i;
	node *child_r = makeNode(t);
	child_r = insertion(root, key, &h, &ret, t);
	if(h){
		node *newNode = makeNode(t);
		newNode->ckey = 1;
		newNode->keys[0] = ret;
		newNode->child[0] = root;
		newNode->child[1] = child_r;
		for(i = 2; i <= ((2 * t) - 1); i++)
			newNode->child[i] = NULL;
		return newNode;
	}
	else
		return root;
}

void print(node *root, int n){ //Usa recursão para printar
	int i, j;
	if(root != NULL){ //Até chegar nas folhas
		for(i = 0; i < root->ckey; i++){
			print(root->child[i], n+1);
			printf("\t\t┃ Chave: %3.d ", root->keys[i]);
			printf("\t\t Nivel: %d ┃\n", n);
		}
		print(root->child[i], n+1);
	}
}

void menu(){
	system("clear");
	printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t┃         ❃   Arvore B   ❃        ┃\n");
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
	int op, v, t;
	system("clear");
	printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t┃          Digite o 'T':          ┃\n");
	printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\t\t  ");
	scanf("%d", &t);
	do{
		menu();
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("\t\t┃ Digite a chave do elemento:     ┃\n");
				printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\t\t  ");
				scanf("%d", &v);
				tree = iBtree(tree, v, t);
				break;
			case 2:
				printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("\t\t┃    ❃   Imprimindo Arvore   ❃    ┃\n");
				printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
				print(tree, 1);
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
				break;
		}
	}while(op != 3);
}