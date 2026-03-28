#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
    // Проверка количества параметров
    if (argc != 4) {
        cout << "Ошибка: Неверное количество параметров!" << endl;
        cout << "Использование: " << argv[0] << " -a/-m число1 число2" << endl;
        return 1;
    }

    // Проверка формата (второй параметр должен быть -a или -m)
    if (strcmp(argv[1], "-a") != 0 && strcmp(argv[1], "-m") != 0) {
        cout << "Ошибка: Неверный флаг операции!" << endl;
        cout << "Используйте -a для сложения или -m для умножения" << endl;
        return 1;
    }

    // Конвертация чисел
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);

    // Выполнение операции
    if (strcmp(argv[1], "-a") == 0) {
        cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    }
    else {
        cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    }

    return 0;
}