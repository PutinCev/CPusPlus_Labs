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

    vector<Vehicle*> vehicles;
    int choice;

    cout << "================================================" << endl;
    cout << "   Создание транспортных средств" << endl;
    cout << "================================================" << endl;

    do {
        cout << "\nВыберите тип:" << endl;
        cout << "1 - Car" << endl;
        cout << "2 - Boat" << endl;
        cout << "3 - Plane" << endl;
        cout << "0 - Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: vehicles.push_back(new Car()); break;
        case 2: vehicles.push_back(new Boat()); break;
        case 3: vehicles.push_back(new Plane()); break;
        }
    } while (choice != 0);

    cout << "\n=== Информация о транспортных средствах ===" << endl;

    for (const auto* v : vehicles) {
        cout << v->type() << ": ";
        v->move();
    }

    for (auto* v : vehicles) {
        delete v;
    }

    return 0;
}