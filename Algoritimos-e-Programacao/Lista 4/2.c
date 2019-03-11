#include <stdio.h>

int main ()
{
	int i=1,i2,i3,i4,nm,s;
	printf("Digite um número:\n");
	scanf("%d",&nm);
	for( i2 = 1; i2 <= nm; i2++){
		for( i3 = 1; i3 <= nm; i3++, i++){
			s=0;
			for(i4=1; i4 <= i; i4++){
		 		if(i%i4 == 0) s++;
			}
			printf( (s == 2) ? "#" : "_");	
		}
		printf("\n");
	}
	return 0; 
}