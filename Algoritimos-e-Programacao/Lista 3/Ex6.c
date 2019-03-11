#include <stdio.h>

int main (){
	int n,a=0;
		for(int i=1;;i++){
			printf("Digite um numero\n");
			scanf("%d",&n);
			if(n == 0) break;
			if(n>a) a=n;
		}
		printf("O maior é: %d\n",a);
	
	return 0;
}