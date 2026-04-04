#pragma once

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize();

public:
    Time();

    Time(int h, int m, int s);

    void display() const;

    Time add(const Time& other) const;

    Time operator+(const Time& other) const;

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    void setHours(int h);
    void setMinutes(int m);
    void setSeconds(int s);
};