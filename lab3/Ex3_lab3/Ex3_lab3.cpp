#include <iostream>
#include <cmath>
using namespace std;
#include <string>
#include <windows.h>

long double firBinSearch(double, int);

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	double a;
	cout << "Введите число корень которого будем искать: " << endl;
	cin >> a;
	int n;
	cout << "Введите степень корня: " << endl;
	cin >> n;

	long r = firBinSearch(a, n);
	cout << "Корень степени : " << n << " числа " << a << " равен " << r << endl;
	
	return 0;

}
long double firBinSearch(double a, int n)
{
	double L = 0;
	double R = a;
	while (R - L > 1e-10)
	{
		double M = (L + R) / 2;
		if (pow(M, n) < a)
		{
			L = M;
		}
		else
		{
			R = M;
		}
	}
	return R;
}
