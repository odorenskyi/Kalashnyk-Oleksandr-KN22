#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <windows.h>
#include "..\struct_type_project13.h"



void registry_from_file(Subject subject, std::vector<Subject>& registry)
{
    std::ifstream input("register.data");
    if (input.is_open())
    {
        while (input >> subject.code)
        {
            input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(input, subject.fullName);
            std::getline(input, subject.shortName);
            std::getline(input, subject.fullNameEng);
            std::getline(input, subject.ownershipForm);
            std::getline(input, subject.governingBody);
            std::getline(input, subject.head);
            std::getline(input, subject.location);
            std::getline(input, subject.contact);
            std::getline(input, subject.email);
            std::getline(input, subject.website);
            std::string hasCrimeaUkraineCenterInput;
            std::getline(input, hasCrimeaUkraineCenterInput);
            subject.hasCrimeaUkraineCenter = (hasCrimeaUkraineCenterInput == "���");
            std::string hasDonbasUkraineCenterInput;
            std::getline(input, hasDonbasUkraineCenterInput);
            subject.hasDonbasUkraineCenter = (hasDonbasUkraineCenterInput == "���");
            std::string hasMilitaryDepartmentInput;
            std::getline(input, hasMilitaryDepartmentInput);
            subject.hasMilitaryDepartment = (hasMilitaryDepartmentInput == "���");
            input >> subject.foundationYear;
            input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            registry.push_back(subject);
        }

        input.close();
    }
    else
    {
        std::ofstream registry("register.data");
        registry.close();
    }
}

void printRegistry(const std::vector<Subject>& registry, std::ostream& output)
{
    if(registry.size() != 0)
    {
        output << "\t\t\t\t���� ����� ���'���� ������� ��������:" << std::endl;

        for (const auto& subject : registry) {
            output << "\n��� ������� � �����: " << subject.code << std::endl;
            output << "����� ������������: " << subject.fullName << std::endl;
            output << "������ ���ί ��²�� " << subject.shortName << std::endl;
            output << "����� ������������ (����.): " << subject.fullNameEng << std::endl;
            output << "����� ��������: " << subject.ownershipForm << std::endl;
            output << "������������ ������, �� ����� ��������� ����� �������� ������ �����: " << subject.governingBody << std::endl;
            output << "������������ ������, �������, ��'�, �� ������� �������� ������� �����: " << subject.head << std::endl;
            output << "̳�������������� (�������� ������): " << subject.location << std::endl;
            output << "������� / ����: " << subject.contact << std::endl;
            output << "���������� �����: " << subject.email << std::endl;
            output << "���-����: " << subject.website << std::endl;
            output << "�� �����-������: " << (subject.hasCrimeaUkraineCenter ? "���" : "�") << std::endl;
            output << "�� �������-������: " << (subject.hasDonbasUkraineCenter ? "���" : "�") << std::endl;
            output << "³������� �������: " << (subject.hasMilitaryDepartment ? "���" : "�") << std::endl;
            output << "г� ����������: " << subject.foundationYear << std::endl;
            output << std::endl;
        }

        std::cout << "____________________________________________" << std::endl;
        std::cout << "\n�������� �������� ������." << std::endl;
    }
    else
    {
        std::cout << "� ����� �� �� �� ������." << std::endl;
    }
}

void addRecord(std::vector<Subject>& registry)
{
    Subject subject;
    std::cout << "��� ������� � �����: ";
    std::cin >> subject.code;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\n����� ������������: ";
    std::getline(std::cin, subject.fullName);

    std::cout << "\n������� �����: ";
    std::getline(std::cin, subject.shortName);

    std::cout << "\n����� ������������ (����.): ";
    std::getline(std::cin, subject.fullNameEng);

    std::cout << "\n����� ��������: ";
    std::getline(std::cin, subject.ownershipForm);

    std::cout << "\n������������ ������, �� ����� ��������� ����� �������� ������ �����: ";
    std::getline(std::cin, subject.governingBody);

    std::cout << "\n������������ ������, �������, ��'�, �� ������� �������� ������� �����: ";
    std::getline(std::cin, subject.head);

    std::cout << "\n̳�������������� (�������� ������): ";
    std::getline(std::cin, subject.location);

    std::cout << "\n������� / ����: ";
    std::getline(std::cin, subject.contact);

    std::cout << "\n���������� �����: ";
    std::getline(std::cin, subject.email);

    std::cout << "\n���-����: ";
    std::getline(std::cin, subject.website);

    std::cout << "\n�� �����-������ (���/�): ";
    std::string hasCrimeaUkraineCenterInput;
    std::getline(std::cin, hasCrimeaUkraineCenterInput);
    subject.hasCrimeaUkraineCenter = (hasCrimeaUkraineCenterInput == "���");

    std::cout << "\n�� �������-������ (���/�): ";
    std::string hasDonbasUkraineCenterInput;
    std::getline(std::cin, hasDonbasUkraineCenterInput);
    subject.hasDonbasUkraineCenter = (hasDonbasUkraineCenterInput == "���");

    std::cout << "\n³������� ������� (���/�): ";
    std::string hasMilitaryDepartmentInput;
    std::getline(std::cin, hasMilitaryDepartmentInput);
    subject.hasMilitaryDepartment = (hasMilitaryDepartmentInput == "���");

    std::cout << "\nг� ����������: ";
    std::cin >> subject.foundationYear;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n____________________________________________" << std::endl;

    registry.push_back(subject);
}

void findSubject(std::vector<Subject>& registry, std::string code)
{
    bool found = false;

    for (int i = 0; i < registry.size(); i++)
    {
        if (registry[i].code == code)
        {
            std::cout << "\n��� ������� � �����: " << registry[i].code << std::endl;
            std::cout << "����� ������������: " << registry[i].fullName << std::endl;
            std::cout << "������� �����: " << registry[i].shortName << std::endl;
            std::cout << "����� ������������ (����.): " << registry[i].fullNameEng << std::endl;
            std::cout << "����� ��������: " << registry[i].ownershipForm << std::endl;
            std::cout << "������������ ������, �� ����� ��������� ����� �������� ������ �����: " << registry[i].governingBody << std::endl;
            std::cout << "������������ ������, �������, ��'�, �� ������� �������� ������� �����: " << registry[i].head << std::endl;
            std::cout << "̳�������������� (�������� ������): " << registry[i].location << std::endl;
            std::cout << "������� / ����: " << registry[i].contact << std::endl;
            std::cout << "���������� �����: " << registry[i].email << std::endl;
            std::cout << "���-����: " << registry[i].website << std::endl;
            std::cout << "�� �����-������: " << (registry[i].hasCrimeaUkraineCenter ? "���" : "�") << std::endl;
            std::cout << "�� �������-������: " << (registry[i].hasDonbasUkraineCenter ? "���" : "�") << std::endl;
            std::cout << "³������� �������: " << (registry[i].hasMilitaryDepartment ? "���" : "�") << std::endl;
            std::cout << "г� ����������: " << registry[i].foundationYear << std::endl;

            found = true;
        }
    }

    if(!found)
    {
        std::cout << "____________________________________________" << std::endl;
        std::cout << "\n����� � ����� ����� ������� �� ��������� � �����." << std::endl;
    }
}

void removeSubject(std::vector<Subject>& registry, std::string code)
{
    bool found = false;

    for (int i = 0; i < registry.size(); i++)
    {
        if (registry[i].code == code)
        {
            registry.erase(registry.begin() + i);

            found = true;
            std::cout << "____________________________________________" << std::endl;
            std::cout << "\n����� ��� ������ ��������� �� ��������� � ������." << std::endl;
        }
    }

    if(!found)
    {
        std::cout << "____________________________________________" << std::endl;
        std::cout << "\n����� � ����� ����� ������� �� ��������� � �����." << std::endl;
    }
}

void endWork(std::vector<Subject>& registry)
{
    std::ofstream output("register.data");

    if(output.is_open())
    {
        for(int i = 0; i < registry.size(); i++)
        {
            output << registry[i].code << std::endl;
            output << registry[i].fullName << std::endl;
            output << registry[i].shortName << std::endl;
            output << registry[i].fullNameEng << std::endl;
            output << registry[i].ownershipForm << std::endl;
            output << registry[i].governingBody << std::endl;
            output << registry[i].head << std::endl;
            output << registry[i].location << std::endl;
            output << registry[i].contact << std::endl;
            output << registry[i].email << std::endl;
            output << registry[i].website << std::endl;
            output << (registry[i].hasCrimeaUkraineCenter ? "���" : "�") << std::endl;
            output << (registry[i].hasDonbasUkraineCenter ? "���" : "�") << std::endl;
            output << (registry[i].hasMilitaryDepartment ? "���" : "�") << std::endl;
            output << registry[i].foundationYear << std::endl;
        }

    }
    else
    {
        std::cout << "�� ������� ������� ������ ��� ������������ �����." << std::endl;
    }

    output.close();
    std::cout << "�������� ��������� ������." << std::endl;

}

int main() {
    SetConsoleCP(1251); SetConsoleOutputCP(1251);

    std::vector<Subject> registry;
    Subject subject;

    registry_from_file(subject, registry);

    int choice;
    do
    {
        std::cout << "____________________________________________" << std::endl;
        std::cout << "\n������ �����:" << std::endl;
        std::cout << "____________________________________________" << std::endl;
        std::cout << "\n1. ������� ����� �� �����" << std::endl;
        std::cout << "2. �������� ����� � ����" << std::endl;
        std::cout << "3. ������ ����� ����� �� ������" << std::endl;
        std::cout << "4. ����� ������ �� ����� �������" << std::endl;
        std::cout << "5. ��������� ������ � ������ �� ����� �������" << std::endl;
        std::cout << "0. ��������� ������ ��������" << std::endl;
        std::cout << "____________________________________________" << std::endl;
        std::cout << "\n��� ����: ";
        std::cin >> choice;
        std::cout << "____________________________________________" << std::endl << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
            case 1:
                printRegistry(registry, std::cout);
                break;
            case 2:
            {
                std::string file;

                std::cout << "������ ����� ����� � ���� ������� �������� �����: ";
                std::cin >> file;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::ofstream output(file);

                printRegistry(registry, output);

                output.close();
                break;
            }
            case 3:
                addRecord(registry);
                std::cout << "\n����� ����� ��� ������� �� ������." << std::endl;
                break;
            case 4:
            {
                std::string code;

                std::cout << "������ ��� ������� � �����: ";
                std::cin >> code;

                findSubject(registry, code);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                break;
            }
            case 5:
            {
                std::string code;

                std::cout << "������ ��� ������� � �����: ";
                std::cin >> code;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                removeSubject(registry, code);
                break;
            }
            case 0:
                endWork(registry);
                break;
            default:
                std::cout << "������������ ����. ���� �����, ��������� �� ���." << std::endl;
                break;
        }

        std::cout << "____________________________________________" << std::endl;
        std::cout << "\n��������� ����-��� ������ ��� ���������� ���!" << std::endl;;
        std::cin.get();

        std::system("cls");

    } while (choice != 0);

    return 0;
}
