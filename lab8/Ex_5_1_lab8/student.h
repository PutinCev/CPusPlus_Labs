#pragma once

#include <string>
using namespace std;

class Student {
public:
    // Конструктор класса Student
    Student(string, string);

    // Деструктор класса Student
    ~Student();

    // Запись данных о студенте в файл
    void save();

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

private:
    int scores[5];
    double average_score;
    string name;
    string last_name;
};