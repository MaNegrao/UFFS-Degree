#include <stdio.h>
#include <string.h>

int main (void){
	int i,j,f;
	char v[20];
	printf("Digite uma palavra e veja se é um palindromo\n");
	fgets(v, 20, stdin);
	f=(strlen(v))-2;

	for(i=0, j=f; i < f, j >=0; i++, j--){
		if(v[i] != v[j]){
			printf("Não é palindormo\n");
			break;
		}
		else if(v[f] == v[0]){
			printf("É palindromo\n");
			break;
		}

	}
	
	return 0;
}