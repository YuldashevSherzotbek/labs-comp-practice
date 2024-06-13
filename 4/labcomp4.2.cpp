#include <iostream>
#include <vector>

using namespace std;

// Функция для вычисления определителя матрицы 3x3
double determinant(vector<vector<double>> mat) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
        mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
        mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

int main() {
    vector<vector<double>> A = {
        {0, 2, 2},
        {5, 2, 5},
        {2, 2, 5}
    };

    vector<double> B = { -1, 2, 0 };

    double detA = determinant(A);
    if (detA == 0) {
        cout << "Система не имеет единственного решения." << endl;
        return 0;
    }

    vector<vector<double>> A1 = A, A2 = A, A3 = A;
    for (int i = 0; i < 3; ++i) {
        A1[i][0] = B[i];
        A2[i][1] = B[i];
        A3[i][2] = B[i];
    }

    double detA1 = determinant(A1);
    double detA2 = determinant(A2);
    double detA3 = determinant(A3);

    double x1 = detA1 / detA;
    double x2 = detA2 / detA;
    double x3 = detA3 / detA;

    cout << "Решение системы методом Крамера:" << endl;
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;

    return 0;
}
