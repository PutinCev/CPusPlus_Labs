#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Шаблонная функция Print
template<typename Container>
void Print(const Container& container, const string& delimiter)
{
    bool first = true;
    for (const auto& element : container)
    {
        if (!first)
        {
            cout << delimiter;
        }
        cout << element;
        first = false;
    }
    cout << endl;
}

int main()
{
    vector<int> data = { 1, 2, 3 };
    Print(data, ", ");  // на экране: 1, 2, 3

    return 0;
}