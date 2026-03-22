#include <iostream>
using namespace std;
#include <string>
#include <windows.h>

void privet(string);
void privet(string, int);


int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	int k;
	cout << "Input number:" << endl;
	cin >> k;
	string name;
	cout << "What is your name Имя?" << endl;
	cin >> name;
	privet(name);
	privet(name, k);
	return 0;

}
void privet(string name)
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	cout << name << ", " << "hello!" << endl;
}

void privet(string name, int k)
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	cout << name << ", " << "hello! " << "you input " << k << endl;
}
