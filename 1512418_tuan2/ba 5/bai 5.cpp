#include<iostream>
#include<string>
#include <fstream>
using namespace std;

typedef struct
{
	char Ma[10];
	char HoTen[40];
} SinhVien;

void WriteFile(string FileName,int n)
{
	fstream f;
	int i;
	fflush(stdin);
	SinhVien* sv = new SinhVien[n];
	f.open(FileName, ios_base::out | ios_base::binary);
	
	for (i = 0; i < n; i++)
	{
		cout << "Sinh vien thu " <<  i << ": ";
		cout << " - MSSV: ";
		fflush(stdin);
		gets(sv[i].Ma);
		cout << " - Ho ten: ";
		fflush(stdin);
		gets(sv[i].HoTen);
		
	}
	f.write((const char*)sv, n*sizeof(SinhVien));

	delete[] sv;
	f.close();
}

void ReadFile(string FileName, int n)
{
	fstream f;
	
	f.open(FileName, ios_base::in | ios_base::binary);
	SinhVien* sv = new SinhVien[n];
	f.read((char*)sv, n*sizeof(SinhVien));
	for (int i = 0; i < n; i++)
	{
		cout << "Sinh vien thu " << i << ": ";
		cout << " - MSSV: " << sv[i].Ma << endl;
		cout << " - Ho ten: " << sv[i].HoTen << endl;

	}
	int x;
	cout << "\n-----TIM KIEM-------\n";
	cout << "nhap so thu tu cua sv: ";
	cin >> x;
	if (x >= 1 && x <= n)
	{
		cout << "Sinh vien thu " << x << ": ";
		cout << " - MSSV: " << sv[x-1].Ma << endl;
		cout << " - Ho ten: " << sv[x-1].HoTen << endl;
	}
	else
	{
		cout << "khong tim thay!" << endl;
	}
	delete[] sv;
	f.close();
}


int main()
{
	//so sv la 3
	int n, x;
	
	do
	{
		do
		{
			cout << "\n-------nhap lua chon: ---------" << endl;
			cout << "0. thoat\n";
			cout << "1. nhap\n";
			cout << "2. xuat\n";
			cin >> x;
			if (x == 1)
			{
				cout << "Nhap so sinh vien: " << endl;
				cin >> n;
				WriteFile("input.txt", n);

			}
			if (x == 2)
			{
				ReadFile("input.txt", n);

			}
		} while (x < 0 || x >2);
	} while (x != 0);
	
	return 0;
}