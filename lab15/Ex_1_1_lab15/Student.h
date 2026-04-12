#pragma once
#include "IdCard.h"
#include <string>

using namespace std;

class Student
{
public:
    // Конструкторы
    Student(string, string, IdCard*);
    Student(string, string);  // для поиска
    Student();

    // Установка имени студента
    void set_name(string);
    // Получение имени студента
    string get_name();
    // Установка фамилии студента
    void set_last_name(string);
    // Получение фамилии студента
    string get_last_name();
    // Установка промежуточных оценок
    void set_scores(int[]);
    // Установка среднего балла
    void set_average_score(double);
    // Получение среднего балла
    double get_average_score();
    // Вывод информации о студенте
    void display() const;
    // Установка карточки
    void setIdCard(IdCard* c);
    // Получение карточки
    IdCard getIdCard();

    // Дружественные операторы сравнения
    friend bool operator<(const Student&, const Student&);
    friend bool operator>(const Student&, const Student&);
    friend bool operator==(const Student&, const Student&);
    friend bool operator!=(const Student&, const Student&);

private:
    int scores[5];
    double average_score;
    string name;
    string last_name;
    IdCard* iCard;
};