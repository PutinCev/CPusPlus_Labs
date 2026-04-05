#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

    void normalize()
    {
        if (seconds >= 60)
        {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60)
        {
            hours += minutes / 60;
            minutes %= 60;
        }
    }

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
    {
        normalize();
    }

    Time(float hoursFloat)
    {
        hours = static_cast<int>(hoursFloat);
        float frac = hoursFloat - hours;
        minutes = static_cast<int>(frac * 60);
        seconds = static_cast<int>((frac * 60 - minutes) * 60);
        normalize();
    }

    operator float() const
    {
        return hours + minutes / 60.0f + seconds / 3600.0f;
    }

    // Сложение объектов Time
    Time operator+ (const Time& other) const
    {
        return Time(hours + other.hours,
            minutes + other.minutes,
            seconds + other.seconds);
    }

    // Вычитание объектов Time
    Time operator- (const Time& other) const
    {
        int total1 = hours * 3600 + minutes * 60 + seconds;
        int total2 = other.hours * 3600 + other.minutes * 60 + other.seconds;

        if (total1 < total2)
        {
            cout << "ОШИБКА: Результат вычитания не может быть отрицательным!" << endl;
            return Time(0, 0, 0);
        }

        return Time(hours - other.hours,
            minutes - other.minutes,
            seconds - other.seconds);
    }

    // Time + float
    Time operator+ (float hoursFloat) const
    {
        return *this + Time(hoursFloat);
    }

    // float + Time (дружественная функция)
    friend Time operator+ (float hoursFloat, const Time& t);

    // Операторы сравнения
    bool operator== (const Time& other) const
    {
        return (hours == other.hours && minutes == other.minutes && seconds == other.seconds);
    }

    bool operator!= (const Time& other) const
    {
        return !(*this == other);
    }

    bool operator< (const Time& other) const
    {
        int total1 = hours * 3600 + minutes * 60 + seconds;
        int total2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
        return total1 < total2;
    }

    bool operator> (const Time& other) const
    {
        int total1 = hours * 3600 + minutes * 60 + seconds;
        int total2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
        return total1 > total2;
    }

    void display() const
    {
        cout << setfill('0') << setw(2) << hours << ":"
            << setfill('0') << setw(2) << minutes << ":"
            << setfill('0') << setw(2) << seconds;
    }
};

Time operator+ (float hoursFloat, const Time& t)
{
    return Time(hoursFloat) + t;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Time t1(2, 30, 45);
    Time t2(1, 45, 50);

    cout << "t1 = "; t1.display(); cout << endl;
    cout << "t2 = "; t2.display(); cout << endl;

    // Сложение Time + Time
    Time t3 = t1 + t2;
    cout << "\nt1 + t2 = "; t3.display(); cout << endl;

    // Вычитание Time - Time
    Time t4 = t1 - t2;
    cout << "t1 - t2 = "; t4.display(); cout << endl;

    // Time + float
    Time t5 = t1 + 1.5F;
    cout << "\nt1 + 1.5 часа = "; t5.display(); cout << endl;

    // float + Time
    Time t6 = 1.5F + t1;
    cout << "1.5 часа + t1 = "; t6.display(); cout << endl;

    // Сравнение
    cout << "\nСравнение t1 и t2:" << endl;
    cout << "t1 == t2: " << (t1 == t2 ? "true" : "false") << endl;
    cout << "t1 != t2: " << (t1 != t2 ? "true" : "false") << endl;
    cout << "t1 < t2: " << (t1 < t2 ? "true" : "false") << endl;
    cout << "t1 > t2: " << (t1 > t2 ? "true" : "false") << endl;

    return 0;
}