import math

def f(x):
    return x**2 - 9

x0 = 0 #intervalo, x0 < x1
x1 = 5
pre = 10**(-10) #precisão

#calculo do erro
def erro(x0, x1):
    erroAbs = abs(x1-x0)
    erro = abs(erroAbs/x1)
    return erro

#verifica se há raiz no intervalo
def verRaiz(x0, x1):
    if(f(x0)*f(x1) <= 0):
        return True
    else:
        return False

def new(x0, x1):
	return (x0*f(x1) - x1*f(x0))/(f(x1) - f(x0))

def secante(x0,x1):

	if verRaiz(x0, x1):
		print('Precisão: {:.15f}'.format(pre))
		print('Intervalo: [{},{}]'.format(x0, x1))
		print('\nProcesso de Convergencia:\n')
		cont_it = 0
		
		while erro(x0, x1) > pre:
			xn = new(x0, x1)
			x0 = x1
			x1 = xn
			cont_it += 1

			print ('I{} = {:.15f}\t\tE = {:.15f}'.format(cont_it, xn, erro(x0, x1)))
			
			#verifica se o próprio ponto é a raíz
			if(f(x0) == 0):
				print ('\nQuantidade de iterações processadas: {}'.format(cont_it))
				print ('Raiz no ponto X = {}'.format(x0))
				return
			if(f(x1) == 0):
				print ('\nQuantidade de iterações processadas: {}'.format(cont_it))
				print ('Raiz no ponto X = {}'.format(x1))
				return

		print ('\nQuantidade de iterações processadas: {}'.format(cont_it))
		print ('Valores finais: X0 = {:.15f}, X1 = {:.15f}'.format(x0,x1))
	else:
		print ('Função não possui raíz no intervalo selecionado.')
		print ('Intervalo: [{},{}]'.format(x0, x1))
		return    

if(x0 >= x1):
	print ('Intervalo inválido.')
else:
	secante(x0, x1)