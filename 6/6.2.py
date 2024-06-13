import numpy as np

def function(x):
    return x[0] + 2 * x[1] + 4 * np.sqrt(1 + x[0]**2 + x[1]**2)

def gradient(x):
    common_term = 4 / np.sqrt(1 + x[0]**2 + x[1]**2)
    return np.array([1 + x[0] * common_term, 2 + x[1] * common_term])

def gradient_descent(alpha, max_iter):
    x = np.array([0.0, 0.0])  # начальная точка
    for _ in range(max_iter):
        grad = gradient(x)
        x -= alpha * grad
    return x

alpha = 0.01
max_iter = 1000
result = gradient_descent(alpha, max_iter)

print("Минимум достигается в точке:", result)
print("Значение функции в этой точке:", function(result))
