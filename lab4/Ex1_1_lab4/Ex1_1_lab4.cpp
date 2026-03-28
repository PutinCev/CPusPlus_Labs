#include <iostream>
using namespace std;
#include <windows.h>

void fum_value(double k, double x, double y)
{
	x = x + k;
	y = y + k;
}
void fum_ptr(double k, double* x, double* y)
{
	*x = *x + k;
	*y = *y + k;
}
void fum_ref(double k, double& x, double& y)
{
	x = x + k;
	y = y + k;
}

void print(double x, double y)
{
	cout << "x = " << x << "; y = " << y << endl;
}


int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	double k = 2.5;
	double xv = 10;
	double yv = 10;
	print(xv, yv);
	fum_value(k, xv, yv); // Передача в функцию обычного параметра
	print(xv, yv);
	fum_ptr(k, &xv, &yv); // Передача в функцию параметра указателя
	print(xv, yv);
	fum_ref(k, xv, yv); // Передача в функцию параметра ссылки
	print(xv, yv);
	return 0;

}
