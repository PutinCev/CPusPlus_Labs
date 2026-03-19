#include <iostream>
#include <math.h>
using namespace std;
#include <windows.h>


int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	int a, b, temp;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	while (a != b)
	{
		if (a > b)
			a -= b; // аналогично выражению a = a - b
		else
			b -= a;
	}
	cout << "НОД = " << a << endl;
	return 0;
}