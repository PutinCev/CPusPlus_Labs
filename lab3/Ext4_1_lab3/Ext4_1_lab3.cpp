#include <iostream>
#include <cmath>
using namespace std;
#include <string>
#include <windows.h>

int addNumders(int);
int gcd(int, int);


int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	int n;
	cout << "Введите любое целое число, сумму чисел от 1 до которого следует посчитать" << endl;
	cin >> n;

	int s = addNumders(n);
	cout << "Cуммы чисел от 1 до введенного числа: " << n << " равна " << s << endl;

	int m;
	cout << "Введите дополнительно любое целое число, чтобы посчитать наибольший общий делитель" << endl;
	cin >> m;
	int d = gcd(m, n);
	cout << "Наибольший общий делитель чисел: " << n << " и " << m << " равен " << d << endl;

	return 0;
}
int addNumders(int n)
{
	if (n == 1) return 1; // выход из рекурсии
	else return (n + addNumders(n - 1));
}

int gcd(int m, int n)
{
	if (n == 0) return m;
	return gcd(n, m % n);
}
