#include <iostream>
#include <complex>
#include <cmath>

int main() {
    setlocale(LC_ALL, "RU");
    std::complex<double> z1(-1, 1);
    std::complex<double> z2(-4, -2);
    std::complex<double> z3(-1, -1);

    // �����
    std::complex<double> sum = z1 + z2;
    std::cout << "�����: " << sum << std::endl;

    // ��������
    std::complex<double> diff = z1 - z2;
    std::cout << "��������: " << diff << std::endl;

    // ������������
    std::complex<double> prod = z1 * z2;
    std::cout << "������������: " << prod << std::endl;

    // �������
    std::complex<double> quot = z1 / z2;
    std::cout << "�������: " << quot << std::endl;

    // ��������� �������
    std::complex<double> z3_pow4 = pow(z3, 4);
    std::cout << "z3 � ��������� �������: " << z3_pow4 << std::endl;

    // ������ ������� �������
    std::complex<double> z3_root3 = pow(z3, 1.0 / 3);
    std::cout << "������ ������� ������� z3: " << z3_root3 << std::endl;

    return 0;
}
