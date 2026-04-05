#include <iostream>
#include <windows.h>
#include "triangle.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Ввод треугольника с клавиатуры
    cout << "\n================================================" << endl;
    cout << "   Ввод треугольника (композиция)" << endl;
    cout << "================================================" << endl;

    double x1, y1, x2, y2, x3, y3;

    cout << "Введите координаты первой вершины (x y): ";
    cin >> x1 >> y1;
    cout << "Введите координаты второй вершины (x y): ";
    cin >> x2 >> y2;
    cout << "Введите координаты третьей вершины (x y): ";
    cin >> x3 >> y3;

    Triangle t2(x1, y1, x2, y2, x3, y3);
    t2.displayInfo();

    return 0;
}