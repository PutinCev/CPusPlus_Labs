#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    string line;
    ofstream out("poem.txt");  // создаем файл poem.txt

    if (!out) {
        cout << "Ошибка создания файла!" << endl;
        return 1;
    }

    cout << "Введите стихотворение (для завершения введите пустую строку):\n";

    while (true) {
        getline(cin, line);
        if (line.empty()) break;  // пустая строка - завершение ввода
        out << line << endl;       // записываем строку в файл
    }

    out.close();
    cout << "Стихотворение сохранено в файл poem.txt\n";

    return 0;
}