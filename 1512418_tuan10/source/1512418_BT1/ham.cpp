#include "thuvien.h"

int Brute_Force(string s, string s1)// s1 la chuoi can tim
{
	int i = 0, j = 0, m, n;
	n = s.length();
	m = s1.length();
	do
	{
		if (s[i] == s1[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	} while (i < n && j < m);
	if (j == m)
	{
		return i - j;
	}
	else if (i == n)
		return -1;
}

int KMP(string source, string T)
{
	int i = 0, j = -1;

	int n = source.length();
	int m = T.length();
	int* next = new int[m];
	next[0] = -1;
	do {
		if (j == -1 || T[i] == T[j])
		{
			i++;
			j++;
			if (T[i] == T[j])
				next[i] = next[j];
			else
				next[i] = j;
		}
		else
			j = next[j];
	} while (i < m - 1);
	i = j = 0;
	do {
		if (j == -1 || source[i] == T[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	} while (j < m && i < n);
	if (j >= m)
		return i - m;
	else
		return -1;
}

void docFile(int a, string s, string s1, string s2)
{
	fstream f(s, ios::in);
	string s0;
	string tam;
	vector <string> name;
	vector <string> data;
	char c;
	int pos;
	while (!f.eof())
	{
		pos = f.tellg();
		fflush(stdin);
		getline(f, s0, ' ');
		if (s0 == "?DB")
		{
		
			f.seekg(pos);
			f.get(c);
			fflush(stdin);
			getline(f, tam);
			name.push_back(tam);
			tam.clear();
			fflush(stdin);
			getline(f, tam);
			data.push_back(tam);
			tam.clear();
		}
		if (s0 == "?EOF")
		{
			break;
		}
		s0.clear();
	}
	
	//for (int i = 0; i < name.size(); i++)
	//{
	//	cout << name[i] << endl;
	//	cout << data[i] << endl;
	//}
	f.close();

	fstream f1(s1, ios::in);
	vector <string> truy_van;
	vector <string> data_truy_van;
	
	while (!f1.eof())
	{
		pos = f1.tellg();
		fflush(stdin);
		getline(f1, s0, ' ');
		if (s0 == "?Query")
		{
			f1.seekg(pos);
			f1.get(c);
			fflush(stdin);
			getline(f1, tam);
			truy_van.push_back(tam);
			tam.clear();
			fflush(stdin);
			getline(f1, tam);
			data_truy_van.push_back(tam);
			tam.clear();
			
		}
		if (s0 == "?EOF")
		{
			break;
		}
		s0.clear();
	}

	int k;
	int count = 0;
	fstream f2(s2, ios::out);
	clock_t start = clock();
	for (int i = 0; i < truy_van.size(); i++)
	{
		cout << truy_van[i] << endl;
		f2 << truy_van[i] << endl;
		//cout << data_truy_van[i] << endl;
		for (int j = 0; j < data.size(); j++)
		{
			if (a == 0)
			{
				k = Brute_Force(data[j], data_truy_van[i]);
			}
			if (a == 2)
			{
				k = KMP(data[j], data_truy_van[i]);
			}
			
			if (k == -1 )
			{
				if (count == 0)
				{
					cout << "NOT FOUND" << endl;
					f2 << "NOT FOUND" << endl;
				}
				
				count++;
			}
			else
			{
			//	cout << truy_van[i] << endl;
				cout << "[" << name[j] << "] at offset " << k << endl;
				f2 << "[" << name[j] << "] at offset " << k << endl;
				count++;
			}
		}
		count = 0;
	}
	clock_t finish = clock();
	cout << "Time total: ";
	cout << ((float)finish - (float)start) / CLOCKS_PER_SEC << endl;
	f2 << "Time total: ";
	f2 << ((float)finish - (float)start) / CLOCKS_PER_SEC << endl;


	f1.close();
	f2.close();
}