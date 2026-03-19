#include <iostream>
#include <string>
#include <cctype>
#include <windows.h>


bool checkSNILS(const std::string& snils) {
    // Проверка длины строки (должна быть ровно 11 символов: 9 цифр + 2 цифры контрольного числа)
    if (snils.length() != 11) {
        return false;
    }

    // Проверка, что все символы являются цифрами
    for (char c : snils) {
        if (!std::isdigit(c)) {
            return false;
        }
    }

    // Извлечение основной части (первые 9 цифр) и контрольного числа (последние 2 цифры)
    std::string mainPart = snils.substr(0, 9);
    std::string controlPart = snils.substr(9, 2);

    // Проверка на наличие более чем двух одинаковых цифр подряд в основной части
    for (size_t i = 0; i < mainPart.length() - 2; ++i) {
        if (mainPart[i] == mainPart[i + 1] && mainPart[i] == mainPart[i + 2]) {
            return false;
        }
    }

    // Расчет контрольной суммы
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        // Позиция отсчитывается с конца (от 9 до 1)
        int position = 9 - i;
        int digit = mainPart[i] - '0';
        sum += digit * position;
    }

    // Вычисление контрольного числа по алгоритму
    int calculatedControl;
    if (sum < 100) {
        calculatedControl = sum;
    }
    else if (sum == 100 || sum == 101) {
        calculatedControl = 0;
    }
    else {
        int remainder = sum % 101;
        if (remainder < 100) {
            calculatedControl = remainder;
        }
        else { // remainder == 100
            calculatedControl = 0;
        }
    }

    // Сравнение вычисленного контрольного числа с заданным
    int givenControl = std::stoi(controlPart);
    return calculatedControl == givenControl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Тестовые примеры
    std::string testSnils1 = "11223344595"; // Пример корректного СНИЛС
    std::string testSnils2 = "12345678901"; // Пример некорректного СНИЛС
    std::string testSnils3 = "11122334495"; // С тремя единицами подряд
    std::string testSnils4 = "08765432100"; // С контрольным числом 00

    std::cout << "Проверка СНИЛС " << testSnils1 << ": "
        << (checkSNILS(testSnils1) ? "корректен" : "некорректен") << std::endl;

    std::cout << "Проверка СНИЛС " << testSnils2 << ": "
        << (checkSNILS(testSnils2) ? "корректен" : "некорректен") << std::endl;

    std::cout << "Проверка СНИЛС " << testSnils3 << ": "
        << (checkSNILS(testSnils3) ? "корректен" : "некорректен") << std::endl;

    std::cout << "Проверка СНИЛС " << testSnils4 << ": "
        << (checkSNILS(testSnils4) ? "корректен" : "некорректен") << std::endl;

    return 0;
}