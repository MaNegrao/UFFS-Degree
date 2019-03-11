#include <stdio.h>

int main ()
{
	double Sa, Pr;
	scanf("%lf %lf", &Sa, &Pr);
	if(Pr<(0.3*Sa))
	printf("O emprestimo pode ser concedido\n");
	else printf("O emprestimo não pode ser concedido\n");	

return 0;
}
