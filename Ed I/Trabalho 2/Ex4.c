#include <stdio.h>
#include <stdlib.h>

int* uniao(int *v1, int n1, int *v2, int n2){
	int c = n1 + n2, i;
	int *v3 = (int *) calloc(c, sizeof(int));
	for(i = 0; i < n1; i++){
		*(v3 + i) = *(v1 + i);
	}
	for(i = 0; n1 < c; n1++, i++){
		*(v3 + n1) = *(v2 + i);
	}
	return v3;
}

int main(void){
	int i, j, n1, n2, c;
	printf("Digite a quantidade de elementos dos dois vetores:\n");
	scanf("%d %d", &n1, &n2);
	c = n1 + n2;
	int *v1 = (int *) calloc(n1, sizeof(int));
	int *v2 = (int *) calloc(n2, sizeof(int));
	for(i = 0; i < n1; i++){
		printf("Vetor [1]   Posição[%d]: ", i);
		scanf("%d", v1+i);
	}
	printf("\n");
	for(i = 0; i < n2; i++){
		printf("Vetor [2]   Posição[%d]: ", i);
		scanf("%d", v2+i);
	}
	int *v3 = uniao(v1, n1, v2, n2);
	system("clear");
	for(i = 0; i < c; i++){
		printf("\nVetor [3] Posição[%d]: %d\n", i,*(v3+i));
	}
	free(v1);
	free(v2);
	free(v3);
	return 0;
}