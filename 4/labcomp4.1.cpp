#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функция для вычисления детерминанта матрицы 4x4
double determinant(vector<vector<double>>& matrix) {
    double det = 0;
    for (int i = 0; i < 4; i++) {
        double sub_det = matrix[0][i];
        for (int j = 1; j < 4; j++) {
            sub_det *= matrix[j][(i + j) % 4];
        }
        det += sub_det;

        sub_det = matrix[0][i];
        for (int j = 1; j < 4; j++) {
            sub_det *= matrix[j][(i - j + 4) % 4];
        }
        det -= sub_det;
    }
    return det;
}

// Функция для замены столбца в матрице
void replaceColumn(vector<vector<double>>& matrix, vector<double>& column, int col) {
    for (int i = 0; i < 4; i++) {
        matrix[i][col] = column[i];
    }
}

// Метод Крамера
void cramerMethod(vector<vector<double>>& A, vector<double>& b) {
    double detA = determinant(A);
    if (detA == 0) {
        cout << "Система не имеет единственного решения (определитель равен нулю)." << endl;
        return;
    }

    vector<double> solution(4);
    for (int i = 0; i < 4; i++) {
        vector<vector<double>> tempA = A;
        replaceColumn(tempA, b, i);
        solution[i] = determinant(tempA) / detA;
    }

    // Вывод решения
    cout << "Решение системы: ";
    for (double x : solution) {
        cout << x << " ";
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

    cramerMethod(A, b);

    return 0;
}