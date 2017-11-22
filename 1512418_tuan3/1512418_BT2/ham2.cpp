#include "thuvien2.h"


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
	fflush(stdin);
	while (!f.eof())
	{
		f >> a[i];
		i++;
		n++;
	}
	f.close();
}
void sapxep(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}

void ghiFile(int dem, int x, char* s, int b1)
{
	int* a = new int[b1];
	int n = 0;
	int* b = new int[b1];
	int nb = 0;
	char* s1 = "input.txt";
	taoFileRandom(s1, b1);
	docFile(s1, a, n);
	if (dem == 3)
	{
		sapxep(a, n);
		//for (int i = 0; i < b1; i++)
		//{
		//	cout << a[i] << " ";
		//}
	}

	fstream f(s, ios::out);
	if (dem == 1)
	{
		clock_t start = clock();
		timKiemTuanTu(a, n, x, b, nb);
		clock_t finish = clock();
		cout << ((float)finish - (float)start) / CLOCKS_PER_SEC << endl;
		f << ((float)finish - (float)start) / CLOCKS_PER_SEC << endl;

	}
	if (dem == 2)
	{
		clock_t start = clock();
		timKiemTuanTuCoLinhCanh(a, n, x, b, nb);

		clock_t finish = clock();
		cout << ((float)finish - (float)start) / CLOCKS_PER_SEC << endl;
		f << ((float)finish - (float)start) / CLOCKS_PER_SEC << endl;
	}
	if (dem == 3)
	{
		clock_t start = clock();
		timKiemTuanTuCoLinhCanh(a, n, x,b, nb);
		clock_t finish = clock();
		cout << ((float)finish - (float)start) / CLOCKS_PER_SEC << endl;
		f << ((float)finish - (float)start) / CLOCKS_PER_SEC << endl;
	}
	if (nb == 0)
	{
		cout << "-1" << endl;
		f << "-1" << endl;
	}
	//else
	//{
	//	cout << "\nvi tri xuat hien trong mang: \n";
	//	for (int i = 0; i < nb; i++)
	//	{
	//		cout << b[i] << " ";
	//		f << b[i] << " ";
	//	}

	//}

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


