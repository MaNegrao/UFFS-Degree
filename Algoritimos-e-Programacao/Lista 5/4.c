#include <stdio.h>

int main (void){

	int v[7],n,i;
	printf("Digite os numeros de um vetor\n");
	for(i=0; i < 7; i++){
		scanf("%d", &v[i]);
	}
	printf("Digite um numero para verificar se pertence ao vetor\n");
	scanf("%d", &n);
	for(i=0; i < 7; i++){
		if(v[i] == n){
			printf("O numero aparece na prosição %d\n",i+1);
			break;
		}
	}

	return 0;
}
