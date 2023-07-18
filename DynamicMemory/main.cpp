#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
		cout << arr[i] << "\t";
	}
	cout << endl;

	int element;
	cout << "Добавить в конец массива число: "; cin >> element;
	int* result_arr = new int[n + 1];
	result_arr[n] = element;
	for (int i = 0; i < n; i++)
	{
		result_arr[i] = arr[i];
	}
	delete[] arr;
	
	for (int i = 0; i < n + 1; i++)
	{
		cout << result_arr[i] << "\t";
	}
	cout << endl;
	delete[] result_arr;
}