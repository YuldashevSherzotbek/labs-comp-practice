import numpy as np

def determinant(mat):
    return np.linalg.det(mat)

A = np.array([
    [0, 2, 2],
    [5, 2, 5],
    [2, 2, 5]
])

B = np.array([-1, 2, 0])

detA = determinant(A)
if detA == 0:
    print("Система не имеет единственного решения.")
else:
    A1 = A.copy()
    A2 = A.copy()
    A3 = A.copy()
    
    A1[:, 0] = B
    A2[:, 1] = B
    A3[:, 2] = B
    
    detA1 = determinant(A1)
    detA2 = determinant(A2)
    detA3 = determinant(A3)
    
    x1 = detA1 / detA
    x2 = detA2 / detA
    x3 = detA3 / detA
    
    print("Решение системы методом Крамера:")
    print("x1 =", x1)
    print("x2 =", x2)
    print("x3 =", x3)
