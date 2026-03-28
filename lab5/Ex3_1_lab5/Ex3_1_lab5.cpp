#include <iostream>
#include<cmath>
#include <windows.h>
using namespace std;


void show_array(int[], int);
bool from_min(int, int);
bool from_max(int, int);

void bubble_sort(int Arr[], int N, bool (*compare)(int a, int b))
{
    for (int i = 1;i < N;i++)
    {
        for (int j = 0;j < N - 1;j++)
        {
            if ((*compare)(Arr[j], Arr[j + 1])) swap(Arr[j], Arr[j + 1]);
        }
    }
}

void setMassiv(int* myArray,int N) {
    for (int i = 0; i < N; i++)
    {
        cout << "myArray[" << i << "]=";
        cin >> myArray[i];
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    bool (*from_f[2])(int, int) = { from_min,from_max };

    int N;
    int my_choose = 0;
    cout << "Введите размер массива\n";
    cin >> N;
    int* A = new int[N];
    setMassiv(A,N);
    //int A[N] = { 9,8,7,6,1,2,3,5,4,9 };
    cout << "1. Сортировать по возрастанию\n";
    cout << "2. Сортировать по убыванию\n";
    cin >> my_choose;
    cout << "Исходные данные: ";
    cout << "\n";
    show_array(A, N);
 /*   switch (my_choose)
    {
    case 1: bubble_sort(A, N, from_min); break;
    case 2: bubble_sort(A, N, from_max); break;
    default: cout << "\rНеизвестная операция ";
    }*/

    bubble_sort(A, N, (from_f[my_choose - 1]));

    cout << "После сортировки: ";
    cout << "\n";
    show_array(A, N);

    // ОСВОБОЖДЕНИЕ ДИНАМИЧЕСКОЙ ПАМЯТИ
    delete[] A; 

    return 0;

}

void show_array(int Arr[], const int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << Arr[i] << " ";
        cout << "\n";
    }
}

bool from_min(const int a, const int b)
{
    return a > b;
}
bool from_max(const int a, const int b)
{
    return a < b;
}

