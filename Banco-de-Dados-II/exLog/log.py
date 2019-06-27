#Isabeli Rosana Reik        1611100015
#Matheus Dias Negrão        1711100026
def leArq():
	arquivo = open('teste01', 'r')
	arq = arquivo.readlines()
	arquivo.close()

	arq = [l.replace('<', '') for l in arq]
	arq = [l.replace('>', '') for l in arq]
	arq = [l.replace('|', '') for l in arq]
	arq = [l.replace('\n', '') for l in arq]
	    
	return arq

def dBanco():
	ban = arqLog[0]
	ban = ban.replace('=', ' ')
	ban = ban.split()
	for i in range(len(ban)):
		if ban[i].isdigit():
			ban[i] = int(ban[i])
	arqLog.pop(0)
	return ban

def tran(linha):
	linha = linha.replace('T', '')
	linha = linha.split(',')
	t = int(linha[0])-1
	flags[t] = 'T'
	var = str(linha[1])
	vAnt = int(linha[2])
	vNov = int(linha[3])
	return [var, vAnt, vNov], t

def redo(tra):
	for i in range(len(log[tra])):
		var = log[tra][i]
		if type(var) is str:
			posBan = banco.index(var)
			banco[posBan + 1] = log[tra][i+2]

def undo(tra):
	log[tra].reverse()
	while log[tra] != []:
		log[tra].pop(0)
	flags[tra] = 'U'

def ckpt():
	for i in range(len(flags)):
		if 'C' in flags[i]:
			flags[i] = 'UC'

def mostra():
	cont = 1
	print('Log de Transações Final:')
	for tran in log:
		print('T{}: {}' .format(cont, tran))
		cont +=1

	cont = 1
	print('\nSituação Final das Transações:')
	for flag in flags:
		print('T{}:' .format(cont), end='')
		if flag == 'C':
			print('Commited... \t\tRedo')
		elif flag == 'U':
			print('Aborted... \t\tUndo')
		elif flag == 'S':
			print("Started")
		elif flag == 'UC':
			print("Checkpoint...")
		cont +=1
	
	print('\nValores Finais Gravados no Banco:')
	for i in range(0, len(banco), 2):
		print('{} = {}' .format(banco[i], banco[i+1]))

def parser():
	for linha in arqLog:
		if 'start T' in linha:
			flags.append('S')
			log.append([])

		elif 'commit' in linha:
			idt = int(linha[-1])-1
			redo(idt)
			flags[idt] = 'C'
			print('Commit T{}' .format(linha[-1]))
			print('Redo T{}\n' .format(linha[-1]))	

		elif 'Start CKPT' in linha:
			print('START CKPT')
			if 'End CKPT' in arqLog:
				ckpt()
			print('')

		elif 'End CKPT' in linha:
			print('END CKPT\n')

		else:
			newTrans, t = tran(linha)
			log[t].extend(newTrans)

	for i in range(len(flags)):
			if 'T' in flags[i]:
				undo(i)
				print('Abort T{}'.format(i+1))	
				print('Undo T{}\n'.format(i+1))
	mostra()

log = []
flags = []
arqLog = leArq()
banco = dBanco()
parser()