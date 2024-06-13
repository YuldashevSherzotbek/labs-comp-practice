#include <iostream>
#include <vector>

using namespace std;

vector<double> solveTridiagonal(vector<double>& a, vector<double>& b, vector<double>& c, vector<double>& d) {
    int n = b.size();
    vector<double> c_prime(n, 0.0);
    vector<double> d_prime(n, 0.0);
    vector<double> x(n, 0.0);

    c_prime[0] = c[0] / b[0];
    d_prime[0] = d[0] / b[0];

    for (int i = 1; i < n; ++i) {
        double m = b[i] - a[i] * c_prime[i - 1];
        c_prime[i] = c[i] / m;
        d_prime[i] = (d[i] - a[i] * d_prime[i - 1]) / m;
    }

    x[n - 1] = d_prime[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        x[i] = d_prime[i] - c_prime[i] * x[i + 1];
    }

    return x;
}

int main() {
    vector<double> a = { 0, -8, -5, 1, -4 };
    vector<double> b = { 14, 14, 17, 5, -10 };
    vector<double> c = { 9, 6, 8, -2, 0 };
    vector<double> d = { 125, -56, 144, -36, 70 };

    vector<double> x = solveTridiagonal(a, b, c, d);

    cout << "Решение системы методом прогонки:" << endl;
    for (int i = 0; i < x.size(); ++i) {
        cout << "x" << (i + 1) << " = " << x[i] << endl;
    }

    return 0;
}
