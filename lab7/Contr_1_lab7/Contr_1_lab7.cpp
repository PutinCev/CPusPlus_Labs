#include <iostream>
using namespace std;
#include <windows.h>

// Структура Time с тремя полями
struct Time {
    int hours;
    int minutes;
    int seconds;

    // Функция сложения двух временных интервалов
    Time add(Time t2) {
        Time result;
        result.seconds = seconds + t2.seconds;
        result.minutes = minutes + t2.minutes + result.seconds / 60;
        result.hours = hours + t2.hours + result.minutes / 60;

        // Приводим к нормальным значениям (остатки переносим)
        result.seconds %= 60;
        result.minutes %= 60;
        return result;
    }

    // Функция вычитания двух временных интервалов (без отрицательных значений)
    Time subtract(Time t2) {
        Time result;

        // Переводим всё в секунды, вычитаем, затем обратно в часы/минуты/секунды
        int total1 = hours * 3600 + minutes * 60 + seconds;
        int total2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

        int diff = total1 - total2;
        if (diff < 0) diff = 0; // Если результат отрицательный — ставим 0

        result.hours = diff / 3600;
        diff %= 3600;
        result.minutes = diff / 60;
        result.seconds = diff % 60;

        return result;
    }
};

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Time t;

    cout << "Введите часы: ";
    cin >> t.hours;
    cout << "Введите минуты: ";
    cin >> t.minutes;
    cout << "Введите секунды: ";
    cin >> t.seconds;

    int totalSeconds = t.hours * 3600 + t.minutes * 60 + t.seconds;
    cout << "Всего секунд: " << totalSeconds << endl;

    Time t2;
    cout << "\nВведите второе время для операций:\n";
    cout << "Часы: "; cin >> t2.hours;
    cout << "Минуты: "; cin >> t2.minutes;
    cout << "Секунды: "; cin >> t2.seconds;

    Time sum = t.add(t2);
    cout << "\nРезультат сложения: " << sum.hours << "ч " << sum.minutes << "м " << sum.seconds << "с" << endl;

    Time diff = t.subtract(t2);
    cout << "Результат вычитания: " << diff.hours << "ч " << diff.minutes << "м " << diff.seconds << "с" << endl;

    return 0;
}