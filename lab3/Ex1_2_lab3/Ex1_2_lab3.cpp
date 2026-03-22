#include <iostream>
using namespace std;
#include <string>
#include <windows.h>

string privet(string name)
{
	string str = name + ", " + "hello!\n";
	return str;
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	string name;
	cout << "What is your name Имя?" << endl;
	cin >> name;
	string nameOut = privet(name);
	cout << nameOut << endl;
	return 0;

}
