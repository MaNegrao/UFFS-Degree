#include <stdio.h>
#include <math.h>

int main (){
	int a,n=1,i;
	double r;
		for(i=1;;i++){
			printf("Digite um numero\n");
			scanf("%d",&n);
				if(n <= 0) break;
			r = sqrt(n);
			a = r;
				if(a == r) printf("%d é quadrado perfeito\n\n", n);
				else printf("%d nao é quadrado perfeito\n\n", n);
		}	
	return 0;
}