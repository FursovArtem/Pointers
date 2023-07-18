#include <iostream>
using namespace std;

void fill_rand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	fill_rand(arr, n);
	print(arr, n);

	int odd_num = 0, even_num = 0;
	for (int i : arr)
	{
		i % 2 == 0 ? even_num++ : odd_num++;
	}

	int* odd = new int[odd_num];
	int* even = new int[even_num];

	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			*(even + j) = arr[i];
			j++;
		}
		else
		{
			*(odd + k) = arr[i];
			k++;
		}
	}

	print(odd, odd_num);
	print(even, even_num);

	delete[] odd;
	delete[] even;
}