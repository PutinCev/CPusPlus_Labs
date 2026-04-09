#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

// Концепт Sortable
template<typename T>
concept Sortable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
    { a > b } -> std::convertible_to<bool>;
};

// Функция is_sorted
template<Sortable T>
bool is_sorted(const vector<T>& container)
{
    if (container.size() <= 1) return true;

    for (size_t i = 0; i < container.size() - 1; ++i)
    {
        if (container[i + 1] < container[i]) return false;
    }
    return true;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    vector<int> v1 = { 1, 2, 3, 4, 5 };
    cout << "is_sorted: " << is_sorted(v1) << endl;

    vector<int> v2 = { 5, 3, 1, 4, 2 };
    cout << "is_sorted: " << is_sorted(v2) << endl;

    vector<string> v3 = { "apple", "banana", "cherry" };
    cout << "is_sorted: " << is_sorted(v3) << endl;

    return 0;
}