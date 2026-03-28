#include <iostream>
#include<cmath>
#include <windows.h>
using namespace std;

// Функция поиска с транспозицией
int search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            if (i > 0) {
                swap(arr[i], arr[i - 1]);  // меняем с предыдущим
                return i - 1;
            }
            return i;
        }
    }
    return -1;  // не найден
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int arr[] = { 5, 2, 8, 1, 9, 3 };
    int n = size(arr);

    // Ищем элемент 8
    int idx = search(arr, n, 8);

    cout << "Индекс: " << idx << endl;
    cout << "Массив после поиска: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}