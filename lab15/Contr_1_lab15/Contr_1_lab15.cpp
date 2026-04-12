#include <iostream>
#include <map>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Контейнер map: имя студента -> оценка
    map<string, char> grades;

    string name;
    char grade;
    char choice;

    cout << "=== Программа учета оценок студентов ===" << endl;
    cout << "=========================================" << endl;

    do {
        cout << "\nВведите имя студента: ";
        getline(cin, name);

        // Поиск студента
        auto it = grades.find(name);

        if (it != grades.end()) {
            // Студент найден
            cout << "Студент " << name << " уже имеет оценку " << it->second << endl;
            cout << "Введите новую оценку (A, B, C, D, F): ";
            cin >> grade;
            cin.ignore();

            // Устанавливаем новую оценку
            grades[name] = grade;
            cout << "Оценка для " << name << " обновлена на " << grade << endl;
        }
        else {
            // Студент не найден - добавляем нового
            cout << "Студент " << name << " не найден. Добавляем нового студента." << endl;
            cout << "Введите оценку (A, B, C, D, F): ";
            cin >> grade;
            cin.ignore();

            // Добавляем нового студента
            grades[name] = grade;
            cout << "Студент " << name << " добавлен с оценкой " << grade << endl;
        }

        cout << "\nПродолжить? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    // Вывод всех студентов
    cout << "\n=== Итоговый список студентов ===" << endl;
    if (grades.empty()) {
        cout << "Список студентов пуст!" << endl;
    }
    else {
        for (const auto& pair : grades) {
            cout << pair.first << " : " << pair.second << endl;
        }
    }

    return 0;
}