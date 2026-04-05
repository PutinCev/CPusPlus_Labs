#include "triangle.h"
#include <cmath>
#include <iomanip>

// Конструктор - точки передаются извне
Triangle::Triangle(Dot* a, Dot* b, Dot* c)
    : pointA(a), pointB(b), pointC(c)
{
}

// Деструктор - не удаляет точки, так как не владеет ими
Triangle::~Triangle()
{
    // Точки не удаляются, они могут существовать отдельно
}

void Triangle::printSides()
{
    double sideAB = pointA->distanceTo(*pointB);
    double sideBC = pointB->distanceTo(*pointC);
    double sideCA = pointC->distanceTo(*pointA);

    cout << fixed << setprecision(2);
    cout << "Длины сторон треугольника:" << endl;
    cout << "AB = " << sideAB << endl;
    cout << "BC = " << sideBC << endl;
    cout << "CA = " << sideCA << endl;
}

double Triangle::getPerimeter()
{
    double sideAB = pointA->distanceTo(*pointB);
    double sideBC = pointB->distanceTo(*pointC);
    double sideCA = pointC->distanceTo(*pointA);

    return sideAB + sideBC + sideCA;
}

double Triangle::getArea()
{
    double sideAB = pointA->distanceTo(*pointB);
    double sideBC = pointB->distanceTo(*pointC);
    double sideCA = pointC->distanceTo(*pointA);

    // Формула Герона
    double p = getPerimeter() / 2;
    return sqrt(p * (p - sideAB) * (p - sideBC) * (p - sideCA));
}

void Triangle::displayInfo()
{
    cout << "\n=== Информация о треугольнике (агрегация) ===" << endl;
    cout << "Координаты вершин:" << endl;
    cout << "A(" << pointA->getX() << ", " << pointA->getY() << ")" << endl;
    cout << "B(" << pointB->getX() << ", " << pointB->getY() << ")" << endl;
    cout << "C(" << pointC->getX() << ", " << pointC->getY() << ")" << endl;

    printSides();
    cout << "Периметр: " << fixed << setprecision(2) << getPerimeter() << endl;
    cout << "Площадь: " << fixed << setprecision(2) << getArea() << endl;
}