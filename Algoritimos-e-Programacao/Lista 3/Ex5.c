#include <stdio.h>

int main (){
	int n,m,s=0;
		for(int i=1;;i++){
			printf("Digite um numero\n");
			scanf("%d",&n);
			if(n == 0) break;
				if(n%3 == 0){
					m++; s+=n;
				}
		}
		printf("A media é: %.2lf\n", (double)s/m);
	
	return 0;
}