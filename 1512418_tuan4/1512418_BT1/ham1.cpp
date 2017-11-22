#include "thuvien1.h"

void selectionSort(int a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		swap(a[min], a[i]);
	}
}

void insertionSort(int a[], int n)
{
	int pos, x;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		pos = i - 1;
		while (pos >= 0 && a[pos] > x)
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}

void shift(int a[], int l, int r)
{
	int x, i, j;
	i = l;
	j = 2 * i + 1;
	x = a[i];
	while (j <= r)
	{
		if (j < r)
		{
			if (a[j]<a[j + 1])
				j++;
		}

		if (a[j] <= x)
		{
			return;
		}

		else
		{
			a[i] = a[j];
			a[j] = x;
			i = j;
			j = 2 * i + 1;
			x = a[i];
		}
	}
}
void CreateHeap(int a[], int n)
{
	int l;
	l = n / 2 - 1;
	while (l >= 0)
	{
		shift(a, l, n - 1);
		l = l - 1;
	}
}
void HeapSort(int a[], int n)
{
	int r;
	CreateHeap(a, n);
	r = n - 1;
	while (r>0)
	{
		swap(a[0], a[r]);
		r--;
		if (r>0)
			shift(a, 0, r);
	}
}

void quickSort(int a[], int l, int r)
{
	int i, j, x;
	x = a[(l + r) / 2];
	i = l;
	j = r;
	do
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (l < j)
	{
		quickSort(a, l, j);
	}
	if (r > i)
	{
		quickSort(a, i, r);
	}
}
void docFile(int x, string s1, string s2)
{
	fstream f1(s2, ios::out);
	fstream f(s1, ios::in);
	int n;
	f >> n;
	f.ignore();
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		f >> a[i];
	}
	if (x == 1)
	{
		selectionSort(a, n);
	}
	if (x == 2)
	{
		insertionSort(a, n);
	}
	if (x == 3)
	{
		HeapSort(a, n);
	}
	if (x == 4)
	{
		quickSort(a, 0, n - 1);

	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
		f1 << a[i] << " ";
	}
	f.close();
	delete[] a;
}