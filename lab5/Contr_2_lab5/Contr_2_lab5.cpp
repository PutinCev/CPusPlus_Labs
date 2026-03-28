#include <iostream>
using namespace std;

// Функция возвращает указатель на динамический массив,
// содержащий максимальные элементы из соответствующих позиций массивов a и b
int* max_vect(int size, int* a, int* b) {
    // Выделяем динамическую память под массив размером size
    int* result = new int[size];

    // Заполняем массив максимальными значениями
    for (int i = 0; i < size; i++) {
        if (a[i] > b[i]) {
            result[i] = a[i];
        }
        else {
            result[i] = b[i];
        }
        // Более краткая запись: result[i] = (a[i] > b[i]) ? a[i] : b[i];
    }

    return result; // Возвращаем указатель на созданный массив
}

int main() {
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 2 };
    int b[] = { 7, 6, 5, 4, 3, 2, 1, 3 };
    int kc = sizeof(a) / sizeof(a[0]); // Количество элементов массива

    int* c; // Указатель на результирующий массив
    c = max_vect(kc, a, b); // вызов функции для создания массива

    // Вывод результата
    for (int i = 0; i < kc; i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    delete[] c; // Возврат памяти

    return 0;
}