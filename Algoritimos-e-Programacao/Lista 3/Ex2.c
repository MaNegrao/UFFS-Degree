#include <stdio.h>

int main (){
	int n1,n2,s=0,i,a;
		printf("Digite dois numeros\n");
		scanf("%d %d",&n1,&n2);
			if(n2 > n1){
				printf("Limite inferior: %d\nLimite superior: %d\nPares: ",n1,n2);
				for(i=n1+1 ; i < n2 ; i++){
					if(i%2 == 0){
						printf("%d ",i); 
						s+=i;
					}
				}
				printf("\nSoma: %d\n",s);
			}
			else if(n1 > n2){
				printf("Limite inferior: %d\nLimite superior: %d\nPares: ",n2,n1);
				for(i=n2+1 ; i < n1 ; i++){
					if(i%2 == 0){ 
						printf("%d ",i);
						s+=i;
					}
				}
				printf("\nSoma: %d\n",s);
			}
	return 0;
}