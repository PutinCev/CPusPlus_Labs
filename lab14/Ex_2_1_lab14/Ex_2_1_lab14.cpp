#include <iostream>
#include <windows.h>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

// Шаблонная функция для вывода кортежа из трех элементов
template<class Tuple>
void printTupleOfThree(Tuple t)
{
    cout << "("
         << std::get<0>(t) << ", "
         << std::get<1>(t) << ", "
         << std::get<2>(t) << ")" << endl;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    vector<string> v1{ "one", "two", "three", "four", "five", "six" };
    vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
    vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
    
    // Кортеж типа (string, int, double)
    auto t0 = make_tuple(v1[0], v2[0], v3[0]);
    printTupleOfThree(t0);
    
    // Кортеж типа (string, string, int)
    auto t3 = make_tuple(v1[0], v1[1], v2[2]);
    printTupleOfThree(t3);
    
    return 0;
}