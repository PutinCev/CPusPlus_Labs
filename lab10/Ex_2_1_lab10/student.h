#pragma once

#include <string>
#include "IdCard.h"
using namespace std;

class Student
{
public:
    // Конструкторы
    Student();
    Student(string, string);
    Student(string, string, int, string);

    // Деструктор
    ~Student();

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

    // Вычисление среднего балла
    void calculate_average_score();

    // Методы для работы с идентификационной карточкой (композиция)
    void setIdCard(int id, string c);
    int getIdCard();

    // Вывод всех данных о студенте
    void display();

private:
    int scores[5];
    double average_score;
    string name;
    string last_name;
    IdCard iCard;  // Теперь это поле, а не указатель (композиция)
};