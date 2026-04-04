#include <iostream>
#include "Time.h"
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int h1, m1, s1;
    int h2, m2, s2;

    // Ввод первой временной точки
    cout << "*** Ввод первой временной точки ***" << endl;
    cout << "Введите часы: ";
    cin >> h1;
    cout << "Введите минуты: ";
    cin >> m1;
    cout << "Введите секунды: ";
    cin >> s1;

    // Ввод второй временной точки
    cout << "\n*** Ввод второй временной точки ***" << endl;
    cout << "Введите часы: ";
    cin >> h2;
    cout << "Введите минуты: ";
    cin >> m2;
    cout << "Введите секунды: ";
    cin >> s2;

    // 1. Создаем два инициализированных объекта
    //    (они могут быть константными, т.к. их значения не меняются)
    const Time time1(h1, m1, s1);
    const Time time2(h2, m2, s2);

    // 2. Создаем неинициализированный объект
    Time timeSum;

    // 3. Складываем два инициализированных значения
    timeSum = time1.add(time2);

    // 4. Выводим результат
    cout << "\n*** Результат ***" << endl;
    cout << "Время 1: ";
    time1.display();
    cout << endl;

    cout << "Время 2: ";
    time2.display();
    cout << endl;

    cout << "Сумма: ";
    timeSum.display();
    cout << endl;

    return 0;
}