#include <iostream>
#include <cmath>
#include <vector>

double function(const std::vector<double>& x) {
    return x[0] + 5 * x[1] + exp(x[0] * x[0] + x[1] * x[1]);
}

std::vector<double> coordinate_descent(double alpha, int max_iter) {
    std::vector<double> x = { 0.0, 0.0 }; // начальная точка
    for (int iter = 0; iter < max_iter; ++iter) {
        for (int i = 0; i < 2; ++i) {
            std::vector<double> x_new = x;
            x_new[i] += alpha;
            if (function(x_new) < function(x)) {
                x[i] = x_new[i];
            }
            else {
                x_new[i] -= 2 * alpha;
                if (function(x_new) < function(x)) {
                    x[i] = x_new[i];
                }
            }
        }
    }
    return x;
}

int main() {
    double alpha = 0.01;
    int max_iter = 1000;
    std::vector<double> result = coordinate_descent(alpha, max_iter);

    std::cout << "Минимум достигается в точке: (" << result[0] << ", " << result[1] << ")" << std::endl;
    std::cout << "Значение функции в этой точке: " << function(result) << std::endl;

    return 0;
}
