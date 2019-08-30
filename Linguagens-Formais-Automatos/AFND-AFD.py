#Variaveis Globais

entrada = ''
#automatonarios
automato    = {} #  
automatoDet = {} # deterministico
automatoAux = {} #
listNTerm = []  # nao terminais
listTerm = [] # terminais
gramaticas = ''
tokens     = ''
#estados
estVisit = set()
estVisitOrd = [] # estado deterministico ordem
# Mortos
listMortos = set()
# Para enconctrar inalcançáveis
listAlcancaveis = set()
listVisitInalc = set()
conteudoArquivo = '' # conteudo que enviara para o arquivo

def insList(lista, vlr):                                             
	if str(lista).find(vlr) == -1:
		lista.append(vlr)

def decodificaEntrada():
	global entrada
	global listNTerm
	global gramaticas
	global tokens	
	linhas = entrada.split('\n')
	for linha in linhas:
		if linha.find('<') != -1: # Gramática
			aux     = linha.split('::=')
			esq     = aux[0]
			entrada = esq[1:len(esq)-1] # remove <>			1
			gramaticas = str(gramaticas)+str(linha)+'\n' 
			# Insere num vetor global
			insList(listNTerm, entrada)
		else:					  # Tokens
			tokens = str(tokens)+str(linha)+'\n'

def criaautomatoGramatica():
	global automato
	global gramaticas
	estTemp = []

	linhas = gramaticas.split('\n')
	indice = 0
	for linha in linhas:
		if linha != '':# se a linha não for vazia
			partes = linha.split('::=') # separa o nome da regra de suas produções
			estado = partes[0][1:len(partes[0])-1] # pega o estado
			if estado in estTemp: # estado repetido, concatena
				linhas[0] = str(linhas[0])+'|'+partes[1]
				linhas.remove(linhas[indice])
			estTemp.append(estado)
			indice += 1

	for linha in linhas:
		print(linha) #mostra cada linha da gramatica
		if linha != '': 
			partes = linha.split('::=') #faz a separação em partes
			estado = partes[0][1:len(partes[0])-1] #pega somente o estado da gramatica
			automato[estado] = criaProducoesGramatica(partes[1]) #chama a função de criar as produções para aquele estado
			
	print("Gramatica")
	print(automato, '\n')

def criaProducoesGramatica(producoes):
	regra = {}
	final = 0
	listTermTmp = set()
	producoes = producoes.split('|')
	for producao in producoes:
		if len(producao) == 1: # seja produção unitaria 
			if producao != 'ε': # se não for epsilon 
				insList(listTerm, producao) # chama funçao para inserir na lista de terminais
				if producao not in listTermTmp:
					regra[producao] = 'X' # estado de erro
				else:
					regra[producao] = str(str(regra[producao])+'X') # estado de erro
				listTermTmp.add(producao)
				automato['X'] = [1, {'':''}]
				insList(listNTerm, 'X') #insere estado de erro
			else: #epsilon
				final = 1 # estado sera final
		else: # terminal nao esta sozinho
			aux      = producao.split('<') #separação dos terminais e não terminais 
			terminal = aux[0] #pega o terminal de cada produção
			estado   = aux[1].replace('>', '') # pega e tira os > dos não terminais das produções
			listTermTmp.add(terminal) # coloca no listunto de terminais
			insList(listTerm, terminal)
			if str(regra).find(terminal) != -1: # encontrou
				regra[terminal] = str(regra[terminal])+str(estado)
			else:
				regra[terminal] = estado

	return [final, regra]

def criaProducoesToken():
	global listNTerm
	global tokens
	global automato
	
	linha = tokens.split("\n")	
	for i in linha:
		if i != '':	    # cada token
			cont = 0
			for j in i: # cada caractere do token
				if cont == 0: # primeiro caracterer do token
					if automato == {}: # caso o automato esteja vazio
						automato['S'] = [0, {j:''}]
						listNTerm.append('S')
					if j in automato['S'][1]: # se já tiver aquele token no automato 
						estadoFinal = ultimoEstado(j)
						automato['S'][1][j] = str(automato['S'][1][j])+str(estadoFinal)
					else: # caso padrão, o automato não está vazio e não tem nenhuma regra para aquele token
						estadoFinal = ultimoEstado(j)
						automato['S'][1][j] = estadoFinal
				else: # caso não seja o primeiro caractere, cria uma regra pra ele
					proximoEstado = listNTerm[len(listNTerm)-1]
					estadoFinal = ultimoEstado(j)
					automato[proximoEstado] = [0, {j:estadoFinal}]
					automato[proximoEstado][1][j] = listNTerm[len(listNTerm)-1]
				
				# valia de se o estado é final ou não, se for 
				if cont == len(i)-1: # ultima letra do token... gera um estado final
					automato[estadoFinal] = [1, {'':''}]

				cont += 1

def ultimoEstado(terminal):                                         #busca o ultimo estado para criar regras
	global listNTerm, listTerm
	if listNTerm[len(listNTerm)-1] == 'X':
		ultimaLetra = listNTerm[len(listNTerm)-2]
	else:
		ultimaLetra = listNTerm[len(listNTerm)-1]
	codLetra    = ord(ultimaLetra)
	if codLetra == 82: # para nao repetir o S
		codLetra += 1
	if len(listNTerm) == 1: # para criar A
		codLetra = 64
	novaLetra = chr(codLetra+1)	
	listNTerm.append(novaLetra)
	insList(listTerm, terminal)
	return novaLetra

def determiniza():
	global automato
	global automatoDet
	global listNTerm
	global listTerm
	global automatoAux
	global estVisit
	global estVisitOrd
	
	automatoAux = automato

	ordemDeterm = []
	ordemDetermX = set()
	insList(ordemDeterm, listNTerm[0])

	automatoDet[listNTerm[0]] = automato[listNTerm[0]] # automato de S

	while 1:
		if ordemDeterm == '' or ordemDeterm == []:
			return
		
		if ordemDeterm[0] not in estVisit:
			estVisitOrd.append(ordemDeterm[0])
		estVisit.add(ordemDeterm[0])		

		print("Estados visitados")
		print(estVisit)
		print(estVisitOrd , '\n')

		for terminal in listTerm:			
			if str(automatoAux[ordemDeterm[0]][1]).find(terminal) != -1: # este terminal existe neste estado
				if automatoAux[ordemDeterm[0]][1][terminal] not in ordemDetermX and automatoAux[ordemDeterm[0]][1][terminal] != '':
					ordemDeterm.append(automatoAux[ordemDeterm[0]][1][terminal])
				ordemDetermX.add(automatoAux[ordemDeterm[0]][1][terminal])	
	
		# passa o primeiro valor da lista de ordem (S) para determinizar a linha no automatoDet
		ordemDeterm.pop(0)

		if len(ordemDeterm) > 0 and ordemDeterm[0] not in estVisit:

			if len(ordemDeterm) > 0 and len(ordemDeterm[0]) > 1: #lista não esta vazia e há indeterminismo
				determinizaLinha(ordemDeterm[0])
			if ordemDeterm[0] != '':
				automatoDet[ordemDeterm[0]] = automatoAux[ordemDeterm[0]]

def determinizaLinha(estado):
	global listTerm
	global automatoAux
	flagFinal = 0
	regra = {}
	# concatena
	for a in listTerm: 
		regra[a] = ''

	for letra in estado:
		for terminal in listTerm: 
			# Verifica se concatenacao nao repete nenhuma letra
			if str(automatoAux[letra][1]).find(terminal) != -1:
				#  valida para não concatenar as mesmas letras
				if str(regra[terminal]).find(automatoAux[letra][1][terminal]) == -1: # não encontrou 
					regra[terminal] = str(regra[terminal])+str(automatoAux[letra][1][terminal])

		# Verifica se este estado eh final
		if automatoAux[letra][0] == 1:
			flagFinal = 1

	automatoAux[estado] = [flagFinal, regra]

def minimiza(): 
	global estVisitOrd
	# Mortos
	for estado in estVisitOrd:	
		eliMortos(estado)

def eliMortos(estado):
	global listTerm
	global automatoDet

	for terminal in listTerm:
		if str(automatoDet[estado][1]).find(terminal) != -1: # existe esse terminal em S
			aux = ''
			for producoes in automatoDet[estado][1][terminal]: # varre todas as producoes do estado S
				aux = str(aux)+str(producoes)
			producao = aux
			
			eliProdMortos(producao, 0) # funcao que busca epsilon somente nas producoes deste estado

def eliProdMortos(estado, qtd):
	global listTerm
	global listMortos
	global automatoDet
	qtd += 1
	for terminal in listTerm:
		if estado != '' and automatoDet[estado][0] == 0: # nao eh final			
			if str(automatoDet[estado][1]).find(terminal) != -1:
				if qtd < 20:
					eliProdMortos(automatoDet[estado][1][terminal], qtd)
				else: 
					# MORTO
					if automatoDet[estado][0] == 0: # nao eh final
						listMortos.add(estado) # primeiro estado do loop
					if automatoDet[automatoDet[estado][1][terminal]][0] == 0: # nao eh final
						listMortos.add(automatoDet[estado][1][terminal]) # segundo estado do loop

def printAFD(tipo, eMorto, automato, listNTerm, mensagem):
	global listTerm
	global conteudoArquivo

	automatoPrint = automato
	for i in listNTerm:
		for j in listTerm:
			if str(automatoPrint[i][1]).find(j) == -1 or automatoPrint[i][1][j] == '':
				automatoPrint[i][1][j] = '  X'

	matriz = str(mensagem)+'\n\n'
	matriz = str(matriz)+' |  δ\t'
	for i in listTerm:
		matriz = str(matriz)+' | '+i+'\t'
	matriz = str(matriz)+' |\n'
	matriz = str(matriz)+' ---------'
	for i in listTerm: 
		matriz = str(matriz)+'--------'
	matriz = str(matriz)+'\n'
		
	for i in listNTerm:
		if eMorto == 1 or (eMorto == 0 and i not in listMortos and tipo == 1):
			if automatoPrint[i][0] == 1:
				final = '*'
			else:
				final = ' '
			matriz = str(matriz)+' | '+final+i+'\t'

			for j in listTerm:
				matriz = str(matriz)+' | '+automatoPrint[i][1][j]+"\t"

			morto = ' | '
			if i in listMortos and tipo == 1: 
				morto = ' | Morto'

			matriz = str(matriz)+morto+'\n'

	print(matriz)

f = open('entrada.in', 'rb')
f.seek(0)
entrada = f.read().decode().replace(' ', '')

decodificaEntrada()
criaautomatoGramatica()
criaProducoesToken()
determiniza()
minimiza() 
printAFD(0, 1, automato, listNTerm, "\n\nautomatoômato Finito Não Determinístico")
printAFD(1, 0, automatoDet, estVisitOrd, "\n\nautomatoômato Finito Minimo Determinístico")