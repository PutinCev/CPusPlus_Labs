#include <iostream>
#include <windows.h>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    // Конструктор по умолчанию
    Distance() : feet(0), inches(0.0) {}

    // Конструктор с двумя параметрами
    Distance(int ft, float in) : feet(ft), inches(in) {}

    // Ввод расстояния
    void getdist()
    {
        cout << "\nВведите число футов: ";
        cin >> feet;
        cout << "Введите число дюймов: ";
        cin >> inches;
    }

    // Перегрузка оператора сложения
    Distance operator+ (const Distance& d2) const
    {
        int f = feet + d2.feet;
        float i = inches + d2.inches;
        if (i >= 12.0)
        {
            i -= 12.0;
            f++;
        }
        return Distance(f, i);
    }

    // Перегрузка оператора вычитания (дружественная функция)
    friend Distance operator- (const Distance& d1, const Distance& d2);

    // Перегрузка оператора потокового вывода
    friend ostream& operator<< (ostream& out, const Distance& dist);
};

// Оператор вычитания с проверкой
Distance operator- (const Distance& d1, const Distance& d2)
{
    // Проверка: не допускаем вычитания большего из меньшего
    float total1 = d1.feet * 12.0 + d1.inches;
    float total2 = d2.feet * 12.0 + d2.inches;

    if (total1 < total2)
    {
        cout << "\nОШИБКА: Нельзя вычитать большее расстояние из меньшего!" << endl;
        return Distance(0, 0.0);
    }

    int f = d1.feet - d2.feet;
    float i = d1.inches - d2.inches;

    if (i < 0.0)
    {
        i += 12.0;
        f--;
    }

    return Distance(f, i);
}

// Оператор потокового вывода
ostream& operator<< (ostream& out, const Distance& dist)
{
    out << dist.feet << "\'-" << dist.inches << "\"";
    return out;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Distance dist1, dist2, dist3, dist4;

    // Ввод расстояний
    cout << "Введите первое расстояние:";
    dist1.getdist();

    cout << "\nВведите второе расстояние:";
    dist2.getdist();

    // Сложение
    dist3 = dist1 + dist2;

    // Цепочка сложения
    dist4 = dist1 + dist2 + dist3;

    // Вывод результатов с помощью перегруженного оператора <<
    cout << "\n\nРезультаты:" << endl;
    cout << "dist1 = " << dist1 << endl;
    cout << "dist2 = " << dist2 << endl;
    cout << "dist3 = dist1 + dist2 = " << dist3 << endl;
    cout << "dist4 = dist1 + dist2 + dist3 = " << dist4 << endl;

    // Вычитание (с проверкой внутри оператора)
    cout << "\nВычитание:" << endl;
    Distance dist5 = dist1 - dist2;
    cout << "dist1 - dist2 = " << dist5 << endl;

    return 0;
}