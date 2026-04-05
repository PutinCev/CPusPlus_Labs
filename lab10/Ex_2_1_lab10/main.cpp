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
    int cardNumber;
    string category;

    // Ввод данных идентификационной карточки
    cout << "*** Ввод данных идентификационной карточки ***" << endl;
    cout << "Введите номер карточки: ";
    cin >> cardNumber;
    cin.ignore(); // Очистка буфера после ввода числа

    cout << "Введите категорию карточки (Базовый, Студенческий, Льготный и т.д.): ";
    getline(cin, category);

    // Ввод имени и фамилии студента
    cout << "\n*** Ввод данных студента ***" << endl;
    cout << "Name: ";
    getline(cin, name);

    cout << "Last name: ";
    getline(cin, last_name);

    // Оценки
    int scores[5];
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

        sum += scores[i];
    }

    // Создание объекта Student (IdCard создается внутри Student - композиция)
    Student* student02 = new Student(name, last_name, cardNumber, category);

    // Сохраняем промежуточные оценки в объект класса Student
    student02->set_scores(scores);

    // Считаем и сохраняем средний балл
    double average_score = sum / 5.0;
    student02->set_average_score(average_score);

    // Выводим данные по студенту с использованием метода display()
    cout << "\n*** Результат ***" << endl;
    cout << "Фамилия Имя\tСредний балл\tНомер карты\tКатегория" << endl;
    cout << "------------------------------------------------------------" << endl;
    student02->display();

    // Освобождаем память (IdCard удалится автоматически вместе со Student)
    delete student02;
    student02 = nullptr;

    return 0;
}