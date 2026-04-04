#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

class Student
{
public:
    class ExScore
    {
    public:
        string origin;   // для имени функции
        int iValue;      // для хранения ошибочного значения

        ExScore(string or_, int sc)
        {
            origin = or_;      // строка с именем виновника ошибки
            iValue = sc;       // сохраненное неправильное значение
        }
    };

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

    // Установка промежуточных оценок (с проверкой и генерацией исключения)
    void set_scores(int student_scores[])
    {

        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);

        for (int i = 0; i < 5; ++i) {
            if (student_scores[i] > 5) {
                throw ExScore("в функции set_scores()", student_scores[i]);
            }
            if (student_scores[i] < 0) {
                throw ExScore("в функции set_scores() (отрицательная оценка)", student_scores[i]);
            }
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

        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);

        cout << "\n      Информация о студенте (из функции класса):    " << endl;
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

    cout << "================================================" << endl;
    cout << "   Программа учета успеваемости студентов" << endl;
    cout << "   Оценки должны быть в диапазоне от 0 до 5" << endl;
    cout << "================================================" << endl;

    Student student01;

    string name;
    string last_name;
    int scores[5];

    cout << "\n   Ввод данных студента" << endl;
    cout << "Name: ";
    getline(cin, name);

    cout << "Last name: ";
    getline(cin, last_name);

    student01.set_name(name);
    student01.set_last_name(last_name);

    cout << "\n    Ввод оценок" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Score " << i + 1 << " (0-5): ";
        cin >> scores[i];
    }

    try
    {
        student01.set_scores(scores);

        // Вывод данных о студенте с использованием метода display_info()
        student01.display_info();

        // Вывод с использованием get-методов
        cout << "\n    Вывод с использованием get-методов" << endl;
        cout << "Average ball for " << student01.get_name() << " "
            << student01.get_last_name() << " is "
            << fixed << setprecision(2) << student01.get_average_score() << endl;
    }
    catch (Student::ExScore& ex)
    {
        cout << "\n================================================" << endl;
        cout << "!!! ОШИБКА !!!" << endl;
        cout << "Ошибка инициализации " << ex.origin << endl;
        cout << "Введенное значение оценки " << ex.iValue << " является недопустимым!" << endl;
        cout << "Допустимые значения оценок: от 0 до 5." << endl;
        cout << "================================================" << endl;
        return 1; // Завершение с кодом ошибки
    }

    cout << "\n================================================" << endl;
    cout << "Программа успешно завершена!" << endl;
    cout << "================================================" << endl;

    return 0;
}