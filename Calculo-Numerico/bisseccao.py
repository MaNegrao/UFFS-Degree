import math 

def f(x):
    return x**2 - 9 

x0 = 0 #intervalo, x0 < x1
x1 = 3
pre = 10**(-10) #precisão

#calculo do erro
def erro(x0, x1):
    erroAbs = abs(x1-x0)
    erro = abs(erroAbs/x1)
    return erro

#existencia da raíz no intervalo
def verificaRaiz(x0, x1):
    if(f(x0)*f(x1) <= 0):
        return True
    else:
        return False

#codigo principal
def bisseccao(x0, x1):
    
    if verificaRaiz(x0, x1):
        print ('Precisão: {:.15f}'.format(pre))
        print ('Intervalo: [{},{}]'.format(x0, x1))
        print ('\nProcesso de Convergencia:\n')
        cont_it = 0
        while erro(x0, x1) > pre:
            med = ((x1-x0)/2.0) + x0 #atualiza ponto médio
            cont_it += 1 #contador de iterações

            #verifica se o próprio ponto é a raíz
            if(f(x0) == 0):
                print ('\nQuantidade de iterações processadas: {}'.format(cont_it))
                print ('Raiz no ponto X = {}'.format(x0))
                return
            if(f(x1) == 0):
                print ('\nQuantidade de iterações processadas: {}'.format(cont_it))
                print ('Raiz no ponto X = {}'.format(x1))
                return

            #verifica raíz em um intervalo menor
            if verificaRaiz(x0, med):
                x1 = med
                print ('I{} = {:.15f}\t\tE = {:.15f}'.format(cont_it, med, erro(x0, x1)))
            else:
                verificaRaiz(med, x1)
                x0 = med
                print ('I{} = {:.15f}\t\tE = {:.15f}'.format(cont_it, med, erro(x0, x1)))

    else:
        print ('Função não possui raíz no intervalo selecionado.')
        print ('Intervalo: [{},{}]'.format(x0, x1))
        return

    #resultado final
    print ('\nQuantidade de iterações processadas: {}'.format(cont_it))
    print ('Valores finais: X0 = {:.15f}, X1 = {:.15f}'.format(x0,x1))    

if(x0 >= x1):
    print ('Intervalo inválido.')
else:
    bisseccao(x0, x1)