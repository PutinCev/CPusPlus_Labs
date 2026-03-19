#include <iostream>
using namespace std;
#include<cmath>;
#include <windows.h>


int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	char op;
	cout << "Сделай свой выбор, собери авто свой мечты:\n";
	cin >> op;
	switch (op)
	{
	case 'V':
		cout << "Кондиционер хочу\n";
	case 'S':
		cout << "Радио играть должно\n";
	default:
		cout << "Колеса круглые\n";
		cout << "Мощный двигатель\n";
	}

}