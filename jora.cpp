#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

bool posl(int a, int b) 
{
	return a % 10 < b % 10;
}

bool predposl(int a, int b)
{
	return (a / 10) % 10 < (b / 10) % 10;
}

void sortt(vector<int>& vec)
{
	sort(vec.begin(), vec.end(), predposl);
	stable_sort(vec.begin(), vec.end(), posl);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	vector<int> vec;
	int k;
	while (true)
	{
		cout << "Введите рамер масива: ";
		cin >> k;
		cout << endl;
		if (k <= 0)
		{
			cout << "Неправельный ввод" << endl << endl;
			cin.clear(); // это убирает пометку об ошибке
			cin.ignore((numeric_limits<streamsize>::max)(), '\n'); // а это чистит консоль
		}
		else
		{
			break;
		}
	}
	cout << "Содержимое массива: ";
	for (int i = 0; i < k; i++)
	{
		vec.push_back(rand() % 9989 + 10);
		cout << vec[i] << " ";
	}
	cout << endl << endl;
	sortt(vec);
	cout << "Результат сортировки массива: ";
	for (int y : vec)
	{
		cout << y << " ";
	}
	cout << endl;
}