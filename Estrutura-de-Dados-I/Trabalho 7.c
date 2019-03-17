#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>

void insertion(int v[], int n){
  int j, chave, i;
  for(j = 1; j <= n-1; j++){
    chave = v[j];
    i = j - 1;
    while(i >= 0 && v[i] > chave){
      v[i+1] = v[i];
      i--;
    }
    v[i+1] = chave;
  }
}

int buscaBinaria(int x, int v[], int e, int d){
	int meio = (e + d)/2;

	if (v[meio] == x)
		return meio;
	if (e >= d)
		return -1; //não encontrado
	else
		if (v[meio] < x)
			return buscaBinaria(x, v, meio+1, d);
		else
			return buscaBinaria(x, v, e, meio-1);
}

void main(){
	int num, i, v[10], ans;
	printf("Digite os numeros do vetor\n");
	for(i = 0; i < 10; i++){
		scanf("%d", &v[i]);
	}
	insertion(v, 10);
	system("clear");
	for(i = 0; i < 10; i++){
		printf("\nPosição: %d\tValor: %d\n", i, v[i]);
	}
	printf("\n\n\nDigite o valor a procurar: ");
	scanf("%d", &num);
	ans = buscaBinaria(num, v, 0, 9);
	if(ans == -1)
		printf("Não encontrado\n");
	else
		printf("A posição do numero é: [%d]\n", ans);
}