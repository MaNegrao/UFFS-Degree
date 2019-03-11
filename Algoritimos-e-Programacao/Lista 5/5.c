#include <stdio.h>
#include <string.h>

int main (void){
	
	int i,j,n,s,c=0,sc;
	char pa[100], pa1[100], pat[200];
	printf("Digite o número da função desejada:\n1- strlen\n2- strcpy\n3- memcpy\n4- strcat\n5- strcmp\n");
	scanf("%d", &sc);

	switch(sc){
		case 1:
			system("clear");
			printf("strlen - Calcula quantos caracteres uma string possui\nDigite a palavra e veja a quantidade de caracteres\n");
			__fpurge(stdin);
			fgets(pa, 100, stdin);
			for(i=0; pa[i] != '\0'; i++);
			printf("A string tem %d caracteres\n", i-1);
			break;

		case 2:
			system("clear");
			printf("strcpy - Copia de uma string para outra\nDigite uma palavra para ser copiada\n");
			__fpurge(stdin);
			fgets(pa, 100, stdin);
			for(i=0; i < 100; i++){
				pa1[i]=pa[i];
			}
			printf("A copia é: %s\n", pa1);
			break;

		case 3:
			system("clear");
			printf("memcpy - Copia os 'n' primeiros temos de uma string para outra\nDigite a palavra desejada\n");
			__fpurge(stdin);
			fgets(pa, 100, stdin);
			printf("Digite a quantidade de caracteres desejada para copiar\n");
			scanf("%d",&n);

			for(i=0; i < n; i++){
				pa1[i]=pa[i];
			}
			pa1[n] = 0;
			puts(pa1);
			break;

		case 4:
			system("clear");
			printf("strcat - Concatena duas strings\nDigite as palavras para serem concatenadas\n");
			__fpurge(stdin);
			fgets(pa, 100, stdin);
			__fpurge(stdin);
			fgets(pa1, 100, stdin);
			for(i=0; i < 200; i++){
				if(pa[i] == '\n'){
					break;
				}
				pat[i]=pa[i];
			}
			for(j=0 ; j < 100, i < 200; i++, j++){
				if(pa1[j] == '\n'){
					break;
				}
				pat[i]=pa1[j];
			}
			puts(pat);
			break;

		case 5:
			system("clear");
			printf("strcmp - Compara duas strings e diz se são iguais ou não\nDigite as palavras e veja se são iguais\n");
			__fpurge(stdin);
			fgets(pa, 100, stdin);
			__fpurge(stdin);
			fgets(pa1, 100, stdin);
			for(i=0 ; i < 100; i++){
				if(pa[i] != pa1[i]){
					printf("Não são iguais\n");
					break;
				}
				else if(pa[i] == '\n' && pa1[i] == '\n'){
					printf("São iguais\n");
					break;
				}
			}
			break;

		default:
			printf("Opção invalida\n");
			break;
	}
	return 0;
}