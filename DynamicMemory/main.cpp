#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n--------------------------------------------------------\n"
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void fill_rand(int arr[], const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void fill_rand(double arr[], const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		*(arr + i) = rand() % 10000;
		*(arr + i) /= 100;
	}
}

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
void fill_rand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10000;
			arr[i][j] /= 100;
		}
	}
}

template <typename T> void print(T* arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template <typename T> void print(T** arr, const int rows, const int cols)
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

template <typename T> T* push_back(T* arr, int& rows, T element)
{
	T* temp = new T[rows + 1];
	for (int i = 0; i < rows; i++) temp[i] = arr[i];
	delete[] arr;
	temp[rows] = element;
	rows++;
	return temp;
}
template <typename T> T* push_front(T* arr, int& rows, T element)
{
	T* temp = new T[rows + 1];
	for (int i = 1; i <= rows; i++)
	{
		temp[i] = arr[i - 1];
	}
	delete[] arr;
	temp[0] = element;
	rows++;
	return temp;
}
template <typename T> T* insert(T* arr, int& rows, T element, int position)
{
	T* temp = new T[rows + 1];
	for (int i = 0; i < position - 1; i++)
	{
		temp[i] = arr[i];
	}
	temp[position - 1] = element;
	for (int i = position; i <= rows; i++)
	{
		temp[i] = arr[i - 1];
	}
	delete[] arr;
	rows++;
	return temp;
}

template <typename T> T* pop_back(T* arr, int& rows)
{
	T* temp = new T[rows - 1];
	rows--;
	for (int i = 0; i < rows; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	return temp;
}
template <typename T> T* pop_front(T* arr, int& rows)
{
	T* temp = new T[rows - 1];
	rows--;
	for (int i = 1; i <= rows; i++)
	{
		temp[i - 1] = arr[i];
	}
	delete[] arr;
	return temp;
}
template <typename T> T* erase(T* arr, int& rows, int position)
{
	T* temp = new T[rows - 1];
	rows--;
	for (int i = 0; i < position - 1; i++)
	{
		temp[i] = arr[i];
	}
	for (int i = position; i <= rows; i++)
	{
		temp[i - 1] = arr[i];
	}
	delete[] arr;
	return temp;
}

template <typename T> T** allocate(const int rows, const int cols)
{
	T** arr = new T * [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols]{};
	}
	return arr;
}
template <typename T> void clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

template <typename T> T** push_row_back(T** arr, int& rows, const int cols)
{
	return push_back(arr, rows, new T[cols]{});
}
template <typename T> T** push_row_front(T** arr, int& rows, const int cols)
{
	return push_front(arr, rows, new T[cols]{});
}
template <typename T> T** insert_row(T** arr, int& rows, const int cols, const int position)
{
	return insert(arr, rows, new T[cols]{}, position);
}

template <typename T> T** pop_row_back(T** arr, int& rows, const int cols)
{
	return pop_back(arr, rows);
	delete[] arr[rows - 1];
}
template <typename T> T** pop_row_front(T** arr, int& rows, const int cols)
{
	return pop_front(arr , rows);
	delete[] arr[rows - 1];
}
template <typename T> T** erase_row(T** arr, int& rows, const int cols, const int position)
{
	return erase(arr, rows, position);
	delete[] arr[rows - 1];
}

template <typename T> void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_back(arr[i], cols, T());
		cols--;
	}
	cols++;
}
template <typename T> void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_front(arr[i], cols, T());
		cols--;
	}
	cols++;
}
template <typename T> void insert_col(T** arr, const int rows, int& cols, const int position)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = insert(arr[i], cols, T(), position);
		cols--;
	}
	cols++;
}

template <typename T> void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = pop_back(arr[i], cols);
		cols++;
	}
	cols--;
}
template <typename T> void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = pop_front(arr[i], cols);
		cols++;
	}
	cols--;
}
template <typename T> void erase_col(T** arr, const int rows, int& cols, const int position)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = erase(arr[i], cols, position);
		cols++;
	}
	cols--;
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int rows;
	cout << "Введите размер массива: "; cin >> rows;
	int* arr = new int[rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = i;
	}
	print(arr, rows);

	int element;
	cout << "Добавить в конец массива число: "; cin >> element;
	arr = push_back(arr, rows, element);
	print(arr, rows);

	cout << "Добавить в начало массива число: "; cin >> element;
	arr = push_front(arr, rows, element);
	print(arr, rows);

	int position;
	cout << "Добавить число: "; cin >> element;
	cout << "На позицию: "; cin >> position;
	arr = insert(arr, rows, element, position);
	print(arr, rows);

	cout << "Удалить последнее число из массива" << endl;
	arr = pop_back(arr, rows);
	print(arr, rows);

	cout << "Удалить первое число из массива" << endl;
	arr = pop_front(arr, rows);
	print(arr, rows);

	cout << "Удалить число на позиции: "; cin >> position;
	arr = erase(arr, rows, position);
	print(arr, rows);
	delete[] arr;
#endif

#ifdef DYNAMIC_MEMORY_2
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество столбцов: "; cin >> cols;

	double** arr = allocate<double>(rows, cols);

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