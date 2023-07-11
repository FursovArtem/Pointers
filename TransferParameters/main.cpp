#include <iostream>
using namespace std;

void exchange(int& a, int& b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}

void main()
{
	setlocale(LC_ALL, "");
	int a = 2, b = 3;
	exchange(a, b);
	cout << a << b;
}