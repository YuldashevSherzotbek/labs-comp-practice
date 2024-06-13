import numpy as np

def solve_tridiagonal(a, b, c, d):
    n = len(b)
    c_prime = np.zeros(n)
    d_prime = np.zeros(n)
    x = np.zeros(n)

    c_prime[0] = c[0] / b[0]
    d_prime[0] = d[0] / b[0]

    for i in range(1, n):
        m = b[i] - a[i] * c_prime[i - 1]
        c_prime[i] = c[i] / m
        d_prime[i] = (d[i] - a[i] * d_prime[i - 1]) / m

    x[-1] = d_prime[-1]
    for i in range(n - 2, -1, -1):
        x[i] = d_prime[i] - c_prime[i] * x[i + 1]

    return x

a = np.array([0, -8, -5, 1, -4])
b = np.array([14, 14, 17, 5, -10])
c = np.array([9, 6, 8, -2, 0])
d = np.array([125, -56, 144, -36, 70])

x = solve_tridiagonal(a, b, c, d)

print("Решение системы методом прогонки:")
for i in range(len(x)):
    print(f"x{i + 1} = {x[i]}")
