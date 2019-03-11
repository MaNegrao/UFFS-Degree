#include <stdio.h>

int main ()
{
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	if(n1>n2)
	printf("A ordem crescente é %d %d\n", n2,n1);
	else if(n2>n1)
	printf("A ordem crescente é %d %d\n", n1,n2);

return 0;
}
