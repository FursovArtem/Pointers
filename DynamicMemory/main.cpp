#include <iostream>
using namespace std;

void print(int*& arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void push_back(int*& arr, int& n, int element)
{
	int* temp = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	arr[n] = element;
	n++;
}

void push_front(int*& arr, int& n, int element)
{
	int* temp = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		temp[i] = arr[i - 1];
	}
	delete[] arr;
	arr = temp;
	arr[0] = element;
	n++;
}

void insert(int*& arr, int& n, int element, int position)
{
	int* temp = new int[n + 1];
	for (int i = 0; i < position - 1; i++)
	{
		temp[i] = arr[i];
	}
	temp[position - 1] = element;
	for (int i = position; i <= n; i++)
	{
		temp[i] = arr[i - 1];
	}
	delete[] arr;
	arr = temp;
	n++;
}

void pop_back(int*& arr, int& n)
{
	int* temp = new int[n - 1];
	n--;
	for (int i = 0; i < n; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}

void pop_front(int*& arr, int& n)
{
	int* temp = new int[n - 1];
	n--;
	for (int i = 1; i <= n; i++)
	{
		temp[i - 1] = arr[i];
	}
	delete[] arr;
	arr = temp;
}

void erase(int*& arr, int& n, int position)
{
	int* temp = new int[n - 1];
	n--;
	for (int i = 0; i < position - 1; i++)
	{
		temp[i] = arr[i];
	}
	for (int i = position; i <= n; i++)
	{
		temp[i - 1] = arr[i];
	}
	delete[] arr;
	arr = temp;
}

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}
	print(arr, n);

	int element;
	cout << "Добавить в конец массива число: "; cin >> element;
	push_back(arr, n, element);
	print(arr, n);

	cout << "Добавить в начало массива число: "; cin >> element;
	push_front(arr, n, element);
	print(arr, n);

	int position;
	cout << "Добавить число: "; cin >> element;
	cout << "На позицию: "; cin >> position;
	insert(arr, n, element, position);
	print(arr, n);

	cout << "Удалить последнее число из массива" << endl;
	pop_back(arr, n);
	print(arr, n);

	cout << "Удалить первое число из массива" << endl;
	pop_front(arr, n);
	print(arr, n);

	cout << "Удалить число на позиции: "; cin >> position;
	erase(arr, n, position);
	print(arr, n);
	delete[] arr;
}