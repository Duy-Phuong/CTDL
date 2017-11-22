#include "thuvien1.h"

//bai1
void timKiemTuanTu(int a[], int n, int x, int b[], int &nb)
{
	int i = 0; 
	nb = 0;
	while (i < n)
	{
		if (a[i] == x)
		{
			b[nb++] = i;
		}
		i++;
	}

}

void timKiemTuanTuCoLinhCanh(int a[], int n, int x, int b[], int &nb)
{
	int i = 0;
	a[n] = x;
	nb = 0;
	while (i != n)
	{
		if (a[i] == x)
		{
			b[nb++] = i;
		}
		i++;
	}
}

void timNhiPhan(int a[], int n, int x, int b[], int &nb)
{
	int left = 0;
	int right = n - 1;
	int mid;
	nb = 0;
	do
	{
		mid = (left + right) / 2;
		if (x == a[mid])
		{
			b[nb++] = mid;
		}
		else
		{
			if (x < a[mid])
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}

	} while (left <= right);
}

void docFile(char* s, int a[], int &n)
{
	fstream f(s, ios::in);
	int i = 0;
	f >> n;
	f.ignore();
	while (i <= n)
	{
		f >> a[i];
		i++;
	}
	f.close();
}
void ghiFile(int dem, int x, char* s, char* s1)
{
	int a[100];
	int n;
	int b[100];
	int nb = 0;
	docFile(s1, a, n);
	fstream f(s, ios::out);
	if (dem == 1)
	{
		timKiemTuanTu(a, n, x, b, nb);

	}
	if (dem == 2)
	{
		timKiemTuanTuCoLinhCanh(a, n, x, b, nb);
	}
	if (dem == 3)
	{
		timKiemTuanTuCoLinhCanh(a, n, x, b, nb);
	}
	if (nb == 0)
	{
		cout << "-1" << endl;
		f << "-1" << endl;
	}
	else
	{
		cout << "\nvi tri xuat hien trong mang: \n";
		for (int i = 0; i < nb; i++)
		{
			cout  << b[i] << " ";
			f << b[i] << " ";
		}
		
	}
	f.close();
}