#include <iostream>
using namespace std;

// Шаблонная функция для вычисления среднего арифметического
template <typename T>
double average(T arr[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}

int main()
{
    // Массив int
    int intArr[] = { 10, 20, 30, 40, 50 };
    cout << "Среднее int: " << average(intArr, 5) << endl;

    // Массив long
    long longArr[] = { 100, 200, 300, 400, 500 };
    cout << "Среднее long: " << average(longArr, 5) << endl;

    // Массив double
    double doubleArr[] = { 1.5, 2.5, 3.5, 4.5, 5.5 };
    cout << "Среднее double: " << average(doubleArr, 5) << endl;

    // Массив char
    char charArr[] = { 10, 20, 30, 40, 50 };
    cout << "Среднее char: " << average(charArr, 5) << endl;

    return 0;
}