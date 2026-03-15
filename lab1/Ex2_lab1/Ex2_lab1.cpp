#include <iostream>
using namespace std;

int main()
{
	system("chcp 1251");
	double a, b;
	cout << "Введите a и b:\n";
	cin >> a; // ввод с клавиатуры значения a
	cin >> b; // ввод с клавиатуры значения b
	double x = a / b; // вычисление значения x
	cout.precision(3);
	cout << "\nx = " << x << endl; //вывод результата на экран
	cout << sizeof(a / b) << endl;
	cout << sizeof(x) << endl;
	return 0;
}
