'''
# -*- coding: utf-8 -*-
'''
import math
import numpy as np

#----------------------------------------------------------------------
#FUNCÇÃO OPCIONAL PARA COMPARAR COM A INTERPOLAÇÃO (OPCIONAL)
def f(x):
    return 4**x + math.cos(-x + (1/x)) + math.log(-x)

#----------------------------------------------------------------------
#LISTA DE PONTOS
'''
Pontos baseados no exercicio 6a da lista 10
(fechou com as respostas do autor)
'''
pontos_x = [-5.7,-5.8,-5.9,-6,-6.4,-6.8,-7.2,-7.6,-8,-8.4,-8.8,-9.2,-9.6,-10.0]
pontos_y = [2.46661956925426,2.55086290136597,2.62635511800892,2.69251508861534,2.85566074137102,2.84941874780725,2.68649802911606,2.40425343800739,2.05843998196245,1.71412506300573,1.43521992323121,1.27429533678208,1.26428812995407,1.413394894043]

#----------------------------------------------------------------------
#LEITURA MANUAL DOS DADOS (OPCINAL)
'''
#GERA Y EM FUNÇÃO DE X (OPCIONAL)
for x in pontos_x:
    pontos_y.append(f(x))    
#INSERE PONTOS MANUALMENTE (OPCIONAL)
qtd_pontos = input("Quantidade de pontos para interpolação: ")
for i in range(0,qtd_pontos):
    x = input("x{} = ".format(i))
    y = input("y{} = ".format(i))
    pontos_x.append(x)
    pontos_y.append(y)
    
'''

#----------------------------------------------------------------------
#GRAU MÁXIMO DE INTERPOLAÇÃO
print ("POLINOMIO INTERPOLADOR DE LAGRANGE \n")
print("Grau maximo de interpolação(1 <= int <= {}): ".format(len(pontos_x)-1))
grau = int(input(''))+1
print ("x: ", pontos_x)
print ("y: ", pontos_y)

#----------------------------------------------------------------------
#PONTO DE ANÁLISE
#x0 = input("Ponto de análise: ") #declaração manual (opcional)
x0 = -0.99
print ('x0 = {}'.format(x0))
#----------------------------------------------------------------------
#CÁLCULO DE Li
L = []
result = 1 #para o produtório
for i in range(0, grau): 
    print ('--------')
    for j in range(0, grau):
        if (i != j):
            print (x0,'-',pontos_x[j],'/',pontos_x[i],'-',pontos_x[j],'=',((x0 - pontos_x[j])/(pontos_x[i] - pontos_x[j])))
            result = result * ((x0 - pontos_x[j])/(pontos_x[i] - pontos_x[j]))
    L.append(result)
    result = 1

#----------------------------------------------------------------------
#Li * Yi
print ('\nL*y')
for i in range(0, grau):
    print ('--------')
    print (L[i],'*',pontos_y[i],'=',L[i]*pontos_y[i])
    L[i] = L[i]*pontos_y[i]

#----------------------------------------------------------------------
#SOMATÓRIO
P = sum(L)

#--------------------------------------------------------------------------
print('\nPolinomio:')
'''
Para graus menores que o grau máximo
a função polyfit retorna o polinomio mediano
entre todos os pontos.
'''
p  =  np.polyfit (pontos_x, pontos_y, grau-1)

casas_decimais = 5 #para os prints
j = (len(p)-1)
for i in range(0, len(p)):
    print (round(p[i],casas_decimais),'x^{}'.format(j))
    j -= 1

#print 'f({}) = {}'.format(x0, round(f(x0),casas_decimais)) #caso comparação com função real (OPCIONAL)
print ('\nP({}) = {}'.format(x0, round(P,casas_decimais)))
#print 'Erro Abs: {}'.format(round(math.fabs(f(x0) - P),casas_decimais)) #para saber o erro abs da função real (OPCIONAL)
