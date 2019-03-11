#include <stdio.h>

int main ()
{
	int a,i=1,i2=1;
		puts("Digite um numero:");
		scanf("%d",&a);
		
			while(i<=a){
				i2=1;
				while(i2<=a){
					printf("*");	
				i2++;
				}
				puts(" ");
				i++;
			}
		
return 0;
}

