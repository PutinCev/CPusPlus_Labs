#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

// Базовый класс human
class human {
public:
    human(string last_name, string name, string second_name)
    {
        this->last_name = last_name;
        this->name = name;
        this->second_name = second_name;
    }

    string get_full_name()
    {
        return last_name + " " + name + " " + second_name;
    }

private:
    string name;
    string last_name;
    string second_name;
};

// Производный класс student
class student : public human {
public:
    student(string last_name, string name, string second_name,
        vector<int> scores) : human(last_name, name, second_name)
    {
        this->scores = scores;
    }

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
    vector<int> scores;
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Оценки студента
    vector<int> scores;

    // Добавление оценок студента в вектор
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(4);
    scores.push_back(4);
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);

    // Создание конкретного студента – объект класса student
    student* stud = new student("Петров", "Иван", "Алексеевич", scores);

    // Вывод полного имени студента (метод базового класса human)
    cout << "ФИО студента: " << stud->get_full_name() << endl;

    // Вывод среднего балла студента (метод класса student)
    cout << "Средний балл: " << stud->get_average_score() << endl;

    // Освобождение памяти
    delete stud;

    return 0;
}