#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <windows.h>
using namespace std;

int FindMaxEven(const vector<int>& vec)
{
    // Находим максимальный четный элемент
    auto it = max_element(vec.begin(), vec.end(),
        [](int a, int b) {
            // Если оба четные - сравниваем
            if (a % 2 == 0 && b % 2 == 0) return a < b;
            // Четное больше нечетного
            if (a % 2 == 0) return false;
            if (b % 2 == 0) return true;
            // Оба нечетные - равны
            return false;
        });

    // Если нет четных чисел - исключение
    if (it == vec.end() || *it % 2 != 0) {
        throw runtime_error("Нет четных чисел");
    }

    return *it;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<int> vec = { 1, 5, 3, 8, 6, 4, 9 };

    try {
        cout << "Наибольшее четное: " << FindMaxEven(vec) << endl;
    }
    catch (const runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}