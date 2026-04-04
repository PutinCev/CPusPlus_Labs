#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

class Student
{
public:
    // Установка имени студента
    void set_name(string student_name)
    {
        name = student_name;
    }

    // Получение имени студента
    string get_name()
    {
        return name;
    }

    // Установка фамилии студента
    void set_last_name(string student_last_name)
    {
        last_name = student_last_name;
    }

    // Получение фамилии студента
    string get_last_name()
    {
        return last_name;
    }

    // Установка промежуточных оценок
    void set_scores(int student_scores[])
    {
        for (int i = 0; i < 5; ++i) {
            scores[i] = student_scores[i];
        }
        // Автоматически пересчитываем средний балл после установки оценок
        calculate_average_score();
    }

    // Установка среднего балла (ручной режим)
    void set_average_score(double ball)
    {
        average_score = ball;
    }

    // Получение среднего балла
    double get_average_score()
    {
        return average_score;
    }

    // Вычисление среднего балла на основе оценок в массиве scores
    void calculate_average_score()
    {
        int sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum += scores[i];
        }
        average_score = sum / 5.0;
    }

    // Дополнительная функция для вывода всей информации о студенте
    void display_info()
    {
        cout << "\n      Информация о студенте(из функции класса):    " << endl;
        cout << "Имя: " << name << endl;
        cout << "Фамилия: " << last_name << endl;
        cout << "Оценки: ";
        for (int i = 0; i < 5; ++i) {
            cout << scores[i] << " ";
        }
        cout << endl;
        cout << "Средний балл: " << fixed << setprecision(2) << average_score << endl;
    }

private:
    int scores[5];      // Промежуточные оценки
    double average_score; // Средний балл
    string name;        // Имя
    string last_name;   // Фамилия
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Создание объекта класса Student
    Student student01;

    // Объявление переменных
    string name;
    string last_name;
    int scores[5];

    // Ввод имени и фамилии студента с клавиатуры
    cout << "   Ввод данных студента    " << endl;
    cout << "Name: ";
    getline(cin, name);

    cout << "Last name: ";
    getline(cin, last_name);


    int sum = 0;
    // Ввод промежуточных оценок
    cout << "\n    Ввод оценок    " << endl;
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
    student01.set_name(name);
    student01.set_last_name(last_name);

    // Сохранение промежуточных оценок в объект класса Student
    // Метод set_scores() автоматически вызовет calculate_average_score()
    student01.set_scores(scores);

    // Вывод данных о студенте с использованием метода display_info()
    student01.display_info();

    // Вывод с использованием get-методов
    cout << "\n    Вывод с использованием get-методов    " << endl;
    cout << "Average ball for " << student01.get_name() << " "
        << student01.get_last_name() << " is "
        << fixed << setprecision(2) << student01.get_average_score() << endl;

     return 0;
}