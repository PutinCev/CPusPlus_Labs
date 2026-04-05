#include "student.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Конструктор по умолчанию
Student::Student()
{
    // iCard создается автоматически с помощью конструктора по умолчанию
}

// Конструктор с именем и фамилией
Student::Student(string name, string last_name)
{
    set_name(name);
    set_last_name(last_name);
    // iCard создается автоматически с помощью конструктора по умолчанию
}

// Конструктор с именем, фамилией, номером карты и категорией
Student::Student(string name, string last_name, int id, string cat)
{
    set_name(name);
    set_last_name(last_name);
    setIdCard(id, cat);
}

// Деструктор
Student::~Student()
{
    // Ничего не нужно удалять, так как iCard не указатель
    // iCard уничтожится автоматически вместе со Student
}

void Student::set_name(string student_name)
{
    name = student_name;
}

string Student::get_name()
{
    return name;
}

void Student::set_last_name(string student_last_name)
{
    last_name = student_last_name;
}

string Student::get_last_name()
{
    return last_name;
}

void Student::set_scores(int student_scores[])
{
    for (int i = 0; i < 5; ++i) {
        scores[i] = student_scores[i];
    }
}

void Student::set_average_score(double ball)
{
    average_score = ball;
}

double Student::get_average_score()
{
    return average_score;
}

void Student::calculate_average_score()
{
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += scores[i];
    }
    average_score = sum / 5.0;
}

// Методы для работы с идентификационной карточкой (композиция)
void Student::setIdCard(int id, string c)
{
    iCard = IdCard(id, c);  // Создаем объект IdCard внутри Student
}

int Student::getIdCard()
{
    return iCard.getNumber();
}

// Вывод всех данных о студенте
void Student::display()
{
    cout << last_name << " " << name << "\t"
        << fixed << setprecision(2) << average_score << "\t"
        << iCard.getNumber() << "\t\t"
        << iCard.getCategory() << endl;
}