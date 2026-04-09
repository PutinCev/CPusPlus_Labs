#include <concepts>
#include <iostream>
using namespace std;

// Функция Factorial, доступная только для целочисленных типов
template <std::integral T>
T Factorial(T n) {
    if (n <= 1) return 1;
    return n * Factorial(n - 1);
}

int main()
{
    // Целочисленный тип - работает
    int intNum = 5;
    cout << "Factorial(" << intNum << ") = " << Factorial(intNum) << endl;

    // Вещественный тип - вызовет ошибку компиляции
    //double doubleNum = 5.5;
    //cout << "Factorial(" << doubleNum << ") = " << Factorial(doubleNum) << endl;

    return 0;
}