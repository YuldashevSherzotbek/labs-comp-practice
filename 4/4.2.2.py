import numpy as np

A = np.array([
    [0, 2, 2],
    [5, 2, 5],
    [2, 2, 5]
])

B = np.array([-1, 2, 0])
x = np.zeros_like(B)
x_new = np.zeros_like(B)
tol = 1e-6
max_iterations = 1000

def converge(prev, curr, tol):
    return np.all(np.abs(curr - prev) < tol)

for _ in range(max_iterations):
    x_new[0] = (B[0] - A[0, 1] * x[1] - A[0, 2] * x[2]) / A[0, 0]
    x_new[1] = (B[1] - A[1, 0] * x[0] - A[1, 2] * x[2]) / A[1, 1]
    x_new[2] = (B[2] - A[2, 0] * x[0] - A[2, 1] * x[1]) / A[2, 2]
    
    if converge(x, x_new, tol):
        break
    
    x = x_new.copy()

print("Решение системы методом Якоби:")
print("x1 =", x[0])
print("x2 =", x[1])
print("x3 =", x[2])
