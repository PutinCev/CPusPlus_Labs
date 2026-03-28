#include <iostream>
#include <fstream>
#include <cstdlib>  // для rand() и srand()
#include <ctime>    // для time()
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double sum = 0;
    int const n = 100;
    double nums[n];

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        nums[i] = (rand() % 100);
    }

    ofstream out("test", ios::out | ios::binary);
    if (!out) {
        cout << "Файл открыть невозможно\n";
        return 1;
    }

    out.write((char*)nums, sizeof(nums));

    out.close();

    cout << "Данные записаны в файл test\n\n";

    ifstream in("test", ios::in | ios::binary);
    if (!in) {
        cout << "Файл открыть невозможно";
        return 1;
    }

    in.read((char*)&nums, sizeof(nums));

    int k = size(nums);
    cout << "Считанные числа:" << endl;
    for (int i = 0; i < k; i++)
    {
        sum = sum + nums[i];
        cout << nums[i] << ' ';

        if ((i + 1) % 10 == 0)
            cout << endl;
    }
    cout << "\n\nСумма = " << sum << endl;

     in.close();

    return 0;
}
