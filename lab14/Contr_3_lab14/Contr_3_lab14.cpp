#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// Шаблонная функция maxOfTwo
template<typename T>
T maxOfTwo(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

// Пользовательский класс Person
class Person
{
private:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    // Перегрузка оператора <
    bool operator<(const Person& other) const
    {
        return age < other.age;
    }

    // Перегрузка оператора > (нужен для maxOfTwo)
    bool operator>(const Person& other) const
    {
        return age > other.age;
    }

    // Для вывода
    friend ostream& operator<<(ostream& out, const Person& p)
    {
        out << p.name << "(" << p.age << ")";
        return out;
    }
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // int
    cout << "max(10, 25) = " << maxOfTwo(10, 25) << endl;

    // double
    cout << "max(3.14, 2.71) = " << maxOfTwo(3.14, 2.71) << endl;

    // Person
    Person p1("Иван", 25);
    Person p2("Петр", 30);
    cout << "max(Иван(25), Петр(30)) = " << maxOfTwo(p1, p2) << endl;

    return 0;
}