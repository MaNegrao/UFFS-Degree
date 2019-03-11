#include <stdio.h>

int main (void){
	
	int i,n;
	printf("Digite a quantidade de salarios\n");
	scanf("%d", &n);
	double s[n];
	printf("Digite o valor dos salarios\n");
	for(i=0; i < n; i++){
		scanf("%lf", &s[i]);
		if(s[i] < 1000)
			s[i]+=s[i]*0.1;
	}
	printf("Salarios atualizados\n");
	for(i=0; i < n; i++){
		printf("R$ %.2lf\n", s[i]);
	}
	return 0;
}