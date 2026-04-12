#include <iostream>
#include <windows.h>
#include <string>
#include "student.h"
#include "IdCard.h"
#include "Group.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Создание карточек
    IdCard* idc = new IdCard(123456, "Базовый");
    IdCard* idc2 = new IdCard(654321, "Студенческий");

    string name;
    string last_name;

    // Ввод первого студента
    cout << "Name: ";
    getline(cin, name);
    cout << "Last name: ";
    getline(cin, last_name);

    Student* student02 = new Student(name, last_name, idc);

    int scores[5];
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        cout << "Score " << i + 1 << ": ";
        cin >> scores[i];
        sum += scores[i];
    }

    student02->set_scores(scores);
    double average_score = sum / 5.0;
    student02->set_average_score(average_score);

    cout << "Average ball for " << student02->get_name() << " "
        << student02->get_last_name() << " is "
        << student02->get_average_score() << endl;

    cout << "IdCard: " << student02->getIdCard().getNumber() << endl;
    cout << "Category: " << student02->getIdCard().getCategory() << endl;

    cin.ignore();

    // Создание дополнительных студентов
    Student student03("Петр", "Петров", idc2);
    Student student04("Семен", "Смирнов", idc);
    Student student05("Саша", "Коен", idc2);
    Student student06("Дмитрий", "Ионов", idc);

    // Установка оценок (пример)
    int def_scores[] = { 4, 4, 4, 4, 4 };
    student03.set_scores(def_scores);
    student04.set_scores(def_scores);
    student05.set_scores(def_scores);
    student06.set_scores(def_scores);
    student03.set_average_score(4);
    student04.set_average_score(4);
    student05.set_average_score(4);
    student06.set_average_score(4);

    // Создание группы
    Group gr1957("1957");

    // Добавление студентов
    gr1957.addStudent(*student02);
    gr1957.addStudent(student03);
    gr1957.addStudent(student04);
    gr1957.addStudent(student05);
    gr1957.addStudent(student06);

    int k = gr1957.getSize();

    // Сортировка и вывод
    gr1957.GroupSort();
    cout << "В группе " << gr1957.getName() << " " << k << " ст." << endl;
    gr1957.GroupOut();

    // Удаление студента
    gr1957.delStudent(gr1957.findStudent("Семен", "Смирнов"));

    // Вывод после удаления
    cout << "В группе " << gr1957.getName() << " " << gr1957.getSize() << " ст." << endl;
    gr1957.GroupOut();

    delete student02;
    delete idc;
    delete idc2;

    return 0;
}