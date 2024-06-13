import numpy as np

def function(x):
    return x[0] + 5 * x[1] + np.exp(x[0]**2 + x[1]**2)

def coordinate_descent(alpha, max_iter):
    x = np.array([0.0, 0.0])  # начальная точка
    for _ in range(max_iter):
        for i in range(2):
            x_new = np.copy(x)
            x_new[i] += alpha
            if function(x_new) < function(x):
                x[i] = x_new[i]
            else:
                x_new[i] -= 2 * alpha
                if function(x_new) < function(x):
                    x[i] = x_new[i]
    return x

alpha = 0.01
max_iter = 1000
result = coordinate_descent(alpha, max_iter)

print("Минимум достигается в точке:", result)
print("Значение функции в этой точке:", function(result))
