#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <windows.h>
using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    // Конструктор с параметрами
    Point(double xCoord = 0, double yCoord = 0) : x(xCoord), y(yCoord) {}

    // Функция расчета расстояния до центра координат
    double distanceToOrigin() const
    {
        return sqrt(x * x + y * y);
    }

    // Перегрузка оператора < (сравнение по расстоянию до центра)
    bool operator<(const Point& other) const
    {
        return distanceToOrigin() < other.distanceToOrigin();
    }

    // Дружественная функция для перегрузки оператора <<
    friend ostream& operator<<(ostream& out, const Point& point);
};

// Перегрузка оператора << для вывода в поток
ostream& operator<<(ostream& out, const Point& point)
{
    out << "Point(" << point.x << ", " << point.y << ")";
    return out;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    vector<Point> v;
    v.push_back(Point(1, 2));
    v.push_back(Point(10, 12));
    v.push_back(Point(21, 7));
    v.push_back(Point(4, 8));

    cout << "Исходный порядок:" << endl;
    for (const auto& point : v)
    {
        cout << point << '\n';
    }

    // Сортировка вектора (требуется перегрузка оператора <)
    sort(v.begin(), v.end());

    cout << "\nОтсортированный порядок (по расстоянию до центра):" << endl;
    for (const auto& point : v)
    {
        cout << point << '\n';
    }

    return 0;
}