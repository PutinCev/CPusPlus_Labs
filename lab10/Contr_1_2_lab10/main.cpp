#include <iostream>
#include <windows.h>
#include "dot.h"
#include "triangle.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Ввод треугольника с клавиатуры (агрегация)
    cout << "\n================================================" << endl;
    cout << "   Ввод треугольника (агрегация)" << endl;
    cout << "================================================" << endl;

    double x1, y1, x2, y2, x3, y3;

    cout << "Введите координаты первой вершины (x y): ";
    cin >> x1 >> y1;
    cout << "Введите координаты второй вершины (x y): ";
    cin >> x2 >> y2;
    cout << "Введите координаты третьей вершины (x y): ";
    cin >> x3 >> y3;

    Dot* userA = new Dot(x1, y1);
    Dot* userB = new Dot(x2, y2);
    Dot* userC = new Dot(x3, y3);

    Triangle* t3 = new Triangle(userA, userB, userC);
    t3->displayInfo();

    // Освобождение памяти (точки удаляются отдельно)

    delete userA; delete userB; delete userC;
    delete t3;

    return 0;
}