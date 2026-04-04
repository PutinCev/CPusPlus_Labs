#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>
#include "student.h"

using namespace std;

// Конструктор Student
Student::Student(string name, string last_name)
{
    Student::set_name(name);
    Student::set_last_name(last_name);
}

// Деструктор Student
Student::~Student()
{
    Student::save();
    cout << "Деструктор вызван для студента: " << get_name() << " " << get_last_name() << endl;
}

// Запись данных о студенте в файл
void Student::save()
{

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    ofstream fout("students.txt", ios::app);
    if (fout.is_open()) {
        fout << Student::get_name() << " "
            << Student::get_last_name() << " ";
        for (int i = 0; i < 5; ++i) {
            fout << Student::scores[i] << " ";
        }
        fout << endl;
        fout.close();
        cout << "Данные студента " << get_name() << " " << get_last_name()
            << " сохранены в файл." << endl;
    }
    else {
        cerr << "Ошибка: не удалось открыть файл для записи!" << endl;
    }
}

// Установка имени студента
void Student::set_name(string student_name)
{
    name = student_name;
}

// Получение имени студента
string Student::get_name()
{
    return name;
}

// Установка фамилии студента
void Student::set_last_name(string student_last_name)
{
    last_name = student_last_name;
}

// Получение фамилии студента
string Student::get_last_name()
{
    return last_name;
}

// Установка промежуточных оценок
void Student::set_scores(int student_scores[])
{
    for (int i = 0; i < 5; ++i) {
        scores[i] = student_scores[i];
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

// Вычисление среднего балла
void Student::calculate_average_score()
{
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += scores[i];
    }
    average_score = sum / 5.0;
}