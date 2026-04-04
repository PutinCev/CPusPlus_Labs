#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

class Time
{
public:
    // Класс исключения для ошибок времени
    class InvalidTimeError
    {
    public:
        string origin;     // имя функции, где возникла ошибка
        int hours;         // ошибочное значение часов
        int minutes;       // ошибочное значение минут
        int seconds;       // ошибочное значение секунд
        string message;    // сообщение об ошибке

        InvalidTimeError(string or_, int h, int m, int s, string msg)
        {
            origin = or_;
            hours = h;
            minutes = m;
            seconds = s;
            message = msg;
        }

        void printError() const
        {
            cout << "\nОШИБКА в " << origin << ": " << message << endl;
            cout << "Некорректные значения: " << hours << "ч " << minutes << "м " << seconds << "с" << endl;
        }
    };

    // Конструктор по умолчанию (инициализация нулями)
    Time() : hours(0), minutes(0), seconds(0) {}

    // Конструктор с параметрами (с проверкой)
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
    {
        // Проверка на отрицательные значения
        if (hours < 0 || minutes < 0 || seconds < 0) {
            throw InvalidTimeError("Time::Time", hours, minutes, seconds,
                "Временная точка не может содержать отрицательные значения!");
        }

        // Проверка на допустимые диапазоны
        if (minutes >= 60) {
            throw InvalidTimeError("Time::Time", hours, minutes, seconds,
                "Минуты должны быть в диапазоне 0-59!");
        }

        if (seconds >= 60) {
            throw InvalidTimeError("Time::Time", hours, minutes, seconds,
                "Секунды должны быть в диапазоне 0-59!");
        }
    }

    // Вычисление общего количества секунд
    long long toSeconds() const
    {
        return (long long)hours * 3600 + minutes * 60 + seconds;
    }

    // Сложение двух временных точек
    Time add(const Time& other) const
    {
        long long total_seconds = toSeconds() + other.toSeconds();

        int new_hours = total_seconds / 3600;
        int new_minutes = (total_seconds % 3600) / 60;
        int new_seconds = total_seconds % 60;

        return Time(new_hours, new_minutes, new_seconds);
    }

    // Вычитание временных точек (с проверкой на отрицательный результат)
    Time subtract(const Time& other) const
    {
        long long diff_seconds = toSeconds() - other.toSeconds();

        if (diff_seconds < 0) {
            throw InvalidTimeError("Time::subtract", 0, 0, 0,
                "Результат вычитания временных точек не может быть отрицательным!");
        }

        int new_hours = diff_seconds / 3600;
        int new_minutes = (diff_seconds % 3600) / 60;
        int new_seconds = diff_seconds % 60;

        return Time(new_hours, new_minutes, new_seconds);
    }

    // Вывод временной точки на экран
    void display() const
    {
        cout << setfill('0') << setw(2) << hours << ":"
            << setfill('0') << setw(2) << minutes << ":"
            << setfill('0') << setw(2) << seconds;
    }

    // Геттеры
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }

private:
    int hours;
    int minutes;
    int seconds;
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int h1, m1, s1;
    int h2, m2, s2;

    // Ввод первой временной точки
    cout << "Введите первую временную точку:" << endl;
    cout << "Часы: ";
    cin >> h1;
    cout << "Минуты: ";
    cin >> m1;
    cout << "Секунды: ";
    cin >> s1;

    // Создание первого объекта Time
    Time t1;
    try
    {
        t1 = Time(h1, m1, s1);
        cout << "\nПервая временная точка: ";
        t1.display();
        cout << endl;
    }
    catch (Time::InvalidTimeError& ex)
    {
        ex.printError();
        return 1;
    }

    // Ввод второй временной точки
    cout << "\nВведите вторую временную точку:" << endl;
    cout << "Часы: ";
    cin >> h2;
    cout << "Минуты: ";
    cin >> m2;
    cout << "Секунды: ";
    cin >> s2;

    // Создание второго объекта Time
    Time t2;
    try
    {
        t2 = Time(h2, m2, s2);
        cout << "\nВторая временная точка: ";
        t2.display();
        cout << endl;
    }
    catch (Time::InvalidTimeError& ex)
    {
        ex.printError();
        return 1;
    }

    // Сложение временных точек
    try
    {
        Time t3 = t1.add(t2);
        cout << "\nСумма временных точек: ";
        t3.display();
        cout << endl;
    }
    catch (Time::InvalidTimeError& ex)
    {
        ex.printError();
        return 1;
    }

    // Вычитание временных точек
    try
    {
        Time t4 = t1.subtract(t2);
        cout << "Разность временных точек (первая - вторая): ";
        t4.display();
        cout << endl;
    }
    catch (Time::InvalidTimeError& ex)
    {
        ex.printError();
        return 1;
    }

    return 0;
}