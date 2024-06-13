#include <iostream>
#include <complex>
#include <cmath>

int main() {
    setlocale(LC_ALL, "RU");
    std::complex<double> z1(-1, 1);
    std::complex<double> z2(-4, -2);
    std::complex<double> z3(-1, -1);

    // Сумма
    std::complex<double> sum = z1 + z2;
    std::cout << "Сумма: " << sum << std::endl;

    // Разность
    std::complex<double> diff = z1 - z2;
    std::cout << "Разность: " << diff << std::endl;

    // Произведение
    std::complex<double> prod = z1 * z2;
    std::cout << "Произведение: " << prod << std::endl;

    // Частное
    std::complex<double> quot = z1 / z2;
    std::cout << "Частное: " << quot << std::endl;

    // Четвертая степень
    std::complex<double> z3_pow4 = pow(z3, 4);
    std::cout << "z3 в четвертой степени: " << z3_pow4 << std::endl;

    // Корень третьей степени
    std::complex<double> z3_root3 = pow(z3, 1.0 / 3);
    std::cout << "Корень третьей степени z3: " << z3_root3 << std::endl;

    return 0;
}
