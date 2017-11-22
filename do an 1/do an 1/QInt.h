#include<iostream>
#include<string>
using namespace std;
#include <vector>
#include <sstream>
#include <bitset>
#include <fstream>
#pragma once
string nhanthapphan(string a, string b);
void chia2(string s, int nhiphan[128], int &j);
string nhan2(string s);
string congthapphan(string a, string b);

class QInt
{
private:
	int arrayBits[4];
public:
	QInt();
	QInt(string);
	QInt(const QInt &a);
	void nhap();
	int getBit(int x);
	void onBit(int);
	void offBit(int x);
	void resetBit();

	QInt& operator = (const QInt &a);
	QInt operator + (QInt a);
	QInt operator - (QInt a);
	QInt operator * (QInt a);
	QInt operator / (QInt a);

	QInt& operator >> (const int &a);
	QInt& operator << (const int &a);
	void ror();
	void rol();
	QInt& operator & (const QInt &a);
	QInt& operator | (const QInt &a);
	QInt& operator ^ (const QInt &a);
	QInt& operator ~ ();
	void xuat();

	void ConvertHexa(string a);
	string ConvertBinaryTo16(const QInt &a);
	QInt& ConvertDecimal(string str);
	string ConvertBinary2(QInt a);
	void timBu2NhiPhan(QInt);

	void docFile(ifstream &a);


	~QInt();
};

