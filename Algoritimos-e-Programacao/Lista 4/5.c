#include <stdio.h>

int main ()
{
	int n1,n2,i2,p1=0,p2=0,a,s;
	printf("Digite um intervalo de numeros e veja os pares de primos entre eles:\n");
	scanf("%d %d", &n1, &n2);
	if(n1 > n2){
		a=n2; n2=n1; n1=a;
	}
	for (; n1 <= n2; n1++){
		s=0;
		for( i2 = 1; i2 <= n1; i2++)
			if(n1%i2 == 0) s++;

		if(s == 2)
			if(p1 == 0) p1 = n1;
			else p2 = n1;
			
		if(p1 != 0 && p2 !=0){
			if(p2 - p1 == 2)
				printf("%d %d\n", p1, p2);
			p1=0; p2=0;
		}
	}
	return 0;
}