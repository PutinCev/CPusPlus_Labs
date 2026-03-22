#include <iostream>
using namespace std;
#include <string>
#include <windows.h>

void privet(string);

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	string name;
	cout << "What is your name Имя?" << endl;
	cin >> name;
	cout << name << ", " << "hello!" << endl;
	privet(name);
	return 0;

}
void privet(string name)
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	cout << name << ", " << "hello!" << endl;
}
