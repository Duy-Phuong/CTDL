#include "thuvien4.h"

void interchangeSort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] % 2 == 0 && a[j] % 2 == 0)
			{
				if (a[i] > a[j])
				{
					swap(a[i], a[j]);
				}
			}
			if (a[i] % 2 != 0 && a[j] % 2 != 0)
			{
				if (a[i] < a[j])
				{
					swap(a[i], a[j]);
				}
			}
		}
	}
}


void docFile(string s1, string s2)
{

		fstream f(s1, ios::in);
		fstream f1(s2, ios::out);
		int n;
		f >> n;
		f.ignore();
		int* a = new int[n];
		for (int i = 0; i < n; i++)
		{
			f >> a[i];
		}
		interchangeSort(a, n);

		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
			f1 << a[i] << " ";
		}
		f.close();
		f1.close();
		delete[] a;

}