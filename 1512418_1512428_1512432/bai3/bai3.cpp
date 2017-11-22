#include<iostream>
#include<string>
using namespace std;
#include <cmath>

class HU{
protected:
	int data[128];
	int size;
public:
	HU();
	void nhap();
	void cong(HU, HU);
	void congthapphan(HU, HU);
	void truthapphan(HU, HU);
	bool kiemtrasolonhon(HU, HU);
	void nhan(HU, HU);
	void xuat();
};

HU::HU(){
	size = 0;
	for (int i = 0; i< 128; i++) data[i] = 0;
}

void HU::nhap(){
	string  str;
	cout << "\nNhap: ";
	cin >> str;
	size = str.size();
	for (int i = 0; i < size; i++)
	{
		data[128 + i - size] = str.at(i) - '0';
	}
}

void HU::cong(HU a, HU b){
	int nho = 0;
	size = (a.size > b.size) ? a.size : b.size;
	for (int i = 128 - 1; i >= 1; i--)//bit dau the hien dau
	{
		int tg = a.data[i] + b.data[i] + nho;
		//nho = tg / 10;
		//data[i] = tg % 10;
		if (tg == 2)
		{
			data[i] = 0;
			nho = 1;
		}
		if (tg == 3)
		{
			data[i] = 1;
			nho = 1;
		}
		if (tg == 1 || tg == 0)
		{
			data[i] = tg;
			nho = 0;
		}

	}
}

void HU::congthapphan(HU a, HU b)
{
	int nho = 0;
	size = (a.size > b.size) ? a.size : b.size;
	for (int i = 128 - 1; i >= 1; i--)
	{
		int tg = a.data[i] + b.data[i] + nho;
		nho = tg / 10;
		data[i] = tg % 10;

	}
}


int main(){
	HU a, b, kqc;


	a.nhap();
	b.nhap();
	kqc.cong(a, b);

	a.xuat(); cout << " + "; b.xuat(); cout << " = "; kqc.xuat();



}