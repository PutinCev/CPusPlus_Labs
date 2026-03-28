#include <iostream>
using namespace std;
#include <windows.h>

void swap(int*, int*);
void swap(int&, int&);
void print(int, int);


int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	int x = 5, y = 10;
	swap(&x, &y);
	print(x,y);
	swap(x, y);
	print(x,y);
	return 0;

}

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void swap(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void print(int x, int y)
{
	cout << "x = " << x << "; y = " << y << endl;
}
