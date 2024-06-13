import numpy as np

def converge(prev, curr, tol):
    return np.all(np.abs(curr - prev) < tol)

A = np.array([
    [24, -7, -4, 4],
    [-3, -9, -2, -2],
    [3, 7, 24, 9],
    [1, -6, -2, -15]
])

B = np.array([-190, -12, 155, -17])
x = np.zeros_like(B)
tol = 0.01
max_iterations = 1000

for _ in range(max_iterations):
    x_new = np.zeros_like(x)
    x_new[0] = (B[0] - A[0, 1] * x[1] - A[0, 2] * x[2] - A[0, 3] * x[3]) / A[0, 0]
    x_new[1] = (B[1] - A[1, 0] * x_new[0] - A[1, 2] * x[2] - A[1, 3] * x[3]) / A[1, 1]
    x_new[2] = (B[2] - A[2, 0] * x_new[0] - A[2, 1] * x_new[1] - A[2, 3] * x[3]) / A[2, 2]
    x_new[3] = (B[3] - A[3, 0] * x_new[0] - A[3, 1] * x_new[1] - A[3, 2] * x_new[2]) / A[3, 3]
    
    if converge(x, x_new, tol):
        break
    
    x = x_new

print("Решение системы методом Зейделя:")
print("x1 =", x[0])
print("x2 =", x[1])
print("x3 =", x[2])
print("x4 =", x[3])
