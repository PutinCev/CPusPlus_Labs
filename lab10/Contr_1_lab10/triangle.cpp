#include "triangle.h"
#include <cmath>
#include <iomanip>

// Конструктор - точки создаются внутри треугольника
Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
    : pointA(x1, y1), pointB(x2, y2), pointC(x3, y3)
{
}

void Triangle::printSides()
{
    double sideAB = pointA.distanceTo(pointB);
    double sideBC = pointB.distanceTo(pointC);
    double sideCA = pointC.distanceTo(pointA);

    cout << fixed << setprecision(2);
    cout << "Длины сторон треугольника:" << endl;
    cout << "AB = " << sideAB << endl;
    cout << "BC = " << sideBC << endl;
    cout << "CA = " << sideCA << endl;
}

double Triangle::getPerimeter()
{
    double sideAB = pointA.distanceTo(pointB);
    double sideBC = pointB.distanceTo(pointC);
    double sideCA = pointC.distanceTo(pointA);

    return sideAB + sideBC + sideCA;
}

double Triangle::getArea()
{
    double sideAB = pointA.distanceTo(pointB);
    double sideBC = pointB.distanceTo(pointC);
    double sideCA = pointC.distanceTo(pointA);

    // Формула Герона
    double p = getPerimeter() / 2;
    return sqrt(p * (p - sideAB) * (p - sideBC) * (p - sideCA));
}

void Triangle::displayInfo()
{
    cout << "\n=== Информация о треугольнике (композиция) ===" << endl;
    cout << "Координаты вершин:" << endl;
    cout << "A(" << pointA.getX() << ", " << pointA.getY() << ")" << endl;
    cout << "B(" << pointB.getX() << ", " << pointB.getY() << ")" << endl;
    cout << "C(" << pointC.getX() << ", " << pointC.getY() << ")" << endl;

    printSides();
    cout << "Периметр: " << fixed << setprecision(2) << getPerimeter() << endl;
    cout << "Площадь: " << fixed << setprecision(2) << getArea() << endl;
}