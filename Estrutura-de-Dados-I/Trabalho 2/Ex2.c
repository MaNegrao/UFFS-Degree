#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct{
	char nome[50];
	char endereco[100];
	int matricula;
}estudante;

int main(){
	int num, i;
	printf("Digite o tamanho do vetor de estudantes: ");
	scanf("%d", &num);
	estudante *p = (estudante *)calloc(num, sizeof(estudante));
	printf("Preencha o vetor de estudantes\n");
	if(p){
		for(i = 0; i < num; i++){
			__fpurge(stdin);
			system("clear");
			printf("Estudante Posição [%d]\n\n", i);
			printf("Nome: ");
			fgets((p+i)->nome, 50, stdin);
			printf("Endereço: ");
			fgets((p+i)->endereco, 100, stdin);
			printf("Matricula: ");
			scanf("%d", &(p+i)->matricula);
		}
	}
	if(p){
		system("clear");
		for(i = 0; i < num; i++){
			printf("Posição do Estudante: %d\n", i);
			printf("Nome: %s", (p+i)->nome);
			printf("Endereço: %s", (p+i)->endereco);
			printf("Matricula: %d\n\n", (p+i)->matricula);
		}	
	}
	free(p);
    return 0;
}