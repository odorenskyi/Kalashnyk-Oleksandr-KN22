#include <iostream>
#include <windows.h>
#include <math.h>
#include <locale.h>

using namespace std;

void SoftwareDevelop(void){
    using namespace std;
    system("chcp 1251");

    cout << "\n -------------------------------------------- \n"
        << " | Olexandr Kalashnyk, CUNTU, sa2005@ukr.net| \n"
        << " | ��������� ��������,  ����, sa2005@ukr.net| \n"
        << " ----------- �All Rights Reserved -----------\n";
}



bool BoolExpression(int a, int b){
    if (a+1<= b)
        return true;
    else
        return false;
}

void HexDecimal(int x, int y, int z)
{
    cout << "___________________________________________"<< endl;
    cout << "X � ��������� ������ ��������: " << dec << x << endl;
    cout << "X � �������������� ������ ��������: " << hex << uppercase << x << endl;
    cout << "___________________________________________"<< endl;
    cout << "___________________________________________"<< endl;
    cout << "Y � ��������� ������ ��������: " << dec << y << endl;
    cout << "Y � �������������� ������ ��������: " << hex << uppercase << y << endl;
    cout << "___________________________________________"<< endl;
    cout << "___________________________________________"<< endl;
    cout << "Z � ��������� ������ ��������: " << dec << z << endl;
    cout << "Z � �������������� ������ ��������: " << hex << uppercase << z << endl;
    cout << "___________________________________________"<< endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SoftwareDevelop();
    int a = 0; int b = 0; int x, y, z = 0;
    cout << "\n\n\n___________________________________________"<< endl;
    cout << "\n������ ����� � � b ��� �������� �������� \n���� �������� a+1<=b ���� �� �������� (1), ���� � �� (0)";
    cout << "\n___________________________________________"<< endl;
    cout << "\n������ ����� �: ";
    cin >> a;
    cout << "������ ����� b: ";
    cin >> b;
    if(BoolExpression(a, b) == true)
        cout << "\n" <<1;
    else
        cout << "\n" <<0;
    cout << "\n\n\n___________________________________________"<< endl;
    cout << "\n������ ����� x, y �� z ��� �������� � ��������� �� �������������� ������� ��������" << endl;
    cout << "\n___________________________________________"<< endl;
    cout << "\n������ ����� X: ";
    cin >> x;
    cout << "������ ����� Y: ";
    cin >> y;
    cout << "������ ����� Z: ";
    cin >> z;

    HexDecimal(x, y, z);
    cout << endl;

    return 0;
}
