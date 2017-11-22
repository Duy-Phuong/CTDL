
#include "thuvien5.h"


void shift(vector<CN> &a, int l, int r)
{
	int i, j;
	CN x;
	i = l;
	j = 2 * i + 1;
	x = a[i];
	while (j <= r)
	{
		if (j < r)
		{
			if (a[j].birth_year < a[j + 1].birth_year)
				j++;
		}

		if (a[j].birth_year <= x.birth_year)
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
void CreateHeap(vector<CN> &a)
{
	int l;
	int n = a.size();
	l = n / 2 - 1;
	while (l >= 0)
	{
		shift(a, l, n - 1);
		l = l - 1;
	}
}
void HeapSort(vector<CN> &a)
{
	int r;
	CreateHeap(a);
	r = a.size() - 1;
	while (r>0)
	{
		swap(a[0], a[r]);
		r--;
		if (r>0)
			shift(a, 0, r);
	}
	for(int i = 0; i < a.size()-1; i++)
	{
		for (int j = i + 1; j < a.size(); j++)
		{
			if (a[i].birth_year == a[j].birth_year)
			{
				if (a[i].name[0] > a[j].name[0])
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
	vector <CN> a;
	CN tam;
	while (!f.eof())
	{
		fflush(stdin);
		getline(f, tam.ID, ',');
		getline(f, tam.name, ',');
		f >> tam.birth_year;
		f.ignore();
		a.push_back(tam);
	}
	HeapSort(a);

	cout << "id, name, birth year" << endl;
	f1 << "id, name, birth year" << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i].ID << "," << a[i].name << "," << a[i].birth_year << endl;
		f1 << a[i].ID << "," << a[i].name << "," << a[i].birth_year << endl;
	}

	f.close();
	f1.close();
}