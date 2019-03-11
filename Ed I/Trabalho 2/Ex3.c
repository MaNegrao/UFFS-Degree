#include <stdio.h>
#include <stdlib.h>

int main(void){
	int num, cont = 0, i = 0;
	int *p = (int *) calloc(5, sizeof(int));
	while(p){
		printf("Posição [%d]: ", i);
		scanf("%d", p+i);
		if(*(p+i) == 0){
			break;
		}
		if(cont == 4){
			int *pNew = (int *) realloc(p, (i+6) * sizeof(int));
				if(pNew){
					p = pNew;
				}
			printf("Realocou\n");
			cont = -1;
		}
		i++; cont++;
	}
	system("clear");
	for(int j = 0; j < i; j++){
		printf("Posição [%d]: %d\n", j, *(p+j));
	}
	free(p);
	return 0;
}
