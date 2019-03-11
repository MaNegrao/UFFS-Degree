#include <stdio.h>

int main (void){

	double s[10],sl;
	int i;
	printf("Digite os 10 salarios\n");
	for(i=0; i < 10; i++){
		scanf("%lf",&s[i]);
		if(s[i] > sl){
			sl=s[i];
		}
	}
	printf("Maior salario: R$: %.2lf\n",sl);
	for(i=9; i >= 0; i--)
		printf("Salario[%d]: R$: %.2lf\n", i+1,s[i]);

	return 0;
}