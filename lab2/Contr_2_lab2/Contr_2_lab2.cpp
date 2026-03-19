#include <iostream>
using namespace std;
#include <windows.h>


bool isSuperPrime(int n) {
    if (n < 2) return false;

    // Проверка на простоту самого числа
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }

    // Находим индекс числа среди простых
    int index = 0;
    for (int i = 2; i <= n; i++) {
        bool prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            index++;
            if (i == n) break;
        }
    }

    // Проверяем, простой ли индекс
    if (index < 2) return false;
    for (int i = 2; i * i <= index; i++) {
        if (index % i == 0) return false;
    }
    return true;
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n;
    cout << "Число: ";
    cin >> n;
    cout << n << (isSuperPrime(n) ? " - суперпростое" : " - не суперпростое") << endl;
    return 0;
}