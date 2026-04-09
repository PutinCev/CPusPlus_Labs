#include <iostream>
using namespace std;
#include <windows.h>

// Шаблонный класс myarray
template<class T, class T1>
class myarray
{
public:
    myarray(int size);
    ~myarray() { delete[] data; cout << "des" << endl; }
    T1 sum();
    T average_value();
    void show_myarray();
    int add_value(T);

private:
    T* data;
    int size;
    int index;
};

// Конструктор
template<class T, class T1>
myarray<T, T1>::myarray(int size)
{
    data = new T[size];
    if (data == NULL)
    {
        cerr << "Error memory ---- exit program" << endl;
        exit(1);
    }
    myarray::size = size;
    myarray::index = 0;
}

// Сумма элементов
template<class T, class T1>
T1 myarray<T, T1>::sum()
{
    T1 sum = 0;
    for (int i = 0; i < index; i++)
        sum += data[i];
    return sum;
}

// Среднее значение
template<class T, class T1>
T myarray<T, T1>::average_value()
{
    T1 sum = 0;
    for (int i = 0; i < index; i++)
        sum += data[i];
    return (sum / index);
}

// Вывод массива
template<class T, class T1>
void myarray<T, T1>::show_myarray()
{
    for (int i = 0; i < index; i++)
        cout << data[i] << ' ';
    cout << endl;
}

// Добавление значения
template<class T, class T1>
int myarray<T, T1>::add_value(T value)
{
    if (index == size)
        return -1;  // массив полон
    else
    {
        data[index] = value;
        index++;
        return 0;   // успешно
    }
}

int main()
{

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Массив целых чисел (int, long)
    myarray<int, long> numbers(100);

    // Массив вещественных чисел (float, float)
    myarray<float, float> values(200);

    // Заполнение первого массива
    cout << "=== Массив целых чисел ===" << endl;
    for (int i = 0; i < 50; i++)
        numbers.add_value(i);

    numbers.show_myarray();
    cout << "Sum = " << numbers.sum() << endl;
    cout << "Average = " << numbers.average_value() << endl;

    // Заполнение второго массива
    cout << "\n=== Массив вещественных чисел ===" << endl;
    for (int i = 0; i < 100; i++)
        values.add_value(i * 100);

    values.show_myarray();
    cout << "Sum = " << values.sum() << endl;
    cout << "Average = " << values.average_value() << endl;

    return 0;
}