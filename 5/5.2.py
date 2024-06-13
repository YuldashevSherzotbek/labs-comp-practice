import numpy as np

def lagrange_interpolation(x, y, x_star):
    n = len(x)
    result = 0.0
    
    for i in range(n):
        term = y[i]
        for j in range(n):
            if i != j:
                term *= (x_star - x[j]) / (x[i] - x[j])
        result += term
    
    return result

def exact_function(x):
    return np.sin(x)

# Исходные данные
x = np.array([0.1 * np.pi, 0.2 * np.pi, 0.3 * np.pi, 0.4 * np.pi])
y = np.sin(x)
x_star = 0.25 * np.pi

# Вычисления
interpolated_value = lagrange_interpolation(x, y, x_star)
exact_value = exact_function(x_star)
error = np.abs(interpolated_value - exact_value)

print("Interpolated Value:", interpolated_value)
print("Exact Value:", exact_value)
print("Interpolation Error:", error)
