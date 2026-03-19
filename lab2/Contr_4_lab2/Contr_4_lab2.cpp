#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    srand(time(0));

    int mode;
    cout << "1 - Обычная стрельба" << endl;
    cout << "2 - Стрельба вслепую (случайный центр)" << endl;
    cout << "3 - Стрельба с помехами" << endl;
    cout << "Выберите режим: ";
    cin >> mode;

    // Центр мишени
    double centerX = 0, centerY = 0;
    if (mode == 2) {
        centerX = (rand() % 20 - 10) / 2.0;
        centerY = (rand() % 20 - 10) / 2.0;
        cout << "Центр мишени неизвестен!" << endl;
    }
    else {
        cout << "Центр мишени в точке (0,0)" << endl;
    }

    int score = 0;
    int shots = 0;
    const int TARGET = 50;

    while (score < TARGET) {
        shots++;
        cout << "\nВыстрел #" << shots << " (нужно " << TARGET - score << " очков)" << endl;

        double x, y;
        cout << "X Y: ";
        cin >> x >> y;

        // Помеха (режим 3)
        if (mode == 3) {
            x += (rand() % 30 - 15) / 10.0;
            y += (rand() % 30 - 15) / 10.0;
            cout << "Помеха! Выстрел сместился" << endl;
        }

        // Расстояние до центра
        double dist = sqrt(pow(x - centerX, 2) + pow(y - centerY, 2));

        // Очки
        int points = 0;
        if (dist <= 1) points = 10;
        else if (dist <= 2) points = 5;
        else if (dist <= 3) points = 3;
        else if (dist <= 4) points = 1;

        score += points;
        cout << "Очки: +" << points << " (всего: " << score << ")" << endl;
    }

    // Результат
    cout << "\n=== ИТОГ ===" << endl;
    cout << "Выстрелов: " << shots << endl;
    cout << "Очки: " << score << endl;

    if (shots <= 5) cout << "СНАЙПЕР!" << endl;
    else if (shots <= 10) cout << "Хороший стрелок" << endl;
    else cout << "Новичок" << endl;

    return 0;
}