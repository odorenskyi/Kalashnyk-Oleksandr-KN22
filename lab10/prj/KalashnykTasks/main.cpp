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
    // Ініціалізуємо генератор випадкових чисел за поточним часом
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Генеруємо випадкове число у заданому діапазоні
    int randomNumber = min + (std::rand() % (max - min + 1));

    return randomNumber;
}

void writeAuthorInfo(std::ofstream& file) {
    file << "Автор: Олександр" << std::endl;
    file << "Установа/організація: ЦНТУ" << std::endl;
    file << "Місто: Кропивницький" << std::endl;
    file << "Країна: Україна" << std::endl;
    file << "Рік розробки: 2023" << std::endl;
    file << "Розробник модуля: Калашник О.В." << std::endl;
    file << "Випадкове число: " << rand()%91+10 << std::endl;
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
    file << "Дату дозапису інформації: " << date << std::endl;
}

void appendResults(std::ofstream& file, float x, float y, float z, double b) {
    file << "Калашник" << std::endl;
    file << "Результати виконання функцій із заголовкового файлу Modules:" << std::endl;
    file << "s_calculation(" << x << ", " << y << ", " << z << ") = " << s_calculation(x, y, z) << std::endl;
    std::string binaryNum = DecimalToBinary(b);
    file << "Число " << y << " в двійковому коді: " << binaryNum << std::endl;
}

int main() {
    char *locale = setlocale(LC_ALL, "");
    int choice;
    int randomNumber = generateRandomNumber(10, 100);
    std::cout << "Виберіть завдання:" << std::endl;
    std::cout << "1. Завдання 10.1" << std::endl;
    std::cout << "2. Завдання 10.2" << std::endl;
    std::cout << "3. Завдання 10.3" << std::endl;
    std::cin >> choice;

    if (choice == 1) {
        std::ifstream input("input.txt");
        std::ofstream output("output.txt");

        if (!input || !output) {
            std::cout << "Помилка відкриття файлу!" << std::endl;
            return 1;
        }

        writeAuthorInfo(output);

        std::string line;
        while (std::getline(input, line)) {
            bool punctuationMistakes = hasPunctuationMistakes(line);
            output << "Текст має пунктуаційні помилки: " << (punctuationMistakes ? "Так" : "Ні") << std::endl;
        }

        input.close();
        output.close();

        std::cout << "Результати було записано у файл: output.txt" << std::endl;
    }

    // Завдання 10.2
    else if (choice == 2) {
        std::ofstream output("output.txt", std::ios::app);
        if (!output) {
            std::cout << "Помилка відкриття файлу!" << std::endl;
            return 1;
        }
        appendDate(output);
        output.close();

        std::cout << "Результати було додано до файлу: output.txt" << std::endl;
    }

    else if (choice == 3) {
        float x, y, z;
        double b;

        std::cout << "Введіть значення x: ";
        std::cin >> x;
        std::cout << "Введіть значення y: ";
        std::cin >> y;
        std::cout << "Введіть значення z: ";
        std::cin >> z;
        std::cout << "Введіть значення b: ";
        std::cin >> b;
        std::ofstream output("output.txt", std::ios::app);
        if (!output) {
            std::cout << "Помилка відкриття файлу!" << std::endl;
            return 1;
        }
        appendResults(output, x, y, z, b);
        output.close();

        std::cout << "Результати було додано до файлу: output.txt" << std::endl;
    }
    return 0;
}
