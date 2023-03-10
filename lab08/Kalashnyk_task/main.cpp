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
        << " | ќлександр  алашник,  ÷Ќ“”, sa2005@ukr.net| \n"
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
    cout << "X в дес€тков≥й систем≥ численн€: " << dec << x << endl;
    cout << "X в ш≥стнадц€тков≥й систем≥ численн€: " << hex << uppercase << x << endl;
    cout << "___________________________________________"<< endl;
    cout << "___________________________________________"<< endl;
    cout << "Y в дес€тков≥й систем≥ численн€: " << dec << y << endl;
    cout << "Y в ш≥стнадц€тков≥й систем≥ численн€: " << hex << uppercase << y << endl;
    cout << "___________________________________________"<< endl;
    cout << "___________________________________________"<< endl;
    cout << "Z в дес€тков≥й систем≥ численн€: " << dec << z << endl;
    cout << "Z в ш≥стнадц€тков≥й систем≥ численн€: " << hex << uppercase << z << endl;
    cout << "___________________________________________"<< endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SoftwareDevelop();
    int a = 0; int b = 0; int x, y, z = 0;
    cout << "\n\n\n___________________________________________"<< endl;
    cout << "\n¬вед≥ть числа а ≥ b дл€ перев≥рки нер≥вност≥ \nякщо нер≥вн≥сть a+1<=b в≥рна то виводить (1), €кщо н≥ то (0)";
    cout << "\n___________________________________________"<< endl;
    cout << "\n¬вед≥ть число а: ";
    cin >> a;
    cout << "¬вед≥ть число b: ";
    cin >> b;
    if(BoolExpression(a, b) == true)
        cout << "\n" <<1;
    else
        cout << "\n" <<0;
    cout << "\n\n\n___________________________________________"<< endl;
    cout << "\n¬вед≥ть числа x, y та z дл€ переводу в дес€ткову та ш≥стнадц€ткову систему числен€€" << endl;
    cout << "\n___________________________________________"<< endl;
    cout << "\n¬вед≥ть число X: ";
    cin >> x;
    cout << "¬вед≥ть число Y: ";
    cin >> y;
    cout << "¬вед≥ть число Z: ";
    cin >> z;

    HexDecimal(x, y, z);
    cout << endl;

    return 0;
}
