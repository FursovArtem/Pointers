#include <iostream>
using namespace std;

void exchange(int& a, int& b)
{
	int buffer = a;
	a = b;
	b = buffer;
}

void main()
{
	setlocale(LC_ALL, "");
	int a = 2, b = 3;
	exchange(a, b);
	cout << a << b;
}