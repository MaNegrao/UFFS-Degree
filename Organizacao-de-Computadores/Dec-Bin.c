#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(void){
	int exp, aux;
	float n, nm;
	char ans[35] = "0 00000000 00000000000000000000000";
	
	printf("Digite o número a ser codificado: ");
	scanf("%f", &n); 
	nm = n;
	if(n != 0){
		if(n < 0){
			ans[0] = '1';
			n *= -1;
		}
		else
			ans[0] = '0';
		if(n >= 1){
			for(exp = 0 ; n >= 2; exp++){
				n /= 2;
			}
		}
		else if(n < 1){
			for(exp = 0 ; n < 1; exp--)
				n *= 2;
		}

		n --; exp += 127;

		for(aux = 9; exp > 0; aux--){
			int res = exp % 2;
			ans[aux] = res+'0';
			exp /= 2;
		}
		for(aux = 11; n != 0; aux++){
			n *= 2;
			if(n >= 1){
				ans[aux] = '1';
				n--;
			}
			else
				ans[aux] = '0';
		}
	}
	system("clear");
	printf("%f Em binario é:\n\n", nm);
	puts(ans);
}