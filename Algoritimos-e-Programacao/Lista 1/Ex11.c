#include <stdio.h>

int main ()
{
	double Vc;
	scanf("%lf", &Vc);
	if(Vc<=20.00)
	printf("O valor de venda é R$ %.2lf\n", Vc*1.45);
	else
	printf("O Valor de venda é R$ %.2lf\n", Vc*1.30);

return 0;
}
