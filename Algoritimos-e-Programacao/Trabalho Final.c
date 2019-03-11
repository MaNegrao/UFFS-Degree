#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>

//variavel global
int ctr=0;

//struct de horarios
typedef struct{
	char seg[20]; 
	char ter[20]; 
	char qua[20]; 
	char qui[20]; 
	char sex[20];
}horarioTurma;

//struct de alunos
typedef struct{
	char name[40], cpf[12];
	int turma, cod, mat, vrf1, vrf2, vrf3;
	double np1, np2, nf, np2f, np1f;
}cadastroAluno;

//struct de turmas
typedef struct{
	char ccr[30];
	int cod, fase;
	horarioTurma hor;
	cadastroAluno alu[30];
}cadastroTurma;

//função para tirar quebra de linha de uma string
void tiraQuebra(char ccr[]){
	ccr[strlen(ccr)-1] = '\0';
}

//função de verificação 1
void verifica1(int *rtn, cadastroAluno alu[]){
	system("clear");
	if(ctr == 0){
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ Nenhuma turma cadastrada...             ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		system("sleep 3");
		*rtn = 1;
	}
	else if(alu[0].cod == 0){
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ Nenhum aluno da turma cadastrado...     ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		system("sleep 3");
		*rtn = 1;
	}
	else if((alu[0].vrf1 == 0) || (alu[0].vrf2 == 0)){
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ Dados de NP1 e/ou NP2 incompletos...    ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		system("sleep 3");
		*rtn = 1;
	}
	else{
		*rtn = 0;
	}
}

//função de verificação 2
void verifica2(int *rtn, cadastroAluno alu[]){
	system("clear");
	if(ctr == 0){
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ Nenhuma turma cadastrada...             ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		system("sleep 3");
		*rtn = 1;
	}
	else if(alu[0].cod == 0){
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ Nenhum aluno da turma cadastrado...     ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		system("sleep 3");
		*rtn = 1;
	}
	else{
		*rtn = 0;	}
}

//função de verificação 3
void verifica3(int *rtn, cadastroAluno alu[]){
	system("clear");
	if(ctr == 0){
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ Nenhuma turma cadastrada...             ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		system("sleep 3");
		*rtn = 1;
	}
	else if(alu[0].cod == 0){
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ Nenhum aluno da turma cadastrado...     ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		system("sleep 3");
		*rtn = 1;
	}
	else if((alu[0].vrf1 == 0) && (alu[0].vrf2 == 0)){
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ Dados de NP1 e NP2 incompletos...       ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		system("sleep 3");
		*rtn = 1;
	}
	else{
		*rtn = 0;
	}
}

//função de ajuste de Layout 1
void ajusteLayout1(char c[], char c2[]){
	int i, num=0, cont=0;
	num = 48 - strlen(c);
	for(i = 0; i < 50; i++){
		if(c[i] == ' '){
			cont++; num++;
		}
	}
	if(cont == 1){
		num--;
	}
	for(i = 0; i < num; i++){
		c2[i] = ' ';
	}
	c2[num] = '\0';
}

//função de ajuste de Layout 2
void ajusteLayout2(char c[], char c2[]){
	int i, num=0, cont=0;
	num = 45 - strlen(c);
	for(i = 0; i < 50; i++){
		if(c[i] == ' '){
			cont++; num++;
		}
	}
	if(cont == 1){
		num--;
	}
	for(i = 0; i < num; i++){
		c2[i] = ' ';
	}
	c2[num] = '\0';
}

//função de ajuste de Layout 3
void ajusteLayout3(char c[], char c2[]){
	int i, num=0;
	num = 44 - strlen(c);
	for(i = 0; i < 50; i++){
		if(c[i] == ' '){
			num++;
		}
	}
	for(i = 0; i < num; i++){
		c2[i] = ' ';
	}
	c2[num] = '\0';
}

//função de ajuste de Layout 4
void ajusteLayout4(char c[], char c2[]){
	int i, num=0;
	num = 41 - strlen(c);
	for(i = 0; i < 50; i++){
		if(c[i] == ' '){
			num++;
		}
	}
	for(i = 0; i < num; i++){
		c2[i] = ' ';
	}
	c2[num] = '\0';
}

//função que salva os dias e horarios de aulas
void horarioAula(horarioTurma *h1){
	int dias, i;
	char dia[30];
	printf("\tDigite a quantidade de dias com aulas na semana: ");
	scanf("%d", &dias);
	while(dias > 5 || dias <= 0){
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ Opção inválida, digite novamente...     ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\t");
		scanf("%d", &dias);
	}
	for(i = 1; i <= dias; i++){
		printf("\tDigite os dia da aula e o horario: ");
		__fpurge(stdin);
		fgets(dia, 30, stdin);
		if((dia[2] == 'g') || (dia[2] == 'G')){
			printf("\t");
			fgets(h1->seg, 20, stdin);
			tiraQuebra(h1->seg);
		}
		else if((dia[2] == 'r') || (dia[2] == 'R')){
			printf("\t");
			fgets(h1->ter, 20, stdin);
			tiraQuebra(h1->ter);
		}
		else if((dia[2] == 'a') || (dia[2] == 'A')){
			printf("\t");
			fgets(h1->qua, 20, stdin);
			tiraQuebra(h1->qua);
		}
		else if((dia[2] == 'i') || (dia[2] == 'I')){
			printf("\t");
			fgets(h1->qui, 20, stdin);
			tiraQuebra(h1->qui);
		}
		else if((dia[2] == 'x') || (dia[2] == 'X')){
			printf("\t");
			fgets(h1->sex, 20, stdin);
			tiraQuebra(h1->sex);
		}
		else{
			printf("\tDia não letivo, por favor, tente novamente...\n");
			i--;
		}
	}
}

//função de validação de cpf
void validarCPF(int *rt, char cpf[]){
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11){
        *rt = 0; return;
    }
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || 
    		(strcmp(cpf,"22222222222") == 0) || (strcmp(cpf,"33333333333") == 0) || 
    		(strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || 
            (strcmp(cpf,"88888888888") == 0) || (strcmp(cpf,"99999999999") == 0)){
    	*rt = 0; return;
    }
    else{
    	for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--){
        	digito1 += (cpf[i]-48) * j;
        }
        digito1 %= 11;
        if(digito1 < 2){
        	digito1 = 0;
        }
       	else{
            digito1 = 11 - digito1;
        }
        if((cpf[9]-48) != digito1){
            *rt = 0; return;
        }
        else{
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--){
            	digito2 += (cpf[i]-48) * j;
            }
        	digito2 %= 11;
       		if(digito2 < 2){
        		digito2 = 0;
        	}
       		else{
        		digito2 = 11 - digito2;
        	}
        	if((cpf[10]-48) != digito2){
        		*rt = 0; return;
        	}
    	}
	}
    *rt = 1; return;
}

//função de menu de escolha de turmas para o usuario
void opcaoTurmas( int *opc, cadastroTurma tur[]){
	int i;
	char c[50];
	if(ctr == 0){
		return;
	}
	system("clear");
	printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t┃ \e[1m%s            ♨  Portal do Professor ♨             %s\e[21m ┃\n",__DATE__,__TIME__);
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t┃                       Digite a turma desejada:                       ┃\n");
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	for(i = 0; i < ctr; i++){
		ajusteLayout1(tur[i].ccr, c);
		printf("\t\t┃ %d ─ Codigo: %d CCR: \e[1m%s\e[21m%s┃\n", i+1, tur[i].cod, tur[i].ccr, c);
		if(i != ctr-1){
			printf("\t\t┠──────────────────────────────────────────────────────────────────────┨\n");
		}
	}
	printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	scanf("%d", &*opc);
}

//função de cadastro de turmas
void cadastrarTurma(cadastroTurma tur[]){
	int contCod=201;
	system("clear");
	printf("\tDigite o compontente curricular ministrado na turma: ");
	__fpurge(stdin);
	fgets(tur[ctr].ccr, 40, stdin);
	tiraQuebra(tur[ctr].ccr);
	printf("\tDigite a fase da turma: ");
	scanf("%d", &tur[ctr].fase);
	horarioAula(&tur[ctr].hor);
	tur[ctr].cod = contCod+ctr;
	printf("\tCodigo gerado para turma: %d\n", tur[ctr].cod);
	system("sleep 3");
	ctr++;
}

//função de cadastro de alunos
void cadastrarAluno( int tur, int opc, cadastroAluno alu[]){
	int ch;
	if(ctr == 0){
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ Nenhuma turma cadastrada...             ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		system("sleep 3");
		return;
	}
	if(alu[0].cod != 0){
		system("clear");
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ \e[1m%s            ♨  Portal do Professor ♨             %s\e[21m ┃\n",__DATE__,__TIME__);
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃             Alunos já cadsatrados - Deseja Sobrescrever?             ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃                          1 ─ Sim  0 ─ Não                            ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		scanf("%d", &ch);
		if(ch == 0){
			return;
		}
	}

	int calu=20001+(1000*opc), i, vl;
	for(i=0; i < 30; i++, calu++){
		system("clear");
		printf("\tDigite os dados do aluno\n\tNome: ");
		__fpurge(stdin);
		fgets(alu[i].name, 40, stdin);
		tiraQuebra(alu[i].name);
		printf("\tMatricula: ");
		scanf("%d", &alu[i].mat);
		printf("\tDigite o CPF (Apenas Números)\n\t");
		do{
			__fpurge(stdin);
			fgets(alu[i].cpf, 12, stdin);
			validarCPF(&vl, alu[i].cpf);
			printf((vl == 0) ? "\tCPF inválido, tente novamente...\n\t" : "\tCPF validado com sucesso\n");
		}while(vl == 0);
		tiraQuebra(alu[i].cpf);
		alu[i].cod = calu;
		printf("\tCodigo gerado para o aluno: %d\n", calu);
		alu[i].turma = tur;
		system("sleep 3");
	}
}

//função de cadastro de notas
void cadastrarNotas(cadastroAluno alu[]){
	int ver2, np, i;
	double peso;
	verifica2(&ver2, alu);
	if(ver2 == 1){
		return;
	}
	system("clear");
	printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t┃ \e[1m%s            ♨  Portal do Professor ♨             %s\e[21m ┃\n",__DATE__,__TIME__);
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t┃                        Digite a opcão desejada:                      ┃\n");
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t┃ 1 ─ NP1 ─ ");
	printf((alu[0].vrf1 == 1) ? "Notas já cadastradas ─ Sobrescrever ?                      ┃\n" : "Disponivel para cadastro                                   ┃\n");
	printf("\t\t┃ 2 ─ NP2 ─ ");
	printf((alu[0].vrf2 == 1) ? "Notas já cadastradas ─ Sobrescrever ?                      ┃\n" : "Disponivel para cadastro                                   ┃\n");
	printf("\t\t┃ 0 - Voltar para menu principal                                       ┃\n");
	printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	scanf("%d", &np);
	if(np == 0){
		return;
	}
	else if(np == 1){
		printf("\tDigite a porcentagem da NP1 na média final: ");
		scanf("%lf", &peso);
		peso = peso/100;
		for(i = 0; i < 30; i++){
			printf("\tAluno: %s\n\tNP1: ", alu[i].name);
			scanf("%lf", &alu[i].np1);
			if(alu[i].np1 > 10.0){
				alu[i].np1 = alu[i].np1f = 10.0;
			}
			alu[i].np1f = alu[i].np1*peso;
			alu[i].vrf1++;
		}
	}
	else if(np == 2){
		printf("\tDigite a porcentagem da NP2 na média final: ");
		scanf("%lf", &peso);
		peso = peso/100;
		for(i = 0; i < 30; i++){
			printf("\tAluno: %s\n\tNP2: ", alu[i].name);
			scanf("%lf", &alu[i].np2);
			if(alu[i].np2 > 10.0){
				alu[i].np2 = alu[i].np2f = 10.0;
			}
			alu[i].np2f = alu[i].np2*peso;
			alu[i].vrf2++;
		}
	}
	else{
		printf("\tOpcão invalida...\n");
		return;
	}
}

//função de calculo de Medias Finais
void calculaMedias(int cod, cadastroAluno alu[]){
	int i, ver3;
	verifica1(&ver3, alu);
	if(ver3 == 1){
		return;
	}
	system("clear");
	printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t┃ \e[1m%s            ♨  Portal do Professor ♨             %s\e[21m ┃\n",__DATE__,__TIME__);
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t┃                      Calculado Médias... Tur. %d:                   ┃\n", cod);
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	for(i = 0; i < 30; i++){
		alu[i].vrf3 = 1;
		alu[i].nf = alu[i].np1f + alu[i].np2f;
		if(alu[i].nf >= 10.00){
			alu[i].nf = 10.00;
			printf("\t\t┃ Cod. Aluno: %d                                  Media Final: 10.0 ┃\n", alu[i].cod);
		}
		else{ 
			printf("\t\t┃ Cod. Aluno: %d                                   Media Final: %.1lf ┃\n", alu[i].cod, alu[i].nf);
		}
		if(i != 2){
			printf("\t\t┠──────────────────────────────────────────────────────────────────────┨\n");
			system("sleep 1");
		}
	}
	printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	system("sleep 7");
}

//função de listagem de alunos de uma determinada turma
void ListaAlunos(int cod, cadastroAluno alu[]){
	int i, ver1;
	verifica2(&ver1, alu);
	if(ver1 == 1){
		return;
	}
	char c[50];
	system("clear");
	printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t┃ \e[1m%s            ♨  Portal do Professor ♨             %s\e[21m ┃\n",__DATE__,__TIME__);
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t┃                           Alunos da Turma %d:                       ┃\n", cod);
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	for(i = 0; i < 30; i++){
		ajusteLayout3(alu[i].name, c);
		printf("\t\t┃ Aluno: \e[1m%s\e[21m%s CPF: \e[1m%s\e[21m ┃\n", alu[i].name, c, alu[i].cpf);
	printf("\t\t┃ Codigo: %d                                  Matricula: %d ┃\n", alu[i].cod, alu[i].mat);
		if(i != 2){
			printf("\t\t┠──────────────────────────────────────────────────────────────────────┨\n");
		}
	}
	printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	system("sleep 10");
}

//função de exibição de horarios dentro da exbição de uma turma
void exibeHorario(horarioTurma h1[]){
	if((h1->seg[0] == '0') || (h1->seg[0] == '1') || (h1->seg[0] == '2')){
		printf("\t\t┃           Segunda-feira ─ %s                             ┃\n", h1->seg);	
	}
	if((h1->ter[0] == '0') || (h1->ter[0] == '1') || (h1->ter[0] == '2')){
		printf("\t\t┃           Terça-feira ─ %s                               ┃\n", h1->ter);	
	}
	if((h1->qua[0] == '0') || (h1->qua[0] == '1') || (h1->qua[0] == '2')){
		printf("\t\t┃           Quarta-feira ─ %s                              ┃\n", h1->qua);	
	}
	if((h1->qui[0] == '0') || (h1->qui[0] == '1') || (h1->qui[0] == '2')){
		printf("\t\t┃           Quinta-feira ─ %s                              ┃\n", h1->qui);	
	}
	if((h1->sex[0] == '0') || (h1->sex[0] == '1') || (h1->sex[0] == '2')){
		printf("\t\t┃           Sexta-feira ─ %s                               ┃\n", h1->sex);	
	}
}

//função de exibição de turma
void exibeTurma(int ctl, cadastroTurma tur[]){
	if(ctr == 0){
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ Nenhuma turma cadastrada...             ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		system("sleep 3");
		return;
	}
	char c[50];
	system("clear");
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ \e[1m%s            ♨  Portal do Professor ♨             %s\e[21m ┃\n",__DATE__,__TIME__);
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃                           Dados da Turma %d:                        ┃\n", tur[ctl].cod);
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		ajusteLayout2(tur[ctl].ccr, c);
		printf("\t\t┃ Compontente Curricular: \e[1m%s\e[21m%s┃\n", tur[ctl].ccr, c);
		printf("\t\t┃ Codigo da turma: %d                                         %dª Fase ┃\n", tur[ctl].cod, tur[ctl].fase);
		printf("\t\t┠──────────────────────────────────────────────────────────────────────┨\n");
		printf("\t\t┃ Horarios:                                                            ┃\n");
		exibeHorario(&tur[ctl].hor);
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		system("sleep 6");
}

//função de exibição de notas parciais
void exibeNotas_par(int cod, cadastroAluno alu[]){
	int i, ver;
	verifica3(&ver, alu);
	if(ver == 1){
		return;
	}
	system("clear");
	printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t┃ \e[1m%s            ♨  Portal do Professor ♨             %s\e[21m ┃\n",__DATE__,__TIME__);
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t┃                       Notas parciais da turma %d:                   ┃\n", cod);
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	for(i = 0; i < 30; i++){
		if(alu[i].np1 == 10.0 && alu[i].np2 < 10.0){
			printf("\t\t┃ Cod. Aluno: %d                                 NP1: 10.0 NP2: %.1lf ┃\n", alu[i].cod, alu[i].np2);
		}
		else if(alu[i].np1 == 10.0 && alu[i].np2 == 10.0){
			printf("\t\t┃ Cod. Aluno: %d                                NP1: 10.0 NP2: 10.0 ┃\n", alu[i].cod);
		}
		else if(alu[i].np2 == 10.0 && alu[i].np1 < 10.0){
			printf("\t\t┃ Cod. Aluno: %d                                 NP1: %.1lf NP2: 10.0 ┃\n", alu[i].cod, alu[i].np1);
		}
		else{
			printf("\t\t┃ Cod. Aluno: %d                                  NP1: %.1lf NP2: %.1lf ┃\n", alu[i].cod, alu[i].np1, alu[i].np2);
		}
		if(i != 2){
			printf("\t\t┠──────────────────────────────────────────────────────────────────────┨\n");
		}
	}
	printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	system("sleep 10");
}

//função de exibição de notas finais
void exibeNotas_fin(int cod, cadastroAluno alu[]){
	int i, ver2;
	verifica1(&ver2, alu);
	if(ver2 == 1){
		return;
	}
	system("clear");
	printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t┃ \e[1m%s            ♨  Portal do Professor ♨             %s\e[21m ┃\n",__DATE__,__TIME__);
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t┃                        Notas finais da turma %d:                    ┃\n", cod);
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	for(i = 0; i < 30; i++){
		if(alu[i].np1 == 10.0 && alu[i].np2 < 10.0){
			printf("\t\t┃ Cod. Aluno: %d                                 NP1: 10.0 NP2: %.1lf ┃\n", alu[i].cod, alu[i].np2);
			printf("\t\t┃                                                     Media Final: %.1lf ┃\n", alu[i].nf);
		}
		else if(alu[i].np1 == 10.0 && alu[i].np2 == 10.0){
			printf("\t\t┃ Cod. Aluno: %d                                NP1: 10.0 NP2: 10.0 ┃\n", alu[i].cod);
			printf("\t\t┃                                                    Media Final: 10.0 ┃\n");
		}
		else if(alu[i].np2 == 10.0 && alu[i].np1 < 10.0){
			printf("\t\t┃ Cod. Aluno: %d                                 NP1: %.1lf NP2: 10.0 ┃\n", alu[i].cod, alu[i].np1);
			printf("\t\t┃                                                    Media Final:  %.1lf ┃\n", alu[i].nf);
		}
		else{
			printf("\t\t┃ Cod. Aluno: %d                                  NP1: %.1lf NP2: %.1lf ┃\n", alu[i].cod, alu[i].np1, alu[i].np2);
			printf("\t\t┃                                                     Media Final: %.1lf ┃\n", alu[i].nf);
		}
		if(i != 2){
			printf("\t\t┣┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┫\n");
		}
	}
	printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	system("sleep 10");
}

//função de encerramento de diario
void encerrar(int cod, cadastroAluno alu[]){
	int i, ver1;
	char c[50];
	verifica1(&ver1, alu);
	if(ver1 == 1){
		return;
	}
	if(alu[0].vrf3 != 1){
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ Médias não calculadas...                ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		system("sleep 3");
		return;
	}
	system("clear");
	printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t\t┃ \e[1m%s            ♨  Portal do Professor ♨             %s\e[21m ┃\n",__DATE__,__TIME__);
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t┃                       Diario final da turma %d:                     ┃\n", cod);
	printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	for(i = 0; i < 30; i++){
		ajusteLayout4(alu[i].name, c);
		if(alu[i].np1 == 10.0 && alu[i].np2 < 10.0){
			printf("\t\t┃ Aluno: \e[1m%s\e[21m%s NP1: 10.0 NP2: %.1lf ┃\n", alu[i].name, c, alu[i].np2);
			printf((alu[i].nf >= 6.0) ? "\t\t┃ \e[92m\e[1mAPROVADO!\e[21m\e[39m                                           Media Final: %.1lf ┃\n" : "\t\t┃ \e[91m\e[1mREPROVADO!\e[21m\e[39m                                          Media Final: %.1lf ┃\n", alu[i].nf);
		}
		else if(alu[i].np1 == 10.0 && alu[i].np2 == 10.0){
			printf("\t\t┃ Aluno: \e[1m%s\e[21m%sNP1: 10.0 NP2: 10.0 ┃\n", alu[i].name, c);
			printf("\t\t┃ \e[92m\e[1mAPROVADO!\e[21m\e[39m                                          Media Final: 10.0 ┃\n");
		}
		else if(alu[i].np2 == 10.0 && alu[i].np1 < 10.0){
			printf("\t\t┃ Aluno: \e[1m%s\e[21m%s NP1: %.1lf NP2: 10.0 ┃\n", alu[i].name, c, alu[i].np1);
			printf((alu[i].nf >= 6.0) ? "\t\t┃ \e[92m\e[1mAPROVADO!\e[21m\e[39m                                           Media Final: %.1lf ┃\n" : "\t\t┃ \e[91m\e[1mREPROVADO!\e[21m\e[39m                                          Media Final: %.1lf ┃\n", alu[i].nf);
		}
		else{
			printf("\t\t┃ Aluno: \e[1m%s\e[21m%s  NP1: %.1lf NP2: %.1lf ┃\n", alu[i].name, c, alu[i].np1, alu[i].np2);
			printf((alu[i].nf >= 6.0) ? "\t\t┃ \e[92m\e[1mAPROVADO!\e[21m\e[39m                                           Media Final: %.1lf ┃\n" : "\t\t┃ \e[91m\e[1mREPROVADO!\e[21m\e[39m                                          Media Final: %.1lf ┃\n", alu[i].nf);
		}
		if(i != 2){
			printf("\t\t┣┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┅┫\n");
		}
	}
	printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	system("sleep 11");
}

//função de exibição do menu principal
void menu(void){
		system("clear");
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃ \e[1m%s            ♨  Portal do Professor ♨             %s\e[21m ┃\n",__DATE__,__TIME__);
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➊ ─ Cadastrar turma.              ┃ ➏ ─ Exibir dados da turma.       ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➋ ─ Cadastrar alunos.             ┃ ➐ ─ Exibir notas parciais.       ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➌ ─ Inserir notas de uma turma.   ┃ ➑ ─ Exibir notas finais.         ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➍ ─ Calcular medias finais.       ┃ ➒ ─ Encerrar Diario.             ┃\n");
		printf("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\t\t┃ ➎ ─ Listar alunos da turma.       ┃ ➓ ─ Fechar Programa.             ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\t\t\t");
}

//função principal
void main(void){
	int op, opc, ctl;
	cadastroTurma tur[10];
	do{
		menu();		
		scanf("%d", &op);
		switch(op){

			case 1:
				cadastrarTurma(tur);
				break;
			case 2:
				opcaoTurmas(&opc, tur);
				ctl=opc-1;
				cadastrarAluno(tur[ctl].cod, opc, tur[ctl].alu);
				break;
			case 3:
				opcaoTurmas(&opc, tur);
				ctl=opc-1;
				cadastrarNotas(tur[ctl].alu);
				break;
			case 4:
				opcaoTurmas(&opc, tur);
				ctl=opc-1;
				calculaMedias(tur[ctl].cod, tur[ctl].alu);
				break;
			case 5:
				opcaoTurmas(&opc, tur);
				ctl=opc-1;
				ListaAlunos(tur[ctl].cod, tur[ctl].alu);
				break;
			case 6:
				opcaoTurmas(&opc, tur);
				ctl=opc-1;
				exibeTurma(ctl, tur);
				break;
			case 7:
				opcaoTurmas(&opc, tur);
				ctl=opc-1;
				exibeNotas_par(tur[ctl].cod, tur[ctl].alu);
				break;
			case 8:
				opcaoTurmas(&opc, tur);
				ctl=opc-1;
				exibeNotas_fin(tur[ctl].cod, tur[ctl].alu);
				break;
			case 9:
				opcaoTurmas(&opc, tur);
				ctl=opc-1;
				encerrar(tur[ctl].cod, tur[ctl].alu);
				break;
			case 10:
				printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("\t\t┃ Saindo...                               ┃\n"); 
				printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
				break;
			default:
				printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("\t\t┃ Opção invalida, tente novamente...      ┃\n");
				printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
				system("sleep 3");
				break;
		}	
	}while(op != 10);
}