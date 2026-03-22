#include <iostream>
#include <windows.h>


// Рекурсивная функция перевода десятичного числа в двоичное
void decimalToBinary(int num) {
    if (num > 0) {
        decimalToBinary(num / 2);  // Рекурсивный вызов с делением на 2
        std::cout << num % 2;       // Вывод остатка после рекурсивного вызова
    }
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int num;

    std::cout << "Введите целое положительное число: ";
    std::cin >> num;

    if (num > 0) {
        std::cout << "Двоичное представление: ";
        decimalToBinary(num);
        std::cout << std::endl;
    }
    else if (num == 0) {
        std::cout << "Двоичное представление: 0" << std::endl;
    }
    else {
        std::cout << "Ошибка: число должно быть положительным!" << std::endl;
    }

    return 0;
}
