#include <stdio.h>

int main ()
{
	int n1,n2,s,i,a;
	printf("Digite um intervalo de numeros e veja os primos entre eles:\n");
	scanf("%d %d", &n1, &n2);
	if(n1 > n2){
		a=n1; n1=n2; n2=a;
	}
	printf("Os números primos entre eles são:\n");
	for( ; n1 <= n2; n1++){
		s=0;
		for(i=1; i <= n1; i++){
			if(n1%i == 0)
				s++;
		}if(s == 2)
			printf("\n%d\n", n1);
	}
return 0;
}