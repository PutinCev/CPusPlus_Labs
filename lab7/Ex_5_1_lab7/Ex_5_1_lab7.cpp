#include <iostream>
#include <windows.h>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
using Tuple = tuple<string, int, double>;
//typedef tuple<string, int, double> Tuple;

void printTupleOfThree(tuple<string, int, double>);
Tuple funtup(string, int, double);
Tuple funtup2(string, int, double);
Tuple funtup3(string, int, double);



int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	vector<string> v1{ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

	auto t0 = make_tuple(v1[0], v2[0], v3[0]);
	printTupleOfThree(t0);

	auto t1 = funtup(v1[1], v2[1], v3[1]);
	printTupleOfThree(t1);

	auto t2 = funtup2(v1[1], v2[1], v3[1]);
	printTupleOfThree(t2);

	auto t3 = funtup3(v1[1], v2[1], v3[1]);
	printTupleOfThree(t3);

	return 0;
}

void printTupleOfThree(Tuple t)
{
	cout << "("
		<< std::get<0>(t) << ", "
		<< std::get<1>(t) << ", "
		<< std::get<2>(t) << ")" << endl;
}

Tuple funtup(string s, int a, double d)
{
	s.append("!");
	return make_tuple(s, a, d * 10);
}

Tuple funtup2(string s, int a, double d)
{
	s.append("++++");
	return make_tuple(s, a++, d);
}

Tuple funtup3(string s, int a, double d)
{
	s.append("!!!!!");
	return make_tuple(s, a*d, d + a);
}




//
//2. Теперь можно сократить запись при объявлении методов, использующих
//данный тип кортежа, исправьте объявление метода printTupleOfThree() :
//	void printTupleOfThree(Tuple t)
//	3. Проверьте, что программа работает без изменений.
//	Замечание.Для объявления псевдонима в C++11 введен новый улучшенный
//	синтаксис, который имитирует способ объявления переменных – type alias :
//using identifier = type;
//4. Замените созданный typedef на новый вариант :
//using Tuple = tuple<string, int, double>;
//5. Проверьте, что программа работает без изменений.
//6. Добавьте объявление следующей функции(логика формирования кортежа
//	может быть и другой) :
//	Tuple funtup(string s, int a, double d)
//{
//	s.append("!");
//	return make_tuple(s, a, d * 10);
//}
//44
//7. В функции main() вызовите новую функцию для создания нового
//кортежа на основе исходных данных :
//auto t1 = funtup(v1[1], v2[1], v3[1]);
//8. И выведите на экран новый кортеж :
//printTupleOfThree(t1);
//9. Постройте и протестируйте приложение.
//10.Добавьте еще одну функцию, которая будет принимать кортеж, изменять
//содержимое его переменных(на ваше усмотрение) и возвращать новый
//кортеж того же типа.
//11.Добавьте еще одну функцию, которая будет принимать кортеж, изменять
//содержимое его переменных, формировать две переменные(на ваше
//	усмотрение) и возвращать новый кортеж другого типа, состоящий из этих
//	двух элементов.