#include "Time.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Time::normalize()
{
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
    else if (seconds < 0) {
        int mins = (abs(seconds) + 59) / 60;
        minutes -= mins;
        seconds += mins * 60;
        if (seconds < 0) seconds = 0;
    }

    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    else if (minutes < 0) {
        int hrs = (abs(minutes) + 59) / 60;
        hours -= hrs;
        minutes += hrs * 60;
        if (minutes < 0) minutes = 0;
    }
}

Time::Time() : hours(0), minutes(0), seconds(0)
{
}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
{
    //Приводим к правильному формату
    normalize();
}

void Time::display() const
{
    // Используем setfill и setw для форматированного вывода (00:00:00)
    cout << setfill('0') << setw(2) << hours << ":"
        << setfill('0') << setw(2) << minutes << ":"
        << setfill('0') << setw(2) << seconds;
}

Time Time::add(const Time& other) const
{
    // Создаем новый объект с суммой всех компонентов
    // Конструктор автоматически нормализует результат
    return Time(hours + other.hours,
        minutes + other.minutes,
        seconds + other.seconds);
}

// Перегрузка оператора +
Time Time::operator+(const Time& other) const
{
    return add(other);
}

// Геттеры (константные методы)
int Time::getHours() const
{
    return hours;
}

int Time::getMinutes() const
{
    return minutes;
}

int Time::getSeconds() const
{
    return seconds;
}

// Сеттеры с нормализацией
void Time::setHours(int h)
{
    hours = h;
    normalize();
}

void Time::setMinutes(int m)
{
    minutes = m;
    normalize();
}

void Time::setSeconds(int s)
{
    seconds = s;
    normalize();
}