#include "IdCard.h"

// Конструктор по умолчанию
IdCard::IdCard()
{
    number = 0;
    category = "Не установлена";
}

// Конструктор с номером
IdCard::IdCard(int n)
{
    number = n;
    category = "Не установлена";
}

// Конструктор с номером и категорией
IdCard::IdCard(int n, string cat)
{
    number = n;
    category = cat;
}

void IdCard::setNumber(int newNumber)
{
    number = newNumber;
}

int IdCard::getNumber()
{
    return number;
}

void IdCard::setCategory(string cat)
{
    category = cat;
}

string IdCard::getCategory()
{
    return category;
}