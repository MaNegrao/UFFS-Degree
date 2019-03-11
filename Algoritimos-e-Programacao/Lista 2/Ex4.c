#include <stdio.h>

int main ()
{
	int i=1,i2=1;
	while(i2<=3){
		while(i<=10){
			printf("%d x %d = %d\n",i2,i,i2*i);			
			i++;
		}puts(" ");
		i=1;
		i2++;
	}
return 0;
}
