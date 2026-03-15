// Ex2_cin_lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
	system("chcp 1251");
	string name;
	cout << "Введите свое имя\n";
	double a, b;
	cout << "Введите a и b:\n";
	cin >> a;
	cin >> name;
	cin >> b;
	double x = a / b;
	cout << "\nx = " << x << endl;
	cout << "Привет, " << name << "!\n";
	return 0;
}

