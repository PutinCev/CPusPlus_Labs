#include <iostream>
using namespace std;
#include<cmath>;
#include <windows.h>


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "Определим принадлежит ли заданная точки заданной фигуре на плоскости. Пожалуйста введите значение радиуса окружности:\n";
    int r;
    cin >> r;
    cout << "Введите координату X точки на площади:\n";
    int x;
    cin >> x;

    cout << "Введите координату Y точки на площади:\n";
    int y;
    cin >> y;

    if (x * x + y * y < r * r && y > 0)
        cout << "внутри";
    else if (x * x + y * y > r * r || y < 0)
        cout << "снаружи";
    else
        cout << "на границе";
}