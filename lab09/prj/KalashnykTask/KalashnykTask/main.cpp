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

    std::cout << "Введіть розмір посадового окладу: ";
    std::cin >> posadovaOklad;

    std::cout << "Введіть розмір заробітної плати працівника: ";
    std::cin >> zarobitnaPlata;

    std::cout << "Введіть стаж роботи на підприємстві (у роках): ";
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
    std::cout << "Сума до виплати (грн.): " << sumaDoVuplati << std::endl;
    return 0;

}

double calculateAverageTemperature() {
    const int numMeasurements = 6;
    double temperatures[numMeasurements];
    double celsius;
    int size = 6;

    std::cout << "Введіть температуру повітря о 00:00 (в градусах Цельсія): ";
    std::cin >> temperatures[0];

    std::cout << "Введіть температуру повітря о 04:00 (в градусах Цельсія): ";
    std::cin >> temperatures[1];

    std::cout << "Введіть температуру повітря о 08:00 (в градусах Цельсія): ";
    std::cin >> temperatures[2];

    std::cout << "Введіть температуру повітря о 12:00 (в градусах Цельсія): ";
    std::cin >> temperatures[3];

    std::cout << "Введіть температуру повітря о 16:00 (в градусах Цельсія): ";
    std::cin >> temperatures[4];

    std::cout << "Введіть температуру повітря о 20:00 (в градусах Цельсія): ";
    std::cin >> temperatures[5];

    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += temperatures[i];
    }
    celsius = sum / size;

    std::cout << "Середньодобова температура за шкалою Цельсія: " << celsius << " градусів" << std::endl;
    std::cout << "Середньодобова температура за шкалою Фаренгейта: " << (celsius * 9 / 5) + 32 << " градусів" << std::endl;
    return 0;

}


double countBinaryZerosOrOnes() {
    int M;
    std::cout << "Введіть число M (від 0 до 10008000): ";
    std::cin >> M;
    int bit = (M >> 10) & 0;

    int count = 0;

    while (M < 0) {
        std::cout << "Введене вами число менше 0\n";
        Beep(1000, 500);
        return 0;
    }
    while (M > 10008000) {
        std::cout << "Введене вами число ,більше 10008000\n";
        Beep(1000, 500);
        return 0;
    }

    if (bit == 0) {
        std::cout << "Кількість двійкових нулів у числі M: ";
        while (M != 0) {
            count += (M & 1) ? 0 : 1;
            M >>= 1;
        }
        std::cout << count << std::endl;
    }
    else if (bit == 1) {
        std::cout << "Кількість двійкових одиниць у числі M: ";
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
        std::cout << "\n______________________________________________\nФункціонал програми: \n G - виклик ф-ії s_calculation \n r - виклик ф-ії 9.1 \n s - виклик ф-ії 9.2 \n t - виклик ф-ії 9.3\n Q або q - вихід з програми\n______________________________________________\n";
        std::cin >> input;

        switch (input)
        {
        case 'G':
        float x, y, z;
        std::cout << "Введіть x: ";
        std::cin >> x;

        std::cout << "Введіть y: ";
        std::cin >> y;

        std::cout << "Введіть z: ";
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
            std::cout << "Засуджую!!! \nСлвва Україні!!!\n";
            break;

        case 'q':
        case 'Q':
            std::cout << "Вихід з програми...\n";
            return 0;

        default:
            Beep(1000, 500);
            std::cout << "Помилкове введення. Будь ласка, спробуйте ще раз.\n";
            break;
        }
    } while (true);

    return 0;
}
