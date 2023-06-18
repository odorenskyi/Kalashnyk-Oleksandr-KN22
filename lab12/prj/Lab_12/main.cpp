#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <math.h>

class ClassLab12_Kalashnyk {
private:
    double a;
    double b;
    std::string color;
    double height;

public:
    ClassLab12_Kalashnyk(double a_val = 140, double b_val = 40, const std::string& color_val = "Горіховий", double height_val = 80) {
        if (a_val <= 0 || b_val <= 0) {
            std::cout << "Помилка: некоректні значення піввісей еліпса!" << std::endl;
            a = b = 0;
        } else {
            a = a_val;
            b = b_val;
        }

        color = color_val;
        height = height_val;
    }

    double getPlosha() const {
        return a * b * M_PI;
    }

    std::string getColor() const {
        return color;
    }

    double getHeight() const {
        return height;
    }

    void setPivvisi(double a_val, double b_val) {
        if (a_val <= 0 || b_val <= 0) {
            std::cout << "Помилка: некоректні значення піввісей еліпса!" << std::endl;
        } else {
            a = a_val;
            b = b_val;
        }
    }

    void setAttributes(const std::string& color_val, double height_val) {
        color = color_val;
        height = height_val;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double a, b;
    a = 140;
    b = 40;
    std::string color = "Горіховий";
    double height = 80;

    ClassLab12_Kalashnyk table(a, b, color, height);

    int option = 0;

    while (option != 3) {
        system("cls");
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Параметри стола;" << std::endl;
        std::cout << "2. Змінити параметри стола;" << std::endl;
        std::cout << "3. Вихід;" << std::endl;
        std::cout << "Виберіть опцію: ";
        std::cin >> option;

        switch (option) {
            case 1:
                system("cls");
                std::cout << "Параметри стола:" << std::endl;
                std::cout << "\nДовжина великої піввісі: " << a << "см" << std::endl;
                std::cout << "Довжина малої піввісі: " << b << "см" << std::endl;
                std::cout << "Площа поверхні столу: " << table.getPlosha() << "см^2" << std::endl;
                std::cout << "Колір столу: " << table.getColor() << std::endl;
                std::cout << "Висота столу: " << table.getHeight() << std::endl;
                system("pause");
                break;
            case 2:
                system("cls");
                std::cout << "Введіть нові значення стола:" << std::endl;
                std::cout << "Довжина великої піввісі (см): ";
                std::cin >> a;
                std::cout << "Довжина малої піввісі (см): ";
                std::cin >> b;
                std::cout << "Висота (см): ";
                std::cin >> height;
                std::cout << "\nКолір: ";
                std::cin >> color;
                table.setPivvisi(a, b);
                table.setAttributes(color, height);

                std::cout << "\nПараметри Вашого стола:" << std::endl;
                std::cout << "Довжина великої піввісі: " << a << "см" << std::endl;
                std::cout << "Довжина малої піввісі: " << b << "см" << std::endl;
                std::cout << "Площа поверхні столу: " << table.getPlosha() << "см^2" << std::endl;
                std::cout << "Колір столу: " << table.getColor() << std::endl;
                std::cout << "Висота столу: " << table.getHeight() << std::endl;
                std::cout << "Натисніть будь-яку кнопку" << std::endl;
                system("pause");
                getchar();
                break;
            case 3:
                system("cls");
                std::cout << "До побачення!" << std::endl;
                break;
            default:
                std::cout << "Некоректна опція. Спробуйте ще раз." << std::endl;
                break;
        }

        std::cout << std::endl;
    }

    return 0;
}
