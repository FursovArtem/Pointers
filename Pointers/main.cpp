#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int arr[n]{ 3, 5, 8, 13, 21 };
	

	for (int i = 0; i < n; i++)
	{
		cout << arr + i << endl;
	}
}