#include <iostream>
#include<cmath>
#include <windows.h>
using namespace std;



int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const int n = 10;
    //Объявите массив целых чисел размером n :
    int mas[n];
    //С помощью цикла for реализуйте заполнение массива с клавиатуры :
    for (int i = 0; i < n; i++)
    {
        cout << "mas[" << i << "]=";
        cin >> mas[i];
    }
    //Определите сумму всех элементов массива :
    int s = 0;
    int otr = 0;
    int polog = 0;
    int nechet = 0;
    int chet = 0;
    int maxEl = 0;
    int minEl = 0;
    int imax = 0;
    int imin = 0;
    int prMinMax = 1;
    int prMinMaxNot0 = false;

    for (int i = 0; i < n; i++)
    {
        s += mas[i];
        if (mas[i] < 0) {
            otr += mas[i];
        }
        else
        {
            polog += mas[i];
        }

        if (mas[i]%2==0) {
            chet += mas[i];
        }
        else
        {
            nechet += mas[i];
        }

        if ((mas[i]> maxEl) or (i == 0)) {
            maxEl = mas[i];
            imax = i;
        }
        if ((mas[i] < minEl) or (i == 0)) {
            minEl = mas[i];
            imin = i;
        }
    }


    for (int i = 0; i < n; i++)
    {
        if (i > min(imax, imin) && i < max(imax, imin)) {
            prMinMax *= mas[i];
            prMinMaxNot0 = true;
        }
    }

    int sred = s / 10;

    //Выведите значение суммы на экран
    cout << "Сумма элементов массива равна " << s << endl;
    cout << "Среднее значение элементов массива равна " << sred << endl;
    //a.расчет суммы отрицательных элементов,
    cout << "Сумма отрицательных элементов равна " << otr << endl;
    //b.расчет суммы положительных элементов,
    cout << "Суммы положительных элементов равна " << polog << endl;
    //c.расчет суммы элементов с нечетными индексами,
    cout << "Суммы элементов с нечетными индексами равна " << nechet << endl;
    //d.расчет суммы элементов с четными индексами.
    cout << "Суммы элементов с четными индексами равна " << chet << endl;
    //e.найти максимальный и минимальный элементы массива и вывести их индексы,
    cout << "Максимальный элемент массива " << maxEl << ", индекс:" << imax << endl;
    cout << "Минимальный элемент массива " << minEl << ", индекс:" << imin << endl;
    //f.рассчитать произведение элементов массива, расположенных между максимальным и минимальным элементами
    cout << "Произведение элементов массива, расположенных между максимальным и минимальным элементами, равно " << (prMinMax*prMinMaxNot0) << endl;

}