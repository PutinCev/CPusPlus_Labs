#include <iostream>
#include <string>
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

    virtual ~human() {}

private:
    string name;
    string last_name;
    string second_name;
};

// Производный класс teacher
class teacher : public human {
public:
    teacher(
        string last_name,
        string name,
        string second_name,
        unsigned int work_time
    ) : human(last_name, name, second_name)
    {
        this->work_time = work_time;
    }

    unsigned int get_work_time()
    {
        return this->work_time;
    }

private:
    unsigned int work_time;
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    unsigned int teacher_work_time = 40;

    // Создание объекта teacher
    teacher* tch = new teacher("Сергеев", "Дмитрий", "Сергеевич", teacher_work_time);

    // Вывод информации о преподавателе
    cout << "=== Информация о преподавателе ===" << endl;
    cout << "ФИО: " << tch->get_full_name() << endl;
    cout << "Количество часов: " << tch->get_work_time() << endl;

    // Освобождение памяти
    delete tch;

    return 0;
}