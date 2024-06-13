#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool converge(vector<double>& prev, vector<double>& curr, double tol) {
    for (int i = 0; i < prev.size(); ++i) {
        if (fabs(curr[i] - prev[i]) > tol) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<vector<double>> A = {
        {24, -7, -4, 4},
        {-3, -9, -2, -2},
        {3, 7, 24, 9},
        {1, -6, -2, -15}
    };

    vector<double> B = { -190, -12, 155, -17 };
    vector<double> x = { 0, 0, 0, 0 };
    vector<double> x_new(4, 0);
    double tol = 0.01;
    int max_iterations = 1000;
    int iterations = 0;

    while (iterations < max_iterations) {
        x_new[0] = (B[0] - A[0][1] * x_new[1] - A[0][2] * x_new[2] - A[0][3] * x_new[3]) / A[0][0];
        x_new[1] = (B[1] - A[1][0] * x_new[0] - A[1][2] * x_new[2] - A[1][3] * x_new[3]) / A[1][1];
        x_new[2] = (B[2] - A[2][0] * x_new[0] - A[2][1] * x_new[1] - A[2][3] * x_new[3]) / A[2][2];
        x_new[3] = (B[3] - A[3][0] * x_new[0] - A[3][1] * x_new[1] - A[3][2] * x_new[2]) / A[3][3];

        if (converge(x, x_new, tol)) {
            break;
        }

        x = x_new;
        ++iterations;
    }

    cout << "Решение системы методом Зейделя:" << endl;
    cout << "x1 = " << x[0] << endl;
    cout << "x2 = " << x[1] << endl;
    cout << "x3 = " << x[2] << endl;
    cout << "x4 = " << x[3] << endl;

    return 0;
}
