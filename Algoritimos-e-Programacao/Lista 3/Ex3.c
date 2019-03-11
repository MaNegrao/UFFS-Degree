#include <stdio.h>

int main (){
	int n,s=0,i=0;
		while(printf("Digite um numero\n")){
			scanf("%d",&n);
				if(n<0) break;
			s+=n; i++;
		}
		printf("Soma: %d\nMedia: %.2lf\nTotal de numeros: %d\n",s,(double)s/i,i);

	return 0;
}