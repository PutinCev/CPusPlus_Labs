#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

class Triangle
{
public:
    // Класс исключения
    class InvalidTriangleError
    {
    public:
        string origin;
        double side_a, side_b, side_c;
        string message;

        InvalidTriangleError(string or_, double a, double b, double c, string msg)
            : origin(or_), side_a(a), side_b(b), side_c(c), message(msg) {
        }

        void printError() const
        {
            cout << "\nОШИБКА в " << origin << ": " << message << endl;
            cout << "Стороны: " << side_a << ", " << side_b << ", " << side_c << endl;
        }
    };

    // Конструктор с проверкой
    Triangle(double a, double b, double c)
    {
        // Проверка на допустимость сторон
        if (a <= 0 || b <= 0 || c <= 0) {
            throw InvalidTriangleError("Triangle::Triangle", a, b, c,
                "Стороны должны быть положительными числами!");
        }

        if (a >= b + c || b >= a + c || c >= a + b) {
            throw InvalidTriangleError("Triangle::Triangle", a, b, c,
                "Стороны не образуют треугольник (нарушено неравенство треугольника)!");
        }

        side_a = a;
        side_b = b;
        side_c = c;
    }

    // Вычисление площади по формуле Герона
    double getArea() const
    {
        double p = (side_a + side_b + side_c) / 2.0;
        return sqrt(p * (p - side_a) * (p - side_b) * (p - side_c));
    }

    // Вывод сторон
    void display() const
    {
        cout << "Стороны треугольника: " << side_a << ", " << side_b << ", " << side_c << endl;
        cout << "Площадь: " << getArea() << endl;
    }

private:
    double side_a, side_b, side_c;
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double a, b, c;

    cout << "Введите три стороны треугольника:" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    try
    {
        Triangle t(a, b, c);
        t.display();
    }
    catch (Triangle::InvalidTriangleError& ex)
    {
        ex.printError();
        return 1;
    }

    return 0;
}