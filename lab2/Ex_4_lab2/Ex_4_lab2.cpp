#include <iostream>
#include <ctime>
using namespace std;
#include <windows.h>


int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	srand(time(NULL));
	int k, m, s = 0;
	cin >> k;
	cin >> m;

	for (int i = 1;i <= 100;i++)
	{
		if ((i > k) && (i < m))
		{
			continue;
	
		}
		s += i;
	}

	cout << "Ответ: " << s << endl;
	return 0;
}