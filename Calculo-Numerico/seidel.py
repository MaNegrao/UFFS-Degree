import numpy as np

limit_it = 10000

# matriz dos coeficientes

'''
A = np.array([[4, 1, -1, 0, 0, 0, 0, 0],
            [1, 6, -2, 1, -1, 0, 0, 0],
            [0, 1, 5, 0, -1, 0, 0, 0],
            [0, 2, 0, 5, -1, 1, -1, -1],
            [0, 0, -1, -1, 6, 0, 0, -1],
            [0, 0, -1, 0, -1, -1, 0, 0],
            [0, 0, 0, -1, 0, 5, 4, -1],
            [0, 0, 0, -1, -1, 0, -1, 5]])
'''
A = np.array([[3, 0, 1],
            [1, -1, 0],
            [3, 1, 8]])

b = np.array([1,2,3])

'''
b = np.array([6., 25., -11., 15.])
b = np.array([0, 0, 0, 0, 0, 0, 0, 0])
b = np.array([0,0,0])
b = np.array([-6, -5, 0, 1, 2, -12, -2, 8])
'''

print("Sistema Linear:")
for i in range(A.shape[0]):
    row = ["{0:3g}*x{1}".format(A[i, j], j + 1) for j in range(A.shape[1])]
    print("[{0}] = [{1:3g}]".format(" + ".join(row), b[i]))

x = np.zeros_like(b)
for it_count in range(1, limit_it):
    x_new = np.zeros_like(x)
    print("Iteração {0}: {1}".format(it_count, x))
    for i in range(A.shape[0]):
        s1 = np.dot(A[i, :i], x_new[:i])
        s2 = np.dot(A[i, i + 1:], x[i + 1:])
        x_new[i] = (b[i] - s1 - s2) / A[i, i]
    if np.allclose(x, x_new, rtol=10**-10):
        break
    x = x_new

print("Solução: {0}".format(x))
error = np.dot(A, x) - b
print("Erro: {0}".format(error))