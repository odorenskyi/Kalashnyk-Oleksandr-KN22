#include <iostream>
#include <windows.h>
#include <math.h>
#include <locale.h>
#include <string>
#include "ModulesKalashnyk.h"

float calculateNadbavka() {
    int stazRoboti;
    double nadbavka = 0.0;
    double posadovaOklad, zarobitnaPlata, sumaDoVuplati;

    std::cout << "������ ����� ���������� ������: ";
    std::cin >> posadovaOklad;

    std::cout << "������ ����� �������� ����� ����������: ";
    std::cin >> zarobitnaPlata;

    std::cout << "������ ���� ������ �� ��������� (� �����): ";
    std::cin >> stazRoboti;

    if (stazRoboti >= 3 && stazRoboti < 5) {
        nadbavka = 0.1 * posadovaOklad;
    }
    else if (stazRoboti >= 5 && stazRoboti < 7) {
        nadbavka = 0.15 * posadovaOklad;
    }
    else if (stazRoboti >= 7 && stazRoboti < 15) {
        nadbavka = 0.2 * posadovaOklad;
    }
    else if (stazRoboti >= 15) {
        nadbavka = 0.25 * posadovaOklad;
    }
    sumaDoVuplati = zarobitnaPlata + nadbavka;
    std::cout << "���� �� ������� (���.): " << sumaDoVuplati << std::endl;
    return 0;

}

double calculateAverageTemperature() {
    const int numMeasurements = 6;
    double temperatures[numMeasurements];
    double celsius;
    int size = 6;

    std::cout << "������ ����������� ������ � 00:00 (� �������� ������): ";
    std::cin >> temperatures[0];

    std::cout << "������ ����������� ������ � 04:00 (� �������� ������): ";
    std::cin >> temperatures[1];

    std::cout << "������ ����������� ������ � 08:00 (� �������� ������): ";
    std::cin >> temperatures[2];

    std::cout << "������ ����������� ������ � 12:00 (� �������� ������): ";
    std::cin >> temperatures[3];

    std::cout << "������ ����������� ������ � 16:00 (� �������� ������): ";
    std::cin >> temperatures[4];

    std::cout << "������ ����������� ������ � 20:00 (� �������� ������): ";
    std::cin >> temperatures[5];

    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += temperatures[i];
    }
    celsius = sum / size;

    std::cout << "�������������� ����������� �� ������ ������: " << celsius << " �������" << std::endl;
    std::cout << "�������������� ����������� �� ������ ����������: " << (celsius * 9 / 5) + 32 << " �������" << std::endl;
    return 0;

}


double countBinaryZerosOrOnes() {
    int M;
    std::cout << "������ ����� M (�� 0 �� 10008000): ";
    std::cin >> M;
    int bit = (M >> 10) & 0;

    int count = 0;

    while (M < 0) {
        std::cout << "������� ���� ����� ����� 0\n";
        Beep(1000, 500);
        return 0;
    }
    while (M > 10008000) {
        std::cout << "������� ���� ����� ,����� 10008000\n";
        Beep(1000, 500);
        return 0;
    }

    if (bit == 0) {
        std::cout << "ʳ������ �������� ���� � ���� M: ";
        while (M != 0) {
            count += (M & 1) ? 0 : 1;
            M >>= 1;
        }
        std::cout << count << std::endl;
    }
    else if (bit == 1) {
        std::cout << "ʳ������ �������� ������� � ���� M: ";
        while (M != 1) {
            count += (M & 1) ? 1 : 0;
            M >>= 1;
        }
        std::cout << count << std::endl;
    }
    return 0;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char input;
    do
    {
        std::cout << "\n______________________________________________\n���������� ��������: \n G - ������ �-�� s_calculation \n r - ������ �-�� 9.1 \n s - ������ �-�� 9.2 \n t - ������ �-�� 9.3\n Q ��� q - ����� � ��������\n______________________________________________\n";
        std::cin >> input;

        switch (input)
        {
        case 'G':
        float x, y, z;
        std::cout << "������ x: ";
        std::cin >> x;

        std::cout << "������ y: ";
        std::cin >> y;

        std::cout << "������ z: ";
        std::cin >> z;
            std::cout << s_calculation(x, y, z);
            break;

        case 'r':
            calculateNadbavka();
            break;

        case 's':
            calculateAverageTemperature();
            break;

        case 't':
            countBinaryZerosOrOnes();
            break;

        case 'z':
            std::cout << "��������!!! \n����� �����!!!\n";
            break;

        case 'q':
        case 'Q':
            std::cout << "����� � ��������...\n";
            return 0;

        default:
            Beep(1000, 500);
            std::cout << "��������� ��������. ���� �����, ��������� �� ���.\n";
            break;
        }
    } while (true);

    return 0;
}
