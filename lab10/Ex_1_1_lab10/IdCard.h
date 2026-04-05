#pragma once

#include <string>
using namespace std;

class IdCard
{
private:
    int number;
    string category;

public:
    // Конструкторы
    IdCard();
    IdCard(int);
    IdCard(int, string);

    // Методы доступа
    void setNumber(int newNumber);
    int getNumber();
    void setCategory(string cat);
    string getCategory();
};