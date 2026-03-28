#include <iostream>
#include <windows.h>
using namespace std;

bool Input(int& a, int& b) {
    cout << "Введите два целых числа: ";

    // Проверка, что ввод успешен
    if (cin >> a >> b) {
        return true;
    }

    // Очистка потока при ошибке
    cin.clear();
    cin.ignore(10000, '\n');
    return false;
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int a, b;

    if (!Input(a, b)) {
        cerr << "error" << endl;
        return 1;
    }

    int s = a + b;
    cout << a << " + " << b << " = " << s << endl;

    return 0;
}