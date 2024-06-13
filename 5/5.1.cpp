#include <iostream>
#include <vector>

using namespace std;

double firstDerivative(const vector<double>& x, const vector<double>& y, double point) {
    for (int i = 1; i < x.size() - 1; ++i) {
        if (x[i] == point) {
            return (y[i + 1] - y[i - 1]) / (x[i + 1] - x[i - 1]);
        }
    }
    return 0.0;
}

double secondDerivative(const vector<double>& x, const vector<double>& y, double point) {
    for (int i = 1; i < x.size() - 1; ++i) {
        if (x[i] == point) {
            return (y[i + 1] - 2 * y[i] + y[i - 1]) / ((x[i + 1] - x[i]) * (x[i] - x[i - 1]));
        }
    }
    return 0.0;
}

int main() {
    vector<double> x = { -1.0, 0.0, 1.0, 2.0, 3.0 };
    vector<double> y = { -0.5, 0.0, 0.5, 0.86603, 1.0 };
    double point = 1.0;

    double first_deriv = firstDerivative(x, y, point);
    double second_deriv = secondDerivative(x, y, point);

    cout << "Первая производная в точке x = " << point << " равна " << first_deriv << endl;
    cout << "Вторая производная в точке x = " << point << " равна " << second_deriv << endl;

    return 0;
}
