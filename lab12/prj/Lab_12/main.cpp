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
    ClassLab12_Kalashnyk(double a_val = 140, double b_val = 40, const std::string& color_val = "��������", double height_val = 80) {
        if (a_val <= 0 || b_val <= 0) {
            std::cout << "�������: ��������� �������� ������ �����!" << std::endl;
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
            std::cout << "�������: ��������� �������� ������ �����!" << std::endl;
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
    std::string color = "��������";
    double height = 80;

    ClassLab12_Kalashnyk table(a, b, color, height);

    int option = 0;

    while (option != 3) {
        system("cls");
        std::cout << "����:" << std::endl;
        std::cout << "1. ��������� �����;" << std::endl;
        std::cout << "2. ������ ��������� �����;" << std::endl;
        std::cout << "3. �����;" << std::endl;
        std::cout << "������� �����: ";
        std::cin >> option;

        switch (option) {
            case 1:
                system("cls");
                std::cout << "��������� �����:" << std::endl;
                std::cout << "\n������� ������ ����: " << a << "��" << std::endl;
                std::cout << "������� ���� ����: " << b << "��" << std::endl;
                std::cout << "����� ������� �����: " << table.getPlosha() << "��^2" << std::endl;
                std::cout << "���� �����: " << table.getColor() << std::endl;
                std::cout << "������ �����: " << table.getHeight() << std::endl;
                system("pause");
                break;
            case 2:
                system("cls");
                std::cout << "������ ��� �������� �����:" << std::endl;
                std::cout << "������� ������ ���� (��): ";
                std::cin >> a;
                std::cout << "������� ���� ���� (��): ";
                std::cin >> b;
                std::cout << "������ (��): ";
                std::cin >> height;
                std::cout << "\n����: ";
                std::cin >> color;
                table.setPivvisi(a, b);
                table.setAttributes(color, height);

                std::cout << "\n��������� ������ �����:" << std::endl;
                std::cout << "������� ������ ����: " << a << "��" << std::endl;
                std::cout << "������� ���� ����: " << b << "��" << std::endl;
                std::cout << "����� ������� �����: " << table.getPlosha() << "��^2" << std::endl;
                std::cout << "���� �����: " << table.getColor() << std::endl;
                std::cout << "������ �����: " << table.getHeight() << std::endl;
                std::cout << "�������� ����-��� ������" << std::endl;
                system("pause");
                getchar();
                break;
            case 3:
                system("cls");
                std::cout << "�� ���������!" << std::endl;
                break;
            default:
                std::cout << "���������� �����. ��������� �� ���." << std::endl;
                break;
        }

        std::cout << std::endl;
    }

    return 0;
}
