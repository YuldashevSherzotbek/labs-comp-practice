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
        {0, 2, 2},
        {5, 2, 5},
        {2, 2, 5}
    };

    vector<double> B = { -1, 2, 0 };
    vector<double> x = { 0, 0, 0 };
    vector<double> x_new(3, 0);
    double tol = 1e-6;
    int max_iterations = 1000;
    int iterations = 0;

    while (iterations < max_iterations) {
        x_new[0] = (B[0] - A[0][1] * x[1] - A[0][2] * x[2]) / A[0][0];
        x_new[1] = (B[1] - A[1][0] * x[0] - A[1][2] * x[2]) / A[1][1];
        x_new[2] = (B[2] - A[2][0] * x[0] - A[2][1] * x[1]) / A[2][2];

        if (converge(x, x_new, tol)) {
            break;
        }

        x = x_new;
        ++iterations;
    }

    cout << "–ешение системы методом якоби:" << endl;
    cout << "x1 = " << x[0] << endl;
    cout << "x2 = " << x[1] << endl;
    cout << "x3 = " << x[2] << endl;

    return 0;
}
