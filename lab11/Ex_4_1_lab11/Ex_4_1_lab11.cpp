#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

struct StudentGrade
{
    string name;
    char grade;
};

class GradeMap
{
private:
    vector<StudentGrade> m_map;

public:
    GradeMap() {}

    char& operator[](const string& name);
};

char& GradeMap::operator[](const string& name)
{
    // Поиск имени ученика в векторе
    for (auto& ref : m_map)
    {
        // Если нашли, возвращаем ссылку на его оценку
        if (ref.name == name)
            return ref.grade;
    }

    // Не нашли - создаём новый StudentGrade для нового ученика
    StudentGrade temp{ name, ' ' };

    // Помещаем его в конец вектора
    m_map.push_back(temp);

    // Возвращаем ссылку на его оценку
    return m_map.back().grade;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    GradeMap grades;

    // Запись данных с помощью перегруженного оператора индекса
    grades["John"] = 'A';
    grades["Martin"] = 'B';

    // Вывод данных
    cout << "John has a grade of " << grades["John"] << endl;
    cout << "Martin has a grade of " << grades["Martin"] << endl;

    // Запрос нового имени и оценки от пользователя
    cout << "\nNew name and grade?" << endl;
    string name;
    char grade;
    cin >> name >> grade;

    // Запись данных нового студента
    grades[name] = grade;

    // Вывод данных нового студента
    cout << name << " has a grade of " << grades[name] << endl;

    return 0;
}