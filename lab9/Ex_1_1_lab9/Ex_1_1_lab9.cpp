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
        throw DivideByZeroError();  // Генерируем исключение
    return (float)num1 / num2;
}

int main()
{

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "=== Программа деления двух целых чисел ===" << endl;
    cout << "Введите два целых числа для расчета их частного:\n";

    int number1, number2;
    cout << "Первое число (делимое): ";
    cin >> number1;
    cout << "Второе число (делитель): ";
    cin >> number2;

    try
    {
        float result = quotient(number1, number2);
        cout << "\nРезультат деления:" << endl;
        cout << number1 << " / " << number2 << " = " << result << endl;
    }
    catch (DivideByZeroError& error)  // Перехватываем исключение по ссылке
    {
        cout << "\nОШИБКА: ";
        error.printMessage();
        return 1;  // Завершение программы с кодом ошибки
    }

    cout << "\nПрограмма успешно завершена!" << endl;
    return 0;  // Нормальное завершение программы
}