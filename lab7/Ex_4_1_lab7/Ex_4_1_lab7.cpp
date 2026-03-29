#include <iostream>
#include <windows.h>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

void printTupleOfThree(tuple<string, int, double>);

int main(){
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	vector<string> v1{ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

	auto t0 = make_tuple(v1[0], v2[0], v3[0]);
	printTupleOfThree(t0);

	return 0;
}

void printTupleOfThree(tuple<string, int, double> t)
{
	cout << "("
		<< std::get<0>(t) << ", "
		<< std::get<1>(t) << ", "
		<< std::get<2>(t) << ")" << endl;
}
