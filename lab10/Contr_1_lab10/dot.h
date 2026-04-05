#pragma once
#include <cmath>
using namespace std;

class Dot
{
private:
    double x;
    double y;

public:
    Dot();
    Dot(double x, double y);

    double distanceTo(Dot point);

    // Геттеры
    double getX() const { return x; }
    double getY() const { return y; }

    // Сеттеры
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
};