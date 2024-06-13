#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void gaussianElimination(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        // Частичная перестановка
        for (int k = i + 1; k < n; k++) {
            if (abs(A[i][i]) < abs(A[k][i])) {
                swap(A[i], A[k]);
                swap(b[i], b[k]);
            }
        }

        // Метод Гаусса
        for (int k = i + 1; k < n; k++) {
            double t = A[k][i] / A[i][i];
            for (int j = i; j < n; j++) {
                A[k][j] -= t * A[i][j];
            }
            b[k] -= t * b[i];
        }
    }

    // Обратный ход
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    // Вывод решения
    cout << "Решение системы: ";
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<double>> A = {
        {-6, -5, 3, -8},
        {5, -1, -5, 4},
        {-6, 0, 5, 5},
        {-7, -2, 8, 5}
    };
    vector<double> b = { 101, 51, 53, -63 };

    gaussianElimination(A, b);

    return 0;
}