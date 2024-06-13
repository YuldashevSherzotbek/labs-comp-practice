#include <iostream>
#include <cmath>
#include <vector>

double function(const std::vector<double>& x) {
    return x[0] + 2 * x[1] + 4 * sqrt(1 + x[0] * x[0] + x[1] * x[1]);
}

std::vector<double> gradient(const std::vector<double>& x) {
    double common_term = 4 / sqrt(1 + x[0] * x[0] + x[1] * x[1]);
    return { 1 + x[0] * common_term, 2 + x[1] * common_term };
}

std::vector<double> gradient_descent(double alpha, int max_iter) {
    std::vector<double> x = { 0.0, 0.0 }; // начальная точка
    for (int iter = 0; iter < max_iter; ++iter) {
        std::vector<double> grad = gradient(x);
        x[0] -= alpha * grad[0];
        x[1] -= alpha * grad[1];
    }
    return x;
}

int main() {
    double alpha = 0.01;
    int max_iter = 1000;
    std::vector<double> result = gradient_descent(alpha, max_iter);

    std::cout << "Минимум достигается в точке: (" << result[0] << ", " << result[1] << ")" << std::endl;
    std::cout << "Значение функции в этой точке: " << function(result) << std::endl;

    return 0;
}
