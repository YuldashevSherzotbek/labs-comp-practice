import math

def f(x):
    return x * math.exp(x) - x - 1

def df(x):
    return math.exp(x) + x * math.exp(x) - 1

# Метод дихотомии
def bisection(a, b, epsilon):
    while (b - a) / 2 > epsilon:
        c = (a + b) / 2
        if f(c) == 0.0:
            return c
        elif f(c) * f(a) < 0:
            b = c
        else:
            a = c
    return c

# Метод итераций
def phi(x):
    return x - f(x) / df(x)

def fixed_point_iteration(x0, epsilon):
    while True:
        x1 = phi(x0)
        if abs(x1 - x0) < epsilon:
            return x1
        x0 = x1

# Метод хорд
def secant(x0, x1, epsilon):
    while True:
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
        if abs(f(x2)) < epsilon:
            return x2
        x0, x1 = x1, x2

# Метод Ньютона
def newton(x0, epsilon):
    while True:
        x1 = x0 - f(x0) / df(x0)
        if abs(x1 - x0) < epsilon:
            return x1
        x0 = x1

# Главная программа
a, b = 0, 1
x0 = 0.5
epsilon = 1e-6

root_bisection = bisection(a, b, epsilon)
print(f"Корень методом дихотомии: {root_bisection}")

root_fixed_point = fixed_point_iteration(x0, epsilon)
print(f"Корень методом итераций: {root_fixed_point}")

root_secant = secant(a, b, epsilon)
print(f"Корень методом хорд: {root_secant}")

root_newton = newton(x0, epsilon)
print(f"Корень методом Ньютона: {root_newton}")
