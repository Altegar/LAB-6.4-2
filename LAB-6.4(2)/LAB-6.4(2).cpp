// LAB-6.4(2).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// LAB_06_4(2).cpp
// Сушинський Ігор
// Лабораторна робота № 6.4
// Опрацювання та впорядкування одновимірних динамічних масивів.
// Варіант 21
// Рекурсивний спосіб

#include <iostream>
#include <iomanip>

using namespace std;

double Sum(double* a, const double n, int i)
{
	if (i < n)
	{
		if (a[i] < 0)
			return a[i] + Sum(a, n, i + 1);
		else
			return Sum(a, n, i + 1);
	}
	else
		return 0;
}

double Dob(double* a, const double n, int i)
{
	if (i == 1)
		return a[i] * Dob(a, n, i - 1);
	else
		return 0;
}

void Sort(double* a, const double n, int i, int j)    // Метод обміну (бульбашки)
{
	if (a[j] > a[j + 1])                              // якщо порушено порядок
	{                                                 // - обмін елементів місцями
		int tmp = a[j];
		a[j] = a[j + 1];
		a[j + 1] = tmp;
	}

	if (j < n - i - 1)                                // j - номер поточного елемента
		Sort(a, n, i, j + 1);                         // перехід до наступного елемента

	if (i < n - 1)                                    // i - лічильник ітерацій
		Sort(a, n, i + 1, 0);                         // перехід до наступної ітерації

	for (int i = 0; i < n; i++)
		cout << setw(3) << a[i] << " ";
	cout << "\n";
}

int main()
{
	double n;

	cout << "n = "; cin >> n;

	double* a = new double[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter element number " << i << ": ";
		cin >> a[i]; // ввожу елементи масиву
	}

	cout << "S = " << Sum(a, n, 0) << endl;
	cout << "D = " << Dob(a, n, 1) << endl;
	cout << "Sort = "; Sort(a, n, 1, 0);

	return 0;
}