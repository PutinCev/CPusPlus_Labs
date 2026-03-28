#include <iostream>
#include <cmath>
#include <windows.h>

int Myroot(double a, double b, double c, double& x1, double& x2) {
    // Проверка, что уравнение квадратное
    if (a == 0) {
        // Линейное уравнение bx + c = 0
        if (b == 0) {
            return -1; // Нет корней
        }
        x1 = -c / b;
        x2 = x1;
        return 0; // Один корень
    }

    // Вычисление дискриминанта
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        // Два различных корня
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        return 1; // Два корня
    }
    else if (discriminant == 0) {
        // Один корень (два совпадающих)
        x1 = -b / (2 * a);
        x2 = x1;
        return 0; // Корни совпадают
    }
    else {
        // Корней нет
        return -1;
    }
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double a, b, c;
    double x1, x2;

    std::cout << "Решение квадратного уравнения ax^2 + bx + c = 0" << std::endl;
    std::cout << "Введите коэффициенты a, b, c: ";
    std::cin >> a >> b >> c;

    int result = Myroot(a, b, c, x1, x2);

    switch (result) {
    case 1:
        std::cout << "Корни уравнения x1 = " << x1 << ", x2 = " << x2 << std::endl;
        break;
    case 0:
        std::cout << "Корень уравнения один x1 = x2 = " << x1 << std::endl;
        break;
    case -1:
        std::cout << "Корней уравнения нет" << std::endl;
        break;
    }

    return 0;
}