import math 

def f(x): #função
	return x**2 - 9 

def d(x): #derivada
    return 2*x

x0 = 3 #ponto inicial
pre = 10**(-5) #precisão

#calculo do erro
def erro(x0, x1):
    erroAbs = abs(x1-x0)
    erro = abs(erroAbs/x1)
    return erro

def newton(x0):

    if(d(x0) == 0):
        print('Escolha outro ponto. f\'(x) = 0.')
        return

    print('Ponto inicial: {}'.format(x0))
    print('Precisão: {:.10f}'.format(pre))
    print('\nProcesso de Convergencia:\n')

    print('X0 = {:.10f}\tPonto inicial'.format(x0))
    p = x0-(f(x0)/d(x0))
    count_it = 1

    print('X{} = {:.10f}\tE = {:.10f}'.format(count_it, p, erro(x0, p)))
    while(erro(x0, p) > pre):
        x0 = p
        p = x0-(f(x0)/d(x0))
        count_it += 1
        print('X{} = {:.10f}\tE = {:.10f}'.format(count_it, p, erro(x0, p)))

    print ('\nPonto final: X{} = {:.10f}'.format(count_it, p))
    print ('Erro final: E = {:.10f}'.format(erro(x0, p)))

newton(x0)