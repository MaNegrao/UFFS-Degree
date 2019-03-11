#include <stdio.h>

int main (void){

	int i,n,a,s,j, cont=0;
	printf("Digite o tamanho da sequencia\n");
	scanf("%d",&n);
	int v[n];

	printf("Digite os numeros e veja se são uma sequencia balanceada\n");

	for(i=0; i < n; i++){
		scanf("%d",&v[i]);
	}
	for(i=0; i < n; i++){
		for(j=i+1; j < n; j++){
			if(v[i] > v[j]){
				a=v[i];
				v[i]=v[j];
				v[j]=a;
			}
		}
	}
	/*for(i=0; i < n; i++){
		printf("%d ", v[i]);
	}*/
	s = (v[0]+v[n-1]);
	for(i=0, j = n-1; i < (n/2), j >= (n/2); i++, j--){
		if(v[i]+v[j] != s){
			printf("A sequencia não é balanceada\n");
			break;
		}
		else cont++;
	}
	if (cont == (n/2))
		printf("A sequencia é balanceada\n");

	return 0;
}