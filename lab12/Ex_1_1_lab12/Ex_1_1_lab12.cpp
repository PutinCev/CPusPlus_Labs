#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

// Базовый класс human
class human {
public:
    // Конструктор класса human
    human(string last_name, string name, string second_name)
    {
        this->last_name = last_name;
        this->name = name;
        this->second_name = second_name;
    }

    // Получение ФИО человека
    string get_full_name()
    {
        return last_name + " " + name + " " + second_name;
    }

private:
    string name;        // имя
    string last_name;   // фамилия
    string second_name; // отчество
};

// Производный класс student
class student : public human {
public:
    // Конструктор класса Student
    student(string last_name, string name, string second_name,
        vector<int> scores) : human(last_name, name, second_name)
    {
        this->scores = scores;
    }

    // Получение среднего балла студента
    float get_average_score()
    {
        unsigned int count_scores = this->scores.size();
        unsigned int sum_scores = 0;

        for (unsigned int i = 0; i < count_scores; ++i) {
            sum_scores += this->scores[i];
        }

        if (count_scores > 0) {
            return (float)sum_scores / (float)count_scores;
        }
        return 0;
    }

private:
    vector<int> scores;  // Оценки студента
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Создание вектора с оценками
    vector<int> scores = { 5, 4, 5, 4, 5 };

    // Создание объекта student
    student stud("Иванов", "Иван", "Иванович", scores);

    // Вывод ФИО (метод базового класса)
    cout << "ФИО: " << stud.get_full_name() << endl;

    // Вывод среднего балла (метод производного класса)
    cout << "Средний балл: " << stud.get_average_score() << endl;

    return 0;
}