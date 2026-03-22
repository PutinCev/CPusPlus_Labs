#include <iostream>
#include <cmath>
#include <windows.h>

// Функция для вычисления площади равностороннего треугольника
double triangleArea(double side) {
    return (sqrt(3) / 4) * side * side;
}

// Перегруженная функция для вычисления площади разностороннего треугольника
double triangleArea(double sideA, double sideB, double sideC) {
    // Проверка существования треугольника
    if (sideA + sideB <= sideC || sideA + sideC <= sideB || sideB + sideC <= sideA) {
        return -1;
    }

    // Формула Герона
    double p = (sideA + sideB + sideC) / 2.0;
    return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int choice;
    do {
        std::cout << "\nВыберите тип треугольника:\n";
        std::cout << "1. Равносторонний\n";
        std::cout << "2. Разносторонний\n";
        std::cout << "0. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        if (choice == 1) {
            double side;
            std::cout << "Введите сторону: ";
            std::cin >> side;

            if (side > 0) {
                double area = triangleArea(side);
                std::cout << "Площадь: " << area << std::endl;
            }
            else {
                std::cout << "Ошибка: сторона должна быть положительной!" << std::endl;
            }
        }
        else if (choice == 2) {
            double a, b, c;
            std::cout << "Введите стороны a, b, c: ";
            std::cin >> a >> b >> c;

            if (a > 0 && b > 0 && c > 0) {
                double area = triangleArea(a, b, c);
                if (area > 0) {
                    std::cout << "Площадь: " << area << std::endl;
                }
                else {
                    std::cout << "Ошибка: треугольник с такими сторонами не существует!" << std::endl;
                }
            }
            else {
                std::cout << "Ошибка: все стороны должны быть положительными!" << std::endl;
            }
        }

    } while (choice != 0);

    return 0;
}