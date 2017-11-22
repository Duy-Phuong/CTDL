#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <time.h>
#include <sstream>

int Tinhkichthuoc(string name)
{
	fstream f0;
	f0.open(name, ios_base::in | ios_base::binary);

	int length;
	f0.seekg(0, ios::end);
	length = f0.tellg();
	f0.seekg(0, ios::beg);
	cout << "kich thuoc tap tin nhi phan .txt la: " << length << endl;
	
	f0.close();
	return length;
}

void creatfile(string filename, int n, int length)
{
	fstream f;
	int lengthfile;

	f.open(filename, ios_base::in | ios_base::binary);
	lengthfile = length / n;
	string ten;
	int fileNumber;
	stringstream ss;

	for (int i = 1; i <= n; i++)
	{
		fileNumber = i;
		ss.clear(); 
		ss.str(""); 
		ss << fileNumber;
		ten = "data" + ss.str() + ".txt";

		fstream f2(ten, ios_base::out | ios_base::binary);
		if (i == n)
		{
			lengthfile = length - (n - 1)*lengthfile;
		}
		char* s = new char[lengthfile];
		f.read(s, lengthfile);
		f2.write(s, lengthfile);
		//char a;
		//for (int i = 1; i <= lengthfile; i++)
		//{
		//	f.read((char*)&a, 1);
		//	f2.write((char*)&a, 1);
		//}
		f2.close();
		
	}
	f.close();
}

void makefile(string filename, int n)
{
	fstream f;
	int lengthfile;

	f.open(filename, ios_base::out | ios_base::binary);
	string ten;
	int fileNumber;
	stringstream ss;

	for (int i = 1; i <= n; i++)
	{
		fileNumber = i;
		ss.clear();
		ss.str("");
		ss << fileNumber;
		ten = "data" + ss.str() + ".txt";
		char a;
		fstream f2(ten, ios_base::in | ios_base::binary);
		while (!f2.eof())
		{
			f2.read((char*)&a, sizeof(a));
			if (f2.eof()) //tránh nhận giá trị rác cuối file
				break;
			f.write((char*)&a, sizeof(a));
			
		}
		
		
		f2.close();
	}
	f.close();
}


int main()
{
	//bai 1

	fstream f;
	f.open("input.txt", ios_base::out | ios_base::binary);
	srand(time(NULL));
	int a;
	for (int i = 0; i < 100; i++)
	{
		a = rand() % 100;
		f.write((const char*)&a, sizeof(a));
	}
	f.close();


	int length = Tinhkichthuoc("input.txt");
	cout << "nhap so file muon chia: ";
	int n;
	cin >> n;
	creatfile("input.txt", n, length);
	makefile("ghepfile.txt", n);

	length = Tinhkichthuoc("ghepfile.txt");

	
	return 0;
}