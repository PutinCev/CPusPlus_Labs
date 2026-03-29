#include <iostream>
#include <cmath>
#include <tuple>
#include <windows.h>
using namespace std;

// Функция решает квадратное уравнение и возвращает кортеж:
// (корень_1, корень_2, есть_корни)
tuple<double, double, bool> solveQuadratic(double a, double b, double c) {
    // Вычисляем дискриминант
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0 || a == 0) {
        // Нет действительных корней или уравнение не квадратное
        return make_tuple(0.0, 0.0, false);
    }

    // Вычисляем корни
    double root1 = (-b + sqrt(discriminant)) / (2 * a);
    double root2 = (-b - sqrt(discriminant)) / (2 * a);

    return make_tuple(root1, root2, true);
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double a, b, c;

    cout << "Решение квадратного уравнения ax² + bx + c = 0\n";
    cout << "Введите коэффициент a: ";
    cin >> a;
    cout << "Введите коэффициент b: ";
    cin >> b;
    cout << "Введите коэффициент c: ";
    cin >> c;

    // Решаем уравнение, получаем кортеж
    tuple<double, double, bool> myTuple = solveQuadratic(a, b, c);

    double root1 = get<0>(myTuple);
    double root2 = get<1>(myTuple);
    double hasRoots = get<2>(myTuple);

    // Обрабатываем результат
    cout << "\nРезультат:\n";
    if (hasRoots) {
        if (root1 == root2) {
            cout << "Один корень: x = " << root1 << "\n";
        }
        else {
            cout << "Два корня:\n";
            cout << "x₁ = " << root1 << "\n";
            cout << "x₂ = " << root2 << "\n";
        }
    }
    else {
        cout << "Уравнение не имеет действительных корней.\n";
    }

    return 0;
}