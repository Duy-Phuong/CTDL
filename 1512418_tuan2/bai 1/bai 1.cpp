#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <time.h>



int main()
{
	//bai 1

	fstream f;
	fstream f1;
	f1.open("input1.txt", ios_base::out);
	f.open("input.txt", ios_base::out | ios_base::binary);
	srand(time(NULL));
	int a;
	for (int i = 0; i < 10000; i++)
	{
		a = rand() % 100;
		f1 << a << " ";
		f.write((const char*)&a, sizeof(a));
	}
	f.close();
	f1.close();

	fstream f0;
	fstream f10;
	f10.open("input1.txt", ios_base::in);
	f0.open("input.txt", ios_base::in | ios_base::binary);
	int length, length1;
	f0.seekg(0, ios::end);
	length = f0.tellg();
	f0.seekg(0, ios::beg);
	cout << "kich thuoc tap tin nhi phan la input.txt: " << length << endl;
	f10.seekg(0, ios::end);
	length1 = f10.tellg();
	f10.seekg(0, ios::beg);
	cout << "kich thuoc tap tin text la input1.txt: " << length1 << endl;



	int b;
	for (int i = 0; i < 3; i++)
	{
		f10 >> b;
		cout << b << endl;
	}
	cout << "\nbinary: \n";
	for (int i = 0; i < 3; i++)
	{
		f0.read((char*)&b, sizeof(b));
		cout << b << endl;
	}

	//bai 2
	//doc du lieu tu tap tin input cua bai 1
	int i1 = 0;
	while (!f10.eof())
	{
		f10 >> b;
		i1++;
		cout << b << " ";
		if (i1 % 15 == 0)
			cout << endl;
	}



	f0.close();
	f10.close();

	//bai 3
	cout << "\nbai3 + 4 : nhap doan van: \n";
	string s;
	fstream f3("1512418.txt", ios_base::out );
	fflush(stdin);
	getline(cin, s);
	while (s != "end")
	{
		f3 << s << endl;
		fflush(stdin);
		getline(cin, s);
	}

	//bai 4
	int* z = new int[26];
	for (int i = 0; i < 26; i++)
	{
		z[i] = 0;
	}

	cout << "\nbai 4: \n";
	string s1;
	fstream f4("1512418.txt", ios_base::in);
	while (!f4.eof())
	{
		fflush(stdin);
		getline(f4, s1);
		for (int i = 0; i < s1.length(); i++)
		{
			int tam = 0;
			if (s1[i] >= 'a' && s1[i] <= 'z')
			{
				tam = s1[i] - 97;
				z[tam]++;
			}
			else if (s1[i] >= 'A' && s1[i] <= 'Z')
			{
				tam = s1[i] - 65;
				z[tam]++;
			}
		}
		cout << s1 << endl;
	}
	cout << "-------so lan xuat hien cac ki tu -------" << endl;
	char dem = 'A';
	for (int i = 0; i < 26; i++)
	{
		cout << "ki tu "<< dem << " xuat hien : " << z[i] << " lan\n";
		dem++;
	}
	
	f3.close();
	f4.close();



	return 0;
}