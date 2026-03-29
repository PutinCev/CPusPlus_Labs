#include <iostream>
#include <windows.h>
using namespace std;

struct Distance
{
    int feet;
    double inches;

    void Normalize()
    {
        if (inches >= 12.0)
        {
            int addFeet = static_cast<int>(inches) / 12;
            feet += addFeet;
            inches -= addFeet * 12.0;
        }
    }

    void ShowDist()
    {
        cout << feet << "\'-" << inches << "\"\n";
    }
};

Distance AddDist(const Distance& d1, const Distance& d2)
{
    Distance d;
    d.feet = d1.feet + d2.feet;
    d.inches = d1.inches + d2.inches;
    d.Normalize();
    return d;
}

Distance InputDist()
{
    Distance d;
    cout << "\nВведите число футов: ";
    cin >> d.feet;
    cout << "Введите число дюймов: ";
    cin >> d.inches;

    // Нормализуем введенные значения
    d.Normalize();

    return d;
}

void ShowDist(Distance d)
{
    cout << d.feet << "\'-" << d.inches << "\"\n";
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Distance sumDist;
    sumDist.feet = 0;
    sumDist.inches = 0;

    int n;
    cout << "Введите размер массива расстояний: ";
    cin >> n;

    Distance* masDist = new Distance[n];

    cout << "\n--- Ввод расстояний ---\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nЭлемент " << i + 1 << ":";
        masDist[i] = InputDist();
    }

    
    cout << "\n--- Введенные расстояния ---\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Элемент " << i + 1 << ": ";
        ShowDist(masDist[i]);
        sumDist = AddDist(sumDist, masDist[i]);
    }

    cout << "\n--- Сумма введенных в массив расстояний ---\n";
    ShowDist(sumDist);

    delete[] masDist;

    return 0;
}