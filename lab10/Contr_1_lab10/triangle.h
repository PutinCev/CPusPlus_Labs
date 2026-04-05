#pragma once
#include "dot.h"
#include <iostream>
using namespace std;

class Triangle
{
private:
    Dot pointA;  // Точки как поля (композиция)
    Dot pointB;
    Dot pointC;

public:
    // Конструктор (точки создаются внутри треугольника)
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3);

    // Методы
    void printSides();      // Вывод длин сторон
    double getPerimeter();  // Расчет периметра
    double getArea();       // Расчет площади

    // Дополнительные методы
    void displayInfo();     // Вывод всей информации
};