#include <stdio.h>

int main (){    
    int i,n,nm,ma=0,s=0;
    printf("Digite a quantidade de numeros a ser digitada:\n");
    scanf("%d",&nm);
    for( i = 1; i <= nm; i++){
    	scanf("%d",&n);
    	if(n > ma){ 
    		s=0; ma=n;
    	}if(n == ma) s++;
    }
    printf("O maior se repete %d vez(es)\n", s);
return 0;
}

