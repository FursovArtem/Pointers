#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n--------------------------------------------------------\n"
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void fill_rand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void print(int*& arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
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


int** allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1] {};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1] {};
	buffer[0] = new int[cols] {};
	for (int i = 1; i <= rows; i++)buffer[i] = arr[i - 1];
	delete[] arr;
	rows++;
	return buffer;
}
int** insert_row(int** arr, int& rows, const int cols, const int position)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++) buffer[i < (position - 1) ? i : i + 1] = arr[i];
	buffer[position - 1] = new int[cols] {};
	delete[] arr;
	rows++;
	return buffer;
}

int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows] {};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows] {};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int** erase_row(int** arr, int& rows, const int cols, const int position)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i < (position - 1) ? i : i + 1];
	delete[] arr;
	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 1; j <= cols; j++) buffer[j] = arr[i][j - 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void insert_col(int** arr, const int rows, int& cols, const int position)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j < (position - 1) ? j : j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

void pop_col_back(int** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}
void pop_col_front(int** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
}
void erase_col(int** arr, const int rows, int& cols, const int position)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j < (position - 1) ? j : j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
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
#endif

#ifdef DYNAMIC_MEMORY_2
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество столбцов: "; cin >> cols;

	int** arr = allocate(rows, cols);

	fill_rand(arr, rows, cols);
	print(arr, rows, cols);
	cout << delimiter;
	arr = push_row_back(arr, rows, cols);
	print(arr, rows, cols);
	cout << delimiter;
	arr = push_row_front(arr, rows, cols);
	print(arr, rows, cols);
	cout << delimiter;
	int position;
	cout << "Добавить ряд на позицию: "; cin >> position;
	arr = insert_row(arr, rows, cols, position);
	print(arr, rows, cols);
	cout << delimiter;
	arr = pop_row_back(arr, rows, cols);
	print(arr, rows, cols);
	cout << delimiter;
	arr = pop_row_front(arr, rows, cols);
	print(arr, rows, cols);
	cout << delimiter;
	cout << "Удалить ряд: "; cin >> position;
	arr = erase_row(arr, rows, cols, position);
	print(arr, rows, cols);
	cout << delimiter;
	push_col_back(arr, rows, cols);
	print(arr, rows, cols);
	cout << delimiter;
	push_col_front(arr, rows, cols);
	print(arr, rows, cols);
	cout << delimiter;
	cout << "Добавить столбик: "; cin >> position;
	insert_col(arr, rows, cols, position);
	print(arr, rows, cols);
	cout << delimiter;
	pop_col_back(arr, rows, cols);
	print(arr, rows, cols);
	cout << delimiter;
	pop_col_front(arr, rows, cols);
	print(arr, rows, cols);
	cout << delimiter;
	cout << "Удалить столбик: "; cin >> position;
	erase_col(arr, rows, cols, position);
	print(arr, rows, cols);
	cout << delimiter;

	clear(arr, rows);
#endif
}