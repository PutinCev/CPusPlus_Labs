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
    // Конструктор по умолчанию
    Distance() : feet(0), inches(0.0), MTF(3.280833F) {}

    // Конструктор с двумя параметрами
    Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) {}

    // Конструктор для преобразования из float (метры) в Distance
    Distance(float meters) : MTF(3.280833F)
    {
        float fltfeet = MTF * meters;      // перевод в футы
        feet = int(fltfeet);                // число полных футов
        inches = 12 * (fltfeet - feet);     // остаток - это дюймы
    }

    // Оператор преобразования Distance в float (метры)
    operator float() const
    {
        float fracfeet = inches / 12;
        fracfeet += static_cast<float>(feet);
        return fracfeet / MTF;
    }

    // Ввод расстояния
    void getdist()
    {
        cout << "\nВведите число футов: ";
        cin >> feet;
        cout << "Введите число дюймов: ";
        cin >> inches;
    }

    // Вывод расстояния
    void showdist()
    {
        cout << feet << "\'-" << inches << "\"";
    }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 1. Преобразование из float в Distance (метры в футы и дюймы)
    Distance dist1 = 2.35F;  // 2.35 метра преобразуется в футы и дюймы
    cout << "2.35 метра = ";
    dist1.showdist();
    cout << endl;

    // 2. Преобразование из Distance в float (футы и дюймы в метры)
    float mtrs;

    // Явное преобразование
    mtrs = static_cast<float>(dist1);
    cout << "Обратное преобразование в метры: " << mtrs << " метров" << endl;

    // 3. Неявное преобразование
    Distance dist2(5, 6.5);  // 5 футов 6.5 дюймов
    mtrs = dist2;             // Неявное преобразование в float
    cout << "\nНеявное преобразование: ";
    dist2.showdist();
    cout << " = " << mtrs << " метров" << endl;

    // 4. Ввод расстояния от пользователя и преобразование в метры
    cout << "\nВведите расстояние для преобразования:";
    Distance dist3;
    dist3.getdist();

    mtrs = static_cast<float>(dist3);
    cout << "Введенное расстояние = " << mtrs << " метров" << endl;

    return 0;
}