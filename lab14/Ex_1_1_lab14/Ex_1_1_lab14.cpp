#include <iostream>
#include <windows.h>
using namespace std;

// Шаблонная функция сортировки
template<class T>
void sorting(T arr[], int size)
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        T x = arr[i];
        for (j = i - 1; j >= 0 && x < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = x;
    }
}

// Шаблонная функция вывода массива
template<class T>
void printArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ";";
    cout << endl;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Целые числа
    int arr[] = { 9, 3, 17, 6, 5, 4, 31, 2, 12 };
    int k1 = sizeof(arr) / sizeof(arr[0]);

    // Вещественные числа
    double arrd[] = { 2.1, 2.3, 1.7, 6.6, 5.3, 2.44, 3.1, 2.4, 1.2 };
    int k2 = sizeof(arrd) / sizeof(arrd[0]);

    // Символы
    char arrc[] = "Hello, word";
    int k3 = sizeof(arrc) / sizeof(arrc[0]) - 1;

    // Сортировка и вывод
    sorting(arr, k1);
    printArray(arr, k1);

    sorting(arrd, k2);
    printArray(arrd, k2);

    sorting(arrc, k3);
    printArray(arrc, k3);

    return 0;
}