#include <iostream>
#include <string>
#include "student.h"
using namespace std;

// Конструктор с карточкой
Student::Student(string name, string last_name, IdCard* id)
{
    set_name(name);
    set_last_name(last_name);
    setIdCard(id);
    set_average_score(0);
}

// Конструктор для поиска (без карточки)
Student::Student(string name, string last_name)
{
    set_name(name);
    set_last_name(last_name);
    setIdCard(nullptr);
    set_average_score(0);
}

// Конструктор по умолчанию
Student::Student() {}

// Установка имени
void Student::set_name(string student_name)
{
    name = student_name;
}

// Получение имени
string Student::get_name()
{
    return name;
}

// Установка фамилии
void Student::set_last_name(string student_last_name)
{
    last_name = student_last_name;
}

// Получение фамилии
string Student::get_last_name()
{
    return last_name;
}

// Установка оценок
void Student::set_scores(int scores[])
{
    for (int i = 0; i < 5; ++i) {
        this->scores[i] = scores[i];
    }
}

// Установка среднего балла
void Student::set_average_score(double ball)
{
    average_score = ball;
}

// Получение среднего балла
double Student::get_average_score()
{
    return average_score;
}

// Установка карточки
void Student::setIdCard(IdCard* c)
{
    iCard = c;
}

// Получение карточки
IdCard Student::getIdCard()
{
    return *iCard;
}

// Вывод информации
void Student::display() const
{
    cout << last_name << " " << name << "\t" << average_score << "\t"
        << (iCard ? iCard->getNumber() : 0) << "\t"
        << (iCard ? iCard->getCategory() : "Нет карты") << endl;
}

// Оператор ==
bool operator==(const Student& p1, const Student& p2)
{
    return (p1.name == p2.name && p1.last_name == p2.last_name);
}

// Оператор < (сортировка по фамилии, затем по имени)
bool operator<(const Student& p1, const Student& p2)
{
    if (p1.last_name == p2.last_name)
        return (p1.name < p2.name);
    return (p1.last_name < p2.last_name);
}

// Оператор !=
bool operator!=(const Student& p1, const Student& p2)
{
    return !(p1 == p2);
}

// Оператор >
bool operator>(const Student& p1, const Student& p2)
{
    return !(p1 < p2) && !(p1 == p2);
}