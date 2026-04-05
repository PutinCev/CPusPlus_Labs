#include <iostream>
#include <windows.h>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;
    const float MTF;  // Коэффициент перевода метров в футы

public:
    // Конструкторы
    Distance() : feet(0), inches(0.0), MTF(3.280833F) {}

    Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) {}

    // Конструктор для преобразования из float (метры) в Distance
    Distance(float meters) : MTF(3.280833F)
    {
        float fltfeet = MTF * meters;
        feet = int(fltfeet);
        inches = 12 * (fltfeet - feet);
    }

    // Оператор преобразования Distance в float
    operator float() const
    {
        float fracfeet = inches / 12;
        fracfeet += static_cast<float>(feet);
        return fracfeet / MTF;
    }

    // Distance + Distance
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

    // Distance + float
    Distance operator+ (float meters) const
    {
        return *this + Distance(meters);
    }

    // Distance - Distance
    Distance operator- (const Distance& d2) const
    {
        float total1 = feet * 12.0 + inches;
        float total2 = d2.feet * 12.0 + d2.inches;

        if (total1 < total2)
        {
            cout << "\nОШИБКА: Нельзя вычитать большее расстояние из меньшего!" << endl;
            return Distance(0, 0.0);
        }

        int f = feet - d2.feet;
        float i = inches - d2.inches;

        if (i < 0.0)
        {
            i += 12.0;
            f--;
        }

        return Distance(f, i);
    }

    // Distance - float
    Distance operator- (float meters) const
    {
        return *this - Distance(meters);
    }

    // Дружественные функции для float + Distance и float - Distance
    friend Distance operator+ (float meters, const Distance& d);
    friend Distance operator- (float meters, const Distance& d);

    // Вывод
    void showdist()
    {
        cout << feet << "\'-" << inches << "\"";
    }
};

// float + Distance
Distance operator+ (float meters, const Distance& d)
{
    return Distance(meters) + d;
}

// float - Distance
Distance operator- (float meters, const Distance& d)
{
    Distance temp(meters);

    float total1 = temp.feet * 12.0 + temp.inches;
    float total2 = d.feet * 12.0 + d.inches;

    if (total1 < total2)
    {
        cout << "\nОШИБКА: Нельзя вычитать большее расстояние из меньшего!" << endl;
        return Distance(0, 0.0);
    }

    return temp - d;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Distance dist1(5, 6.0);  // 5 футов 6 дюймов
    Distance dist2(3, 8.0);  // 3 фута 8 дюймов

    cout << "dist1 = ";
    dist1.showdist();
    cout << endl;

    cout << "dist2 = ";
    dist2.showdist();
    cout << endl;

    // Distance + Distance
    Distance dist3 = dist1 + dist2;
    cout << "\ndist1 + dist2 = ";
    dist3.showdist();
    cout << endl;

    // Distance + float
    Distance dist4 = dist1 + 2.5F;
    cout << "\ndist1 + 2.5 метра = ";
    dist4.showdist();
    cout << endl;

    // float + Distance
    Distance dist5 = 2.5F + dist1;
    cout << "2.5 метра + dist1 = ";
    dist5.showdist();
    cout << endl;

    // Distance - Distance
    Distance dist6 = dist1 - dist2;
    cout << "\ndist1 - dist2 = ";
    dist6.showdist();
    cout << endl;

    // Distance - float
    Distance dist7 = dist1 - 1.2F;
    cout << "dist1 - 1.2 метра = ";
    dist7.showdist();
    cout << endl;

    // float - Distance
    Distance dist8 = 5.0F - dist2;
    cout << "5.0 метров - dist2 = ";
    dist8.showdist();
    cout << endl;

    return 0;
}