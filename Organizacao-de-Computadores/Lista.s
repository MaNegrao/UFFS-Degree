@Cleisson Raimundi
@Matheus Dias Negrão
@Otavio Secco


@ Lista Simples em Assembly para o simulador armsim

	.global _start      @ ROTULO NECESSARIO PARA O LIGADOR
_start:

	/* opções */
	mov 	r8, #0
	str 	r8, buf		@zera o buffer

	mov     r0, #1		@mov para 1, stdout
	ldr     r1, =menu	@carrega em r1 o 
	ldr     r2, =tamM
	mov     r7, #4
	svc     0x55

	mov     r0, #0
	ldr     r1, =buf	@compara os valores com
	mov     r2, #4		@as opções abaixo
	mov     r7, #3
	svc     0x55

	ldr 	r9, buf
	cmp		r9, #49		@1 em ascii
	beq		_inserir
	cmp 	r9, #50		@2 em ascii
	beq		_remover
	cmp		r9, #51		@3 em ascii
	beq		_mostrar
	cmp		r9, #48		@0 em ascii
	beq		_exit

	b		_start

_inserir:
	ldr		r5, =prod

_insere:
	
	ldr		r1, [r5]
	cmp		r1, #0
	addne	r5, #58
	bne		_insere

	mov     r0, #1
	ldr     r1, =digC
	ldr     r2, =tamC		@printf
	mov     r7, #4
	svc     0x55

	mov     r0, #0
	mov		r1, r5	
	mov     r2, #4			@scanf
	mov     r7, #3
	svc     0x55

	mov		r0, #1
	ldr     r1, =digP
	ldr     r2, =tamP
	mov     r7, #4
	svc     0x55

	mov 	r0, #0
	mov		r1, r5
	add		r1, #4
	mov     r2, #4
	mov 	r7, #3
	svc     0x55

	mov     r0, #1
	ldr     r1, =digN
	ldr     r2, =tamN
	mov     r7, #4
	svc     0x55

	mov 	r0, #0
	mov		r1, r5
	add		r1, #8
	mov 	r2, #50
	mov 	r7, #3
	svc     0x55

	mov     r0, #1
	ldr     r1, =lido
	ldr     r2, =tamL
	mov     r7, #4
	svc     0x55

	b	_start	    @ volta para o menu


_remover:
	str 	r8, buf
	ldr		r5, =prod
	mov		r10, #0

	mov     r0, #1
	ldr     r1, =rem
	ldr     r2, =tamR
	mov     r7, #4
	svc     0x55

	mov		r0, #0
	ldr		r1,	=buf
	mov		r2, #4
	mov		r7, #3
	svc 	0x55
	ldr		r6, buf

_remove:
	add 	r10, #1
	cmp 	r10, #25
	beq		_start

	ldr		r1, [r5]
	cmp		r6, r1
	addne 	r5, #58
	bne		_remove

	mov		r10, #0
	mov 	r11, #0
	str 	r11, [r5]
	add     r5, #2

_zerar:
	add 	r10, #1
	cmp 	r10, #14
	beq	    _start
	str 	r11, [r5]
	b 		_zerar

_mostrar:
	ldr		r5, =prod
	mov		r10, #0

_mostra:

	add 	r10, #1
	cmp 	r10, #25
	beq 	_start

	ldr     r1, [r5]
	cmp		r1, #0
	addeq   r5, #58
	beq		_mostra

	mov     r0, #1
	mov		r1, r5
	mov		r2, #4
	mov     r7, #4
	svc     0x55

	mov		r0, #1
	mov 	r1, r5
	add 	r1, #4
	mov 	r2, #4
	mov 	r7, #4
	svc     0x55
	
	mov 	r0, #1
	mov 	r1, r5
	add 	r1, #8
	mov 	r2, #50
	mov 	r7, #4
	svc     0x55

	mov 	r0, #1
	ldr 	r1, =quebra
	ldr 	r2, =tamQ
	mov 	r7, #4
	svc     0x55

	add 	r5, #58

	b       _mostra

_exit:
	mov     r0, #1
	ldr		r1, =sair
	ldr		r2, =tamS
	mov     r7, #4
	mov		r7, #5
	svc     0x55


menu:
	.ascii   "\n\tLista Simples Assembly\n\n\t1 - Inserir\n\t2 - Remover\n\t3 - Mostrar\n\t0 - Sair\n"
tamM = . - menu

lido:
	.ascii "\nDados lidos com sucesso\n"
tamL = . - lido

digC:
	.ascii "\nDigite o Codigo:\n"
tamC = . - digC

digN:
	.ascii "\nDigite o Nome:\n"
tamN = . - digN

digP:
	.ascii "\nDigite o Preco:\n"
tamP = . - digP

sair:
	.ascii "\nSaindo...\n"
tamS = . - sair

quebra:
	.ascii "\n\n\n"
tamQ = . - quebra

rem:
	.ascii "\nDigite o codigo do qual quer remover\n"
tamR = . - rem

buf:
	.skip	4

prod:
	.skip	1450 
