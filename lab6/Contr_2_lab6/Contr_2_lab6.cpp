#include <iostream>
#include<cmath>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const int N = 10;

    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };

    string line;
    ofstream out("arr.txt");  // создаем файл poem.txt

    if (!out) {
        cout << "Ошибка создания файла!" << endl;
        return 1;
    }

    for (int i : a) {
        out << i << '\t';
    }

    cout << "\nНачальный массив сохранен в файл arr.txt\n";
    out << endl;


    int min = 0; // для записи минимального значения
    int buf = 0; // для обмена значениями
    for (int i = 0; i < N; i++)
    {
        min = i; // номер текущей ячейки, как ячейки с минимальным значением
        // в цикле найдем реальный номер ячейки с минимальным значением
        for (int j = i + 1; j < N; j++) {
            min = (a[j] < a[min]) ? j : min;
        }

        // перестановка этого элемента, поменяв его местами с текущим
        if (i != min)
        {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }
    for (int i : a) {
        out << i << '\t';
    }

    out.close();
    cout << "\nСортированный массив сохранен в файл arr.txt\n";

}