#include <iostream>
#include <cmath>

double f(double x) {
    return x * exp(x) - x - 1;
}

double df(double x) {
    return exp(x) + x * exp(x) - 1;
}

// Метод дихотомии
double bisection(double a, double b, double epsilon) {
    double c;
    while ((b - a) / 2 > epsilon) {
        c = (a + b) / 2;
        if (f(c) == 0.0) {
            break;
        }
        else if (f(c) * f(a) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }
    return c;
}

// Метод итераций
double phi(double x) {
    return x - (f(x) / df(x));
}

double fixedPointIteration(double x0, double epsilon) {
    double x1;
    do {
        x1 = phi(x0);
        if (fabs(x1 - x0) < epsilon) {
            break;
        }
        x0 = x1;
    } while (true);
    return x1;
}

// Метод хорд
double secant(double x0, double x1, double epsilon) {
    double x2;
    do {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
    } while (fabs(f(x2)) > epsilon);
    return x2;
}

// Метод Ньютона
double newton(double x0, double epsilon) {
    double x1;
    do {
        x1 = x0 - f(x0) / df(x0);
        if (fabs(x1 - x0) < epsilon) {
            break;
        }
        x0 = x1;
    } while (true);
    return x1;
}

int main() {
    setlocale(LC_ALL, "RU");
    double a = 0, b = 1, x0 = 0.5, x1 = 1, epsilon = 1e-6;

    double root_bisection = bisection(a, b, epsilon);
    std::cout << "Корень методом дихотомии: " << root_bisection << std::endl;

    double root_fixed_point = fixedPointIteration(x0, epsilon);
    std::cout << "Корень методом итераций: " << root_fixed_point << std::endl;

    double root_secant = secant(a, b, epsilon);
    std::cout << "Корень методом хорд: " << root_secant << std::endl;

    double root_newton = newton(x0, epsilon);
    std::cout << "Корень методом Ньютона: " << root_newton << std::endl;

    return 0;
}
