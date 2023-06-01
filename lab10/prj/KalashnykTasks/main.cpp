#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "ModulesKalashnyk.h"
#include <locale.h>
#include <random>


std::string DecimalToBinary(int decimal) {
    std::string binary;
    while (decimal > 0) {
        binary = (decimal % 2 == 0 ? "0" : "1") + binary;
        decimal /= 2;
    }
    return binary;
}

int generateRandomNumber(int min, int max) {
    // ���������� ��������� ���������� ����� �� �������� �����
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // �������� ��������� ����� � �������� �������
    int randomNumber = min + (std::rand() % (max - min + 1));

    return randomNumber;
}

void writeAuthorInfo(std::ofstream& file) {
    file << "�����: ���������" << std::endl;
    file << "��������/����������: ����" << std::endl;
    file << "̳���: �������������" << std::endl;
    file << "�����: ������" << std::endl;
    file << "г� ��������: 2023" << std::endl;
    file << "��������� ������: �������� �.�." << std::endl;
    file << "��������� �����: " << rand()%91+10 << std::endl;
}

bool hasPunctuationMistakes(const std::string& text) {
    std::string allowedPunctuation = ".,?!:;";
    for (char c : text) {
        if (ispunct(c)) {
            if (allowedPunctuation.find(c) == std::string::npos) {
                return true;
            }
        }
    }
    return false;
}

void appendDate(std::ofstream& file) {
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char date[11];
    strftime(date, sizeof(date), "%d.%m.%Y", timeinfo);
    file << "���� �������� ����������: " << date << std::endl;
}

void appendResults(std::ofstream& file, float x, float y, float z, double b) {
    file << "��������" << std::endl;
    file << "���������� ��������� ������� �� ������������� ����� Modules:" << std::endl;
    file << "s_calculation(" << x << ", " << y << ", " << z << ") = " << s_calculation(x, y, z) << std::endl;
    std::string binaryNum = DecimalToBinary(b);
    file << "����� " << y << " � ��������� ���: " << binaryNum << std::endl;
}

int main() {
    char *locale = setlocale(LC_ALL, "");
    int choice;
    int randomNumber = generateRandomNumber(10, 100);
    std::cout << "������� ��������:" << std::endl;
    std::cout << "1. �������� 10.1" << std::endl;
    std::cout << "2. �������� 10.2" << std::endl;
    std::cout << "3. �������� 10.3" << std::endl;
    std::cin >> choice;

    if (choice == 1) {
        std::ifstream input("input.txt");
        std::ofstream output("output.txt");

        if (!input || !output) {
            std::cout << "������� �������� �����!" << std::endl;
            return 1;
        }

        writeAuthorInfo(output);

        std::string line;
        while (std::getline(input, line)) {
            bool punctuationMistakes = hasPunctuationMistakes(line);
            output << "����� �� ����������� �������: " << (punctuationMistakes ? "���" : "ͳ") << std::endl;
        }

        input.close();
        output.close();

        std::cout << "���������� ���� �������� � ����: output.txt" << std::endl;
    }

    // �������� 10.2
    else if (choice == 2) {
        std::ofstream output("output.txt", std::ios::app);
        if (!output) {
            std::cout << "������� �������� �����!" << std::endl;
            return 1;
        }
        appendDate(output);
        output.close();

        std::cout << "���������� ���� ������ �� �����: output.txt" << std::endl;
    }

    else if (choice == 3) {
        float x, y, z;
        double b;

        std::cout << "������ �������� x: ";
        std::cin >> x;
        std::cout << "������ �������� y: ";
        std::cin >> y;
        std::cout << "������ �������� z: ";
        std::cin >> z;
        std::cout << "������ �������� b: ";
        std::cin >> b;
        std::ofstream output("output.txt", std::ios::app);
        if (!output) {
            std::cout << "������� �������� �����!" << std::endl;
            return 1;
        }
        appendResults(output, x, y, z, b);
        output.close();

        std::cout << "���������� ���� ������ �� �����: output.txt" << std::endl;
    }
    return 0;
}
