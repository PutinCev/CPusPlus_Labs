#include <iostream>
using namespace std;
#include <windows.h>


int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Номиналы монет
    int coins[] = { 10, 5, 2, 1 };
    int coinCount[4] = { 0, 0, 0, 0 };

    int sum;
    cout << "Введите сумму в рублях: ";
    cin >> sum;

    int ostatok = sum;
    int vsegoMonet = 0;

    for (int i = 0; i < 4; i++) {
        if (ostatok >= coins[i]) {
            coinCount[i] = ostatok / coins[i];
            ostatok = ostatok % coins[i];
            vsegoMonet += coinCount[i];
        }
    }

    cout << "\nСумма " << sum << " руб.:" << endl;
    for (int i = 0; i < 4; i++) {
        if (coinCount[i] > 0) {
            cout << coinCount[i] << " монет по " << coins[i] << " руб." << endl;
        }
    }
    cout << "Всего монет: " << vsegoMonet << endl;

    return 0;
}