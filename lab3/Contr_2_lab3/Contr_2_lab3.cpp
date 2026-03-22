#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>


// Вариант 1: Использование стандартной функции pow
double cubeRootStd(double x) {
    if (x < 0) {
        return -pow(-x, 1.0 / 3.0);
    }
    return pow(x, 1.0 / 3.0);
}

// Вариант 2: Итерационная формула (метод Ньютона)
double cubeRootIter(double x, double epsilon = 1e-10) {
    if (x == 0) return 0;

    // Начальное приближение
    double guess;
    if (x > 0) {
        guess = x / 3.0; // Начальное приближение для положительных чисел
    }
    else {
        guess = -pow(-x, 1.0 / 3.0); // Начальное приближение для отрицательных
    }

    // Итерационная формула: x_{n+1} = (2*x_n + a/(x_n^2)) / 3
    double nextGuess;
    do {
        nextGuess = (2.0 * guess + x / (guess * guess)) / 3.0;

        // Проверка на сходимость
        if (std::abs(nextGuess - guess) < epsilon) {
            break;
        }

        guess = nextGuess;
    } while (true);

    return nextGuess;
}

// Функция для сравнения результатов
void testCubeRoot(double value) {
    double resultStd = cubeRootStd(value);
    double resultIter = cubeRootIter(value);
    double exactResult = std::cbrt(value); // Точное значение для сравнения

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Число: " << value << std::endl;
    std::cout << "  pow(1/3):     " << resultStd << std::endl;
    std::cout << "  Итерационный: " << resultIter << std::endl;
    std::cout << "  Точное (cbrt): " << exactResult << std::endl;
    std::cout << "  Разница между итерационным и точным: "
        << std::abs(resultIter - exactResult) << std::endl;
    std::cout << std::endl;
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "Тестирование функций вычисления кубического корня\n";
    std::cout << "================================================\n\n";

    // Тестовые значения
    double testValues[] = {
        27.0,      // 3^3 = 27
        -27.0,     // (-3)^3 = -27
        8.0,       // 2^3 = 8
        -8.0,      // (-2)^3 = -8
        0.0,       // 0^3 = 0
        1.0,       // 1^3 = 1
        -1.0,      // (-1)^3 = -1
        0.125,     // 0.5^3 = 0.125
        -0.125,    // (-0.5)^3 = -0.125
        1000.0,    // 10^3 = 1000
        2.0,       // ∛2 ≈ 1.25992105
        100.0,     // ∛100 ≈ 4.64158883
        0.001,     // 0.1^3 = 0.001
        -0.001     // (-0.1)^3 = -0.001
    };

    int numTests = sizeof(testValues) / sizeof(testValues[0]);

    for (int i = 0; i < numTests; ++i) {
        testCubeRoot(testValues[i]);
    }

    // Дополнительный тест с высокой точностью
    std::cout << "Тестирование точности итерационного метода\n";
    std::cout << "==========================================\n\n";

    double testValue = 2.0;
    double resultIter = cubeRootIter(testValue, 1e-15);
    double resultStd = cubeRootStd(testValue);

    std::cout << "Кубический корень из " << testValue << ":\n";
    std::cout << "  pow(1/3):           " << std::setprecision(15) << resultStd << std::endl;
    std::cout << "  Итерационный метод: " << std::setprecision(15) << resultIter << std::endl;
    std::cout << "  Точное значение:    " << std::setprecision(15) << std::cbrt(testValue) << std::endl;
    std::cout << "  Погрешность:        " << std::abs(resultIter - std::cbrt(testValue)) << std::endl;

    return 0;
}