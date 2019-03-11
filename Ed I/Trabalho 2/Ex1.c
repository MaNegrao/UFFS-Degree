#include <stdio.h>
#include <stdlib.h>

int main(){
	int num, i;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &num);
	int *p = (int*)calloc(num, sizeof(int));
	printf("Preencha as posições do vetor\n");
	for(i = 0; i < num; i++){
		printf("Posição %d: ", i);
		scanf("%d", p+i);
	}
	if(p){
		for(i = 0; i < num; i++){
			printf("\nPosição: %d\tValor: %d\n", i, *(p+i));
		}	
	}
	free(p);
    return 0;
}