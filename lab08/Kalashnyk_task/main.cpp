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
        << " | Олександр Калашник,  ЦНТУ, sa2005@ukr.net| \n"
        << " ----------- ©All Rights Reserved -----------\n";
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
    cout << "X в десятковій системі числення: " << dec << x << endl;
    cout << "X в шістнадцятковій системі числення: " << hex << uppercase << x << endl;
    cout << "___________________________________________"<< endl;
    cout << "___________________________________________"<< endl;
    cout << "Y в десятковій системі числення: " << dec << y << endl;
    cout << "Y в шістнадцятковій системі числення: " << hex << uppercase << y << endl;
    cout << "___________________________________________"<< endl;
    cout << "___________________________________________"<< endl;
    cout << "Z в десятковій системі числення: " << dec << z << endl;
    cout << "Z в шістнадцятковій системі числення: " << hex << uppercase << z << endl;
    cout << "___________________________________________"<< endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SoftwareDevelop();
    int a = 0; int b = 0; int x, y, z = 0;
    cout << "\n\n\n___________________________________________"<< endl;
    cout << "\nВведіть числа а і b для перевірки нерівності \nЯкщо нерівність a+1<=b вірна то виводить (1), якщо ні то (0)";
    cout << "\n___________________________________________"<< endl;
    cout << "\nВведіть число а: ";
    cin >> a;
    cout << "Введіть число b: ";
    cin >> b;
    if(BoolExpression(a, b) == true)
        cout << "\n" <<1;
    else
        cout << "\n" <<0;
    cout << "\n\n\n___________________________________________"<< endl;
    cout << "\nВведіть числа x, y та z для переводу в десяткову та шістнадцяткову систему числення" << endl;
    cout << "\n___________________________________________"<< endl;
    cout << "\nВведіть число X: ";
    cin >> x;
    cout << "Введіть число Y: ";
    cin >> y;
    cout << "Введіть число Z: ";
    cin >> z;

    HexDecimal(x, y, z);
    cout << endl;

    return 0;
}
