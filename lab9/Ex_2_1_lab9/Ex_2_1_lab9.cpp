#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

// Класс исключения для ошибки деления на ноль
class DivideByZeroError
{
public:
    DivideByZeroError() : message("Деление на нуль") {}
    void printMessage() const { cout << message << endl; }
private:
    string message;
};

// Функция деления с проверкой на ноль
float quotient(int num1, int num2)
{
    if (num2 == 0)
        throw DivideByZeroError();
    return (float)num1 / num2;
}

int main()
{

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "=== Программа деления числа на значения от -10 до 10 ===" << endl;
    cout << "Введите целое число (делимое): ";

    int number1;
    cin >> number1;

    cout << "\nРезультаты деления " << number1 << " на числа от -10 до 10:\n";
    cout << "----------------------------------------" << endl;

    // Цикл с блоком try-catch для безопасного деления
    for (int i = -10; i < 10; i++)
    {
        try
        {
            float result = quotient(number1, i);
            cout << number1 << " / " << i << " = " << result << endl;
        }
        catch (DivideByZeroError& error)
        {
            cout << number1 << " / " << i << " -> ОШИБКА: ";
            error.printMessage();
        }
    }

    cout << "----------------------------------------" << endl;
    cout << "\nПрограмма успешно завершена!" << endl;

    return 0;
}