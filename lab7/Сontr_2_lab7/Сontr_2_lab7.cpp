#include <iostream>
#include <cmath>
using namespace std;
#include <windows.h>


// Структура для корней квадратного уравнения
struct Roots {
    double x1;
    double x2;
};

// Функция решает квадратное уравнение и возвращает структуру с корнями
Roots solveQuadratic(double a, double b, double c) {
    Roots r;

    // Вычисляем дискриминант
    double D = b * b - 4 * a * c;

    // Находим корни (если дискриминант >= 0)
    r.x1 = (-b + sqrt(D)) / (2 * a);
    r.x2 = (-b - sqrt(D)) / (2 * a);

    return r;
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double a, b, c;

    cout << "Введите коэффициенты a, b, c: ";
    cin >> a >> b >> c;

    // Решаем уравнение
    Roots result = solveQuadratic(a, b, c);

    // Выводим корни
    cout << "Корень 1: " << result.x1 << endl;
    cout << "Корень 2: " << result.x2 << endl;

    return 0;
}