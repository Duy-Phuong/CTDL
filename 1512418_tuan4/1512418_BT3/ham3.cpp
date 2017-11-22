#include "thuvien3.h"

void selectionSort(int a[], int n)
{
	int max;
	for (int i = 0; i < n - 1; i++)
	{
		max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] > a[max])
			{
				max = j;
			}
		}
		swap(a[max], a[i]);
	}
}

void insertionSort(int a[], int n)
{
	int pos, x;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		pos = i - 1;
		while (pos >= 0 && a[pos] < x)
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
			if (a[j] > a[j + 1])
				j++;
		}

		if (a[j] >= x)
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
		while (a[i] > x) i++;
		while (a[j] < x) j--;
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

	if (x == 1)
	{
		fstream f(s1, ios::in);
		int n;
		f >> n;
		f.ignore();
		int* a = new int[n];
		for (int i = 0; i < n; i++)
		{
			f >> a[i];
		}
		selectionSort(a, n);

		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		f.close();
		delete[] a;
	}
	if (x == 2)
	{
		fstream f(s1, ios::in);
		int n;
		f >> n;
		f.ignore();
		int* a = new int[n];
		for (int i = 0; i < n; i++)
		{
			f >> a[i];
		}
		insertionSort(a, n);

		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		f.close();
		delete[] a;
	}
	if (x == 3)
	{
		fstream f(s1, ios::in);
		int n;
		f >> n;
		f.ignore();
		int* a = new int[n];
		for (int i = 0; i < n; i++)
		{
			f >> a[i];
		}
		HeapSort(a, n);
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		f.close();
		delete[] a;
	}
	if (x == 4)
	{
		fstream f(s1, ios::in);
		int n;
		f >> n;
		f.ignore();
		int* a = new int[n];
		for (int i = 0; i < n; i++)
		{
			f >> a[i];
		}
		quickSort(a, 0, n - 1);
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		f.close();
		delete[] a;
	}
}


void docFile(char* s, int a[], int &n)
{
	fstream f(s, ios::in);
	int i = 0;
	fflush(stdin);
	while (!f.eof())
	{
		f >> a[i];
		i++;
		n++;
		if (f.eof())
		{
			break;
		}
	}
	f.close();
}


void taoFileRandom(char* s, int x)
{

	fstream f1;
	f1.open(s, ios_base::out);
	srand(time(NULL));
	int a;
	for (int i = 0; i < x; i++)
	{
		a = rand() % 100;
		f1 << a << " ";
	}
	f1.close();
}

void ghiFile(int dem, char* s, int b1)
{
	int* a = new int[b1];
	int n = 0;
	char* s1 = "inputBT3.txt";
	taoFileRandom(s1, b1);
	docFile(s1, a, n);

	fstream f(s, ios::out);
	if (dem == 1)
	{
		clock_t start = clock();
		selectionSort(a, n);
		clock_t finish = clock();
		cout << ((float)finish - (float)start) / CLOCKS_PER_SEC << endl;
		f << ((float)finish - (float)start) / CLOCKS_PER_SEC << endl;

	}
	if (dem == 2)
	{
		clock_t start = clock();
		insertionSort(a, n);

		clock_t finish = clock();
		cout << ((float)finish - (float)start) / CLOCKS_PER_SEC << endl;
		f << ((float)finish - (float)start) / CLOCKS_PER_SEC << endl;
	}
	if (dem == 3)
	{
		clock_t start = clock();
		HeapSort(a, n);

		clock_t finish = clock();
		cout << ((float)finish - (float)start) / CLOCKS_PER_SEC << endl;
		f << ((float)finish - (float)start) / CLOCKS_PER_SEC << endl;
	}

	if (dem == 4)
	{
		clock_t start = clock();
		quickSort(a, 0, n - 1);
		clock_t finish = clock();
		cout << ((float)finish - (float)start) / CLOCKS_PER_SEC << endl;
		f << ((float)finish - (float)start) / CLOCKS_PER_SEC << endl;
	}
	//for (int i = 0; i < n; i++)
	//{
	//	cout << a[i] << "  ";
	//}

	f.close();
}