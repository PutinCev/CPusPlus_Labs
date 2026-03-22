#include <iostream>
#include <windows.h>

// Рекурсивная функция вычисления суммы ряда 5 + 10 + 15 + ... + 5*n
int sumSeries(int n) {
    if (n == 1) {
        return 5;  // Базовый случай: 5*1 = 5
    }
    return 5 * n + sumSeries(n - 1);  // Рекурсивный вызов
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n;

    std::cout << "Введите n (n > 0): ";
    std::cin >> n;

    if (n > 0) {
        int result = sumSeries(n);
        std::cout << "Сумма ряда: " << result << std::endl;
    }
    else {
        std::cout << "Ошибка: n должно быть больше 0" << std::endl;
    }

    return 0;
}