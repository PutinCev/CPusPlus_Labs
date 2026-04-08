#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

// Абстрактный класс Vehicle
class Vehicle
{
public:
    virtual void move() const = 0;
    virtual string type() const = 0;
    virtual ~Vehicle() {}
};

// Производный класс Car
class Car : public Vehicle
{
public:
    void move() const override
    {
        cout << "Car is driving on the road." << endl;
    }

    string type() const override
    {
        return "Car";
    }
};

// Производный класс Boat
class Boat : public Vehicle
{
public:
    void move() const override
    {
        cout << "Boat is sailing on water." << endl;
    }

    string type() const override
    {
        return "Boat";
    }
};

// Производный класс Plane
class Plane : public Vehicle
{
public:
    void move() const override
    {
        cout << "Plane is flying in the sky." << endl;
    }

    string type() const override
    {
        return "Plane";
    }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Вектор указателей на Vehicle
    vector<Vehicle*> vehicles;

    // Наполнение вектора объектами разных типов
    vehicles.push_back(new Car());
    vehicles.push_back(new Boat());
    vehicles.push_back(new Plane());

    // Вывод информации о типе и поведении каждого объекта
    cout << "=== Информация о транспортных средствах ===" << endl;

    for (const auto* v : vehicles) {
        cout << v->type() << ": ";
        v->move();
    }

    // Освобождение памяти
    for (auto* v : vehicles) {
        delete v;
    }

    return 0;
}