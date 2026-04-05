#include <iostream>
#include <string>
#include <windows.h>
#include "student.h"
#include "IdCard.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Ввод данных идентификационной карточки
    cout << "*** Ввод данных идентификационной карточки ***" << endl;

    int cardNumber;
    string category;

    cout << "Введите номер карточки: ";
    cin >> cardNumber;
    cin.ignore(); // Очистка буфера после ввода числа

    cout << "Введите категорию карточки (Базовый, Студенческий, Льготный и т.д.): ";
    getline(cin, category);

    // Создание объекта IdCard
    IdCard* idc = new IdCard(cardNumber, category);

    // Выделение памяти для объекта Student в куче
    Student* student02 = new Student;

    string name;
    string last_name;

    // Ввод имени с клавиатуры
    cout << "\n*** Ввод данных студента ***" << endl;
    cout << "Name: ";
    getline(cin, name);

    // Ввод фамилии
    cout << "Last name: ";
    getline(cin, last_name);

    // Оценки
    int scores[5];

    // Сумма всех оценок
    int sum = 0;

    // Ввод промежуточных оценок
    cout << "\n*** Ввод оценок ***" << endl;
    for (int i = 0; i < 5; ++i) {
        do {
            cout << "Score " << i + 1 << " (0-5): ";
            cin >> scores[i];
            if (scores[i] < 0 || scores[i] > 5) {
                cout << "Ошибка! Оценка должна быть в диапазоне 0-5. Повторите ввод." << endl;
            }
        } while (scores[i] < 0 || scores[i] > 5);

        // суммирование (для отображения)
        sum += scores[i];
    }

    // Сохранение имени и фамилии в объект класса Student
    student02->set_name(name);
    student02->set_last_name(last_name);

    // Сохраняем промежуточные оценки в объект класса Student
    student02->set_scores(scores);

    // Считаем средний балл
    double average_score = sum / 5.0;

    // Сохраняем средний балл в объект класса Student
    student02->set_average_score(average_score);

    // Привязываем идентификационную карточку к студенту
    student02->setIdCard(idc);

    // Выводим данные по студенту
    cout << "\n*** Результат ***" << endl;
    cout << "Average ball for " << student02->get_name() << " "
        << student02->get_last_name() << " is "
        << student02->get_average_score() << endl;

    // Вывод данных идентификационной карточки
    cout << "\n*** Данные идентификационной карточки ***" << endl;
    cout << "IdCard Number: " << student02->getIdCard()->getNumber() << endl;
    cout << "Category: " << student02->getIdCard()->getCategory() << endl;

    // Освобождаем память
    delete student02;
    delete idc;
    student02 = nullptr;
    idc = nullptr;

    return 0;
}