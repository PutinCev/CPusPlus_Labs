#include <iostream>
#include <string>
#include <windows.h>
#include "student.h"

using namespace std;

int main()
{

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    string name;
    string last_name;

    // Ввод имени с клавиатуры
    cout << "=== Ввод данных студента ===" << endl;
    cout << "Name: ";
    getline(cin, name);

    // Ввод фамилии
    cout << "Last name: ";
    getline(cin, last_name);

    // Передача параметров конструктору при создании объекта в куче
    Student* student02 = new Student(name, last_name);

    // Оценки
    int scores[5];

    // Сумма всех оценок
    int sum = 0;

    // Ввод промежуточных оценок
    cout << "\n=== Ввод оценок ===" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Score " << i + 1 << ": ";
        cin >> scores[i];
        // суммирование
        sum += scores[i];
    }

    // Сохраняем промежуточные оценки в объект класса Student
    student02->set_scores(scores);

    // Считаем средний балл
    double average_score = sum / 5.0;

    // Сохраняем средний балл в объект класса Student
    student02->set_average_score(average_score);

    // Выводим данные по студенту
    cout << "\n=== Результат ===" << endl;
    cout << "Average ball for " << student02->get_name() << " "
        << student02->get_last_name() << " is "
        << student02->get_average_score() << endl;

    // Удаление объекта student из памяти
    // При вызове delete автоматически сработает деструктор, который вызовет save()
    delete student02;

    return 0;
}