import numpy as np

ITERATION_LIMIT = 1000

#matriz de coeficientes
A = np.array([[5, 1, 1],
            [3, 4, 1],
            [3, 3, 8]])
'''A = np.array([[4, 1, -1, 0, 0, 0, 0, 0],
            [1, 6, -2, 1, -1, 0, 0, 0],
            [0, 1, 5, 0, -1, 0, 0, 0],
            [0, 2, 0, 5, -1, 1, -1, -1],
            [0, 0, -1, -1, 6, 0, 0, -1],
            [0, 0, -1, 0, -1, -1, 0, 0],
            [0, 0, 0, -1, 0, 5, 4, -1],
            [0, 0, 0, -1, -1, 0, -1, 5]])
'''
#vetor b 
#b = np.array([-6, -5, 0, 1, 2, -12, -2, 8])
b = np.array([1,2,3])

#imprime sistema formatado
print("SISTEMA:")
for i in range(A.shape[0]):
    row = ["{}x{}".format(A[i, j], j + 1) for j in range(A.shape[1])]
    print(" + ".join(row), "=", b[i])
print('n')

x = np.zeros_like(b)
for it_count in range(ITERATION_LIMIT):
    print("SOLUCAO CORRENTE:", x)
    x_new = np.zeros_like(x)

    for i in range(A.shape[0]):
        s1 = np.dot(A[i, :i], x[:i])
        s2 = np.dot(A[i, i + 1:], x[i + 1:])
        x_new[i] = (b[i] - s1 - s2) / A[i, i]

    if np.allclose(x, x_new, atol=1e-5, rtol=0.):
        break

    x = x_new

print("SOLUÇÃO:")
print(x)

error = np.dot(A, x) - b
print("ERRO:")
print(error)