#include <stdio.h>
#include <math.h>

int main (){
	int nm,s,raiz;
	printf("Digite Um Numero\n");
		scanf("%d",&nm); s=0;
			if( nm!=2 && nm%2 == 0 ) printf("Nao Primo\n"); 
			else{
				raiz = sqrt(nm);
				for( int i=1 ; i <= raiz ; i++)
					if(nm%i == 0) s++;		
				printf( (s == 1) ? "Primo\n" : "Nao Primo\n"); 	
				}

return 0;
}