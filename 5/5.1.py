def first_derivative(x, y, point):
    for i in range(1, len(x) - 1):
        if x[i] == point:
            return (y[i + 1] - y[i - 1]) / (x[i + 1] - x[i - 1])
    return 0.0

def second_derivative(x, y, point):
    for i in range(1, len(x) - 1):
        if x[i] == point:
            return (y[i + 1] - 2 * y[i] + y[i - 1]) / ((x[i + 1] - x[i]) * (x[i] - x[i - 1]))
    return 0.0

x = [-1.0, 0.0, 1.0, 2.0, 3.0]
y = [-0.5, 0.0, 0.5, 0.86603, 1.0]
point = 1.0

first_deriv = first_derivative(x, y, point)
second_deriv = second_derivative(x, y, point)

print(f"Первая производная в точке x = {point} равна {first_deriv}")
print(f"Вторая производная в точке x = {point} равна {second_deriv}")
