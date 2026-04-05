#pragma once
#include "dot.h"
#include <iostream>
using namespace std;

class Triangle
{
private:
    Dot* pointA;  // Указатели на точки (агрегация)
    Dot* pointB;
    Dot* pointC;

public:
    // Конструктор (точки создаются вне треугольника)
    Triangle(Dot* a, Dot* b, Dot* c);

    // Деструктор (не удаляет точки, так как не владеет ими)
    ~Triangle();

    // Методы
    void printSides();      // Вывод длин сторон
    double getPerimeter();  // Расчет периметра
    double getArea();       // Расчет площади

    // Дополнительные методы
    void displayInfo();     // Вывод всей информации
};