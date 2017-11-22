#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <time.h>
#include <sstream>

void mahoafile(string file1, string file2)
{

	fstream f, f2;
	f.open(file1, ios_base::in | ios_base::binary);
	f2.open(file2, ios_base::out | ios_base::binary);
	char** mang= new char*[50];
	for (int i = 0; i < 50; i++)
	{
		mang[i] = new char[4];
	}
	int dem = 0;
	while (!f.eof())
	{
		f.read(mang[dem], 4);
		if (f.eof()) //tránh nhận giá trị rác cuối file
			break;
		//f2.write(mang[dem], 4);
		dem++;
	}
	for (int i = 0; i < dem-1; i++)
	{
		if (i % 2 == 0)
		{
			swap(mang[i], mang[i + 1]);
		}
		
	}
	for (int i = 0; i < dem; i++)
	{
		f2.write(mang[i], 4);
	}
	f2.close();
	f.close();
}


int main()
{

	fstream f;
	f.open("input.txt", ios_base::out | ios_base::binary);
	srand(time(NULL));
	int a;
	for (int i = 1; i <= 10; i++)
	{
		//a = rand() % 100; lấy random
		a = i;
		f.write((const char*)&a, sizeof(a));
	}
	f.close();

	mahoafile("input.txt", "mahoa.txt");
	mahoafile("mahoa.txt", "filebandau.txt");
	
	fstream f0;
	int b;
	f0.open("input.txt", ios_base::in | ios_base::binary);
	while (!f0.eof())
	{
		f0.read((char*)&b, sizeof(b));
		cout << b << endl;
	}
	f0.close();

	fstream f10;
	int b1;
	cout << "\nsau khi ma hoa: " << endl;
	f10.open("filebandau.txt", ios_base::in | ios_base::binary);
	while (!f10.eof())
	{
		f10.read((char*)&b1, sizeof(b1));
		cout << b1 << endl;
	}
	f10.close();
	return 0;
}