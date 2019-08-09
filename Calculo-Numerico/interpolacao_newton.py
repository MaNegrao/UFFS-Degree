# -*- coding: utf-8 -*-

import math
import numpy as np

#----------------------------------------------------------------------
#FUNCÇÃO OPCIONAL PARA COMPARAR COM A INTERPOLAÇÃO
def f(x):
    return 0

#----------------------------------------------------------------------
#VARIÁVEIS
'''
Pontos baseados no exercicio 1a da lista 11
(fechou com as respostas do autor)
'''
pontos_x = [1, 11, 20, 28,36, 46, 50, 54, 56]
pontos_y = [10, 6, 8, 14, 16, 16, 21, 17, 11]

#LISTA PARA AS DIFERENÇAS DIVIDIDAS
DD = []
DD_temp = []

#----------------------------------------------------------------------
#LEITURA MANUAL DOS DADOS (OPCINAL)
'''
for x in pontos_x:
    pontos_y.append(f(x))    
qtd_pontos = input("Quantidade de pontos para interpolaï¿½ï¿½o: ")
for i in range(0,qtd_pontos):
    x = input("x{} = ".format(i))
    y = input("y{} = ".format(i))
    pontos_x.append(x)
    pontos_y.append(y)
'''

#----------------------------------------------------------------------
#GRAU MÁXIMO DE INTERPOLAÇÃO
print ("POLINOMIO INTERPOLADOR DE NEWTON \n")
print("Grau maximo de interpolação(1 <= int <= {}): ".format(len(pontos_x)-1))
grau = int(input(''))+1
print ("x: ", pontos_x)
print ("y: ", pontos_y)

#----------------------------------------------------------------------
#PONTO DE ANÁLISE
#input("Ponto de análise: ") #entrada manual (opcional)
x0 = -7

#----------------------------------------------------------------------
#PRIMEIRA DIFERENÇAS DIVIDIDAS
for i in range(1, len(pontos_x)):
    DD_temp.append((pontos_y[i]-pontos_y[i-1])/(pontos_x[i]-pontos_x[i-1]))
DD.append(DD_temp[0])

#----------------------------------------------------------------------
#RESTANTE DAS DIFERENÇAS DIVIDIDAS
g = 1
j = 0
while len(DD) < grau-1:

    for i in range(1, len(DD_temp)):
        DD_temp[j] = ((DD_temp[i]-DD_temp[i-1])/(pontos_x[i+g]-pontos_x[i-1]))
        j = j + 1 

    DD.append(DD_temp[0])
    DD_temp.pop()
    g = g + 1
    j = 0

#----------------------------------------------------------------------
#PRODUTÓRIO DOS TERMOS DE x
P = [] #lista de produções
produt = 1 #para o produtório

for i in range(0,len(DD)):
    for j in range(0, i+1):
        produt = produt * (x0 - pontos_x[j])
    P.append(produt)
    produt = 1
    
#----------------------------------------------------------------------
#MULTIPLICAÇÃO PELAS DIFERENÇAS DIVIDIDAS
for i in range(0, len(DD)):
    DD[i] = DD[i] * P[i]
    
#----------------------------------------------------------------------
#ADICIONANDO f(x0)
DD.append(pontos_y[0])

#----------------------------------------------------------------------
#SOMATÓRIO
n = sum(DD)

#----------------------------------------------------------------------
print('\nPolinomio:')
'''
Para graus menores que o grau máximo
a função polyfit retorna o polinomio mediano
entre todos os pontos.
(A FUNÇÃO POLYFIT ESTA SENDO USADA SOMENTE PARA MOSTRAR O POLINOMIO GENÉRICO)
'''
p  =  np.polyfit (pontos_x, pontos_y, grau-1)

casas_decimais = 15 #para os prints
j = (len(p)-1)
for i in range(0, len(p)):
    print (round(p[i],casas_decimais),'x^{}'.format(j))
    j -= 1

#print 'f({}) = {}'.format(x0, round(f(x0),casas_decimais)) #caso comparação com função real (OPCIONAL)
print ('\nP({}) = {}'.format(x0, round(n,casas_decimais)))
#print 'Erro Abs: {}'.format(round(math.fabs(f(x0) - P),casas_decimais)) #para saber o erro abs da função real (OPCIONAL)
 