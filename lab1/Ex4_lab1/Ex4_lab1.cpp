
#include <iostream>
using namespace std;
#include<cmath>;
#include <windows.h>


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "Здравствуйте! Давайте посчитаем площадь равностороннего треугольника. Пожалуйста введите значение периметра:\n";
    double p;
    cin >> p;
    double a = p / 3;
    double s = sqrt(p/2 * pow((p/2 - a), 3));
    cout.precision(4);
    cout << "Сторона \t Площадь\n";
    cout << a << "\t \t"<< s;
}

