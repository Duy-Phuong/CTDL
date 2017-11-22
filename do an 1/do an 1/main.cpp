#include "QInt.h"

int main()
{
	//-1 la bat tat ca cac bit, 0 là tat**

	//QInt a;
	////QInt c;
	//a.nhap();
	//c.nhap();
	//a.onBit(31);
	//a.onBit(127);
	//a.offBit(31);
	//a.timBu2NhiPhan(a);
	//cout << "\na" << endl;
	//a.xuat();
	////c = a;
	//cout << "\nc" << endl;
	//c.xuat();
	//~a;
	//a & c;
	//a << 3;
	//string s = a.ConvertBinary2(a);
	//cout << "\n s: " << s << endl;
	//a.xuat();
	//cout << endl;
	//c.xuat();
	//a >> 1;
	//a.ror();
	//a.rol();
	//QInt b;
	//b = a - c;
	cout << "\n-------------KQ-----------\n";
	//a.xuat();
	//b.xuat();

	//string s;
	//fflush(stdin);
	//getline(cin, s);
	//a.ConvertHexa(s);
	//s = a.ConvertBinaryTo16(a);
	//cout << "\nsau khi doi qua hexan: " << s << endl;

	//int n = 2147483648-1;
	//cout << n;

	

	//while (1)
	//{ 
		//string s;
		//cout << "nhap so: " << endl;
		//fflush(stdin);
		//getline(cin, s);
		//
		//{
		//	
		//	string max1 = "170141183460469231731687303715884105727";
		//	if (s > max1)
		//	{
		//		cout << "tran so!" << endl;
		//	}
		//}
		//}
		//QInt a;
		/////a = a.ConvertDecimal(s);
		////a.xuat();
		//string s2 = a.ConvertBinary2(a);
		//cout << "\nsau khi doi sang thap luc phan:\n";
		//cout << s2 << endl;
	//}
	//string s1;
	//cout << "\nnhap so thap luc phan: " << endl;
	//fflush(stdin);
	//getline(cin, s1);
	//QInt a1;

	//a1.ConvertHexa(s1);
	//cout << "\nsau khi doi sang nhi phan:\n";
	//a1.xuat();
	//cout << endl;

	//QInt c;
	//cout << "\nc: " << endl;
	//c = a / a1;
	//c.xuat();
	//string s2 = c.ConvertBinary2(c);
	///cout << "\nsau khi doi:\n";
	//cout << s2 << endl;
	
	//string s;
	//fflush(stdin);
	//getline(cin, s);
	//string s1;
	//fflush(stdin);
	//getline(cin, s1);
	//string s2;
	//s2 = nhanthapphan(s, s1);
	//cout << s2;

	//string s;
	//fflush(stdin);
	//getline(cin, s);
	//QInt a(s);
	//a.xuat();
	//cout << endl;
	//string s1;
	//fflush(stdin);
	//getline(cin, s1);
	//
	//QInt b(s1);
	////b.xuat();
	//QInt c = a / b;
	//cout << endl;
	//c.xuat();
	//~a;
	//string s1 = a.ConvertBinaryTo16(a);
	//a.xuat();
	//cout << endl;
	//cout << s1 << endl;
	//cout << endl;




	fstream f;
	f.open("input.txt", ios_base::in);


	vector <string> s;
	string s1, s2, s3, s4;
	int i = 0;
	while (!f.eof())
	{

		fflush(stdin);
		getline(f, s1);
		s.push_back(s1);
		i++;
	}
	s1.clear();
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}

	cout << "ket qua sau khi thuc hien phep toan: " << endl;
	int x, y, z, t;
	vector <string> bien;

	for (int j = 0; j < s.size(); j++)
	{
		while (1)
		{
			x = s[j].find(' ', 0);
			if (x == -1)
			{
				bien.push_back(s[j]);
				//cout << bien[k] << endl;
				break;
			}
			s1 = s[j].substr(0, x);
			bien.push_back(s1);
			s[j].erase(0, x + 1);
			//cout << "s =" << s[j] << " l = " << s[j].length() << endl;
			//cout << bien[k] << endl;
			//k++;

		//	s1.clear();
		}
		if (bien[0] == "2" && bien[1] == "10")
		{
			QInt a(bien[2]);
			string s0 = a.ConvertBinary2(a);
			cout << s0 << endl;

		}
		if (bien[0] == "10" && bien[1] == "2")
		{
			QInt a;
			a = a.ConvertDecimal(bien[2]);
			a.xuat();
			cout << endl;

		}
		if (bien[0] == "2" && bien[1] == "16")
		{
			QInt a(bien[2]);
			string s0 = a.ConvertBinaryTo16(a);
			cout << s0 << endl;

		}
		if (bien[0] == "16" && bien[1] == "2")
		{
			QInt a;
			a.ConvertHexa(bien[2]);
			a.xuat();

		}
		if ((bien[0] == "2" && bien[1] != "10") || bien[0] == "2" && bien[1] != "16")
		{
			
			QInt c;
			if (bien[2] == "+")
			{
				QInt a(bien[1]);
				QInt b(bien[3]);
				c = a + b;
				c.xuat();
				cout << endl;
			}
			if (bien[2] == "*")
			{
				QInt a(bien[1]);
				QInt b(bien[3]);
				c = a * b;
				c.xuat();
				cout << endl;
			}
			if (bien[2] == "-")
			{
				QInt a(bien[1]);
				QInt b(bien[3]);
				c = a - b;
				c.xuat();
				cout << endl;
			}
			if (bien[2] == "/")
			{
				QInt a(bien[1]);
				QInt b(bien[3]);
				c = a / b;
				c.xuat();
				cout << endl;
			}
			if (bien[2] == "&")
			{
				QInt a(bien[1]);
				QInt b(bien[3]);
				c = a & b;
				c.xuat();
				cout << endl;
			}
			if (bien[2] == "|")
			{
				QInt a(bien[1]);
				QInt b(bien[3]);
				c = a | b;
				c.xuat();
				cout << endl;
			}
			if (bien[2] == "^")
			{
				QInt a(bien[1]);
				QInt b(bien[3]);
				c = a ^ b;
				c.xuat();
				cout << endl;
			}
			if (bien[2] == ">>")
			{
				QInt a(bien[1]);
				int x;
				string::size_type sz;  
				x = stoi(bien[3], &sz);
				c = a >> x;
				c.xuat();
				cout << endl;
			}
			if (bien[2] == "<<")
			{
				QInt a(bien[1]);
				int x;
				string::size_type sz;
				x = stoi(bien[3], &sz);
				c = a << x;
				c.xuat();
				cout << endl;
			}
			if (bien[1] == "~")
			{
				QInt a(bien[2]);
				~a;
				a.xuat();
				cout << endl;
			}
			if (bien[1] == "ror")
			{
				QInt a(bien[2]);
				a.ror();
				a.xuat();
				cout << endl;
			}
			if (bien[1] == "rol")
			{
				QInt a(bien[2]);
				a.rol();
				a.xuat();
				cout << endl;
			}
		}
		//he so 10
		if ((bien[0] == "10" && bien[1] != "16") || bien[0] == "10" && bien[1] != "2")
		{

			QInt c;
			if (bien[2] == "+")
			{
				QInt a = a.ConvertDecimal(bien[1]);
				QInt b = b.ConvertDecimal(bien[3]);
				c = a + b;
				string v = c.ConvertBinary2(c);
				cout << v;
				cout << endl;
			}
			if (bien[2] == "*")
			{
				QInt a = a.ConvertDecimal(bien[1]);
				QInt b = b.ConvertDecimal(bien[3]);
				c = a * b;
				string v = c.ConvertBinary2(c);
				cout << v;
				cout << endl;
			}
			if (bien[2] == "-")
			{
				QInt a = a.ConvertDecimal(bien[1]);
				QInt b = b.ConvertDecimal(bien[3]);
				c = a - b;
				string v = c.ConvertBinary2(c);
				cout << v;
				cout << endl;
			}
			if (bien[2] == "/")
			{
				QInt a = a.ConvertDecimal(bien[1]);
				QInt b = b.ConvertDecimal(bien[3]);
				c = a / b;
				string v = c.ConvertBinary2(c);
				cout << v;
				cout << endl;
			}
			if (bien[2] == "&")
			{
				QInt a = a.ConvertDecimal(bien[1]);
				QInt b = b.ConvertDecimal(bien[3]);
				c = a & b;
				string v = c.ConvertBinary2(c);
				cout << v;
				cout << endl;
			}
			if (bien[2] == "|")
			{
				QInt a = a.ConvertDecimal(bien[1]);
				QInt b = b.ConvertDecimal(bien[3]);
				c = a | b;
				string v = c.ConvertBinary2(c);
				cout << v;
				cout << endl;
			}
			if (bien[2] == "^")
			{
				QInt a = a.ConvertDecimal(bien[1]);
				QInt b = b.ConvertDecimal(bien[3]);
				c = a ^ b;
				string v = c.ConvertBinary2(c);
				cout << v;
				cout << endl;
			}
			if (bien[2] == ">>")
			{
				QInt a = a.ConvertDecimal(bien[1]);
				int x;
				string::size_type sz;
				x = stoi(bien[3], &sz);
				c = a >> x;
				//cout << "a: " << endl;
				//a.xuat();
				//cout << "\nc: " << endl;
				//c.xuat();
				string v = c.ConvertBinary2(c);
				cout << v;
				cout << endl;
			}
			if (bien[2] == "<<")
			{
				QInt a = a.ConvertDecimal(bien[1]);
				int x;
				string::size_type sz;
				x = stoi(bien[3], &sz);
				c = a << x;
				string v = c.ConvertBinary2(c);
				cout << v;
				cout << endl;
			}
			if (bien[1] == "~")
			{
				QInt a = a.ConvertDecimal(bien[2]);
				~a;
				string v = a.ConvertBinary2(a);
				cout << v;
				cout << endl;
			}
			if (bien[1] == "ror")
			{
				QInt a = a.ConvertDecimal(bien[2]);
				a.ror();
				string v = a.ConvertBinary2(a);
				cout << v;
				cout << endl;
			}
			if (bien[1] == "rol")
			{
				QInt a = a.ConvertDecimal(bien[2]);
				a.rol();
				string v = a.ConvertBinary2(a);
				cout << v;
				cout << endl;
			}
		}
		//he so 16
		if ((bien[0] == "16" && bien[1] != "10") || bien[0] == "16" && bien[1] != "2")
		{

			QInt c;
			if (bien[2] == "+")
			{
				QInt a;
				a.ConvertHexa(bien[1]);
				QInt b;
				b.ConvertHexa(bien[3]);
				c = a + b;
				string v = c.ConvertBinaryTo16(c);
				cout << v;
				cout << endl;
			}
			if (bien[2] == "*")
			{
				QInt a;
				a.ConvertHexa(bien[1]);
				QInt b;
				b.ConvertHexa(bien[3]);
				c = a * b;
				string v = c.ConvertBinaryTo16(c);
				cout << v;
				cout << endl;
			}
			if (bien[2] == "-")
			{
				QInt a;
				a.ConvertHexa(bien[1]);
				QInt b;
				b.ConvertHexa(bien[3]);
				c = a - b;
				string v = c.ConvertBinaryTo16(c);
				cout << v;
				cout << endl;
			}
			if (bien[2] == "/")
			{
				QInt a;
				a.ConvertHexa(bien[1]);
				QInt b;
				b.ConvertHexa(bien[3]);
				c = a / b;
				string v = c.ConvertBinaryTo16(c);
				cout << v;
				cout << endl;
			}
			if (bien[2] == "&")
			{
				QInt a;
				a.ConvertHexa(bien[1]);
				QInt b;
				b.ConvertHexa(bien[3]);
				c = a & b;
				string v = c.ConvertBinaryTo16(c);
				cout << v;
				cout << endl;
			}
			if (bien[2] == "|")
			{
				QInt a;
				a.ConvertHexa(bien[1]);
				QInt b;
				b.ConvertHexa(bien[3]);
				c = a | b;
				string v = c.ConvertBinaryTo16(c);
				cout << v;
				cout << endl;
			}
			if (bien[2] == "^")
			{
				QInt a;
				a.ConvertHexa(bien[1]);
				QInt b;
				b.ConvertHexa(bien[3]);
				c = a ^ b;
				string v = c.ConvertBinaryTo16(c);
				cout << v;
				cout << endl;
			}
			if (bien[2] == ">>")
			{
				QInt a;
				a.ConvertHexa(bien[1]);
				int x;
				//cout << "a: " << endl;
				//a.xuat();
				string::size_type sz;
				x = stoi(bien[3], &sz);
				c = a >> x;

				string v = a.ConvertBinaryTo16(a);
				cout << v;
				cout << endl;
			}
			if (bien[2] == "<<")
			{
				QInt a;
				a.ConvertHexa(bien[1]);
				int x;
				//cout << "a: " << endl;
				//a.xuat();
				string::size_type sz;
				x = stoi(bien[3], &sz);
				c = a << x;
				//cout << "\na: " << endl;
				//a.xuat();
				//cout << "\nc: " << endl;
				//c.xuat();
				string v = a.ConvertBinaryTo16(a);
				cout << v;
				cout << endl;
			}
			if (bien[1] == "~")
			{
				QInt a;
				a.ConvertHexa(bien[2]);/////////////**************
				~a;
					
				string v = a.ConvertBinaryTo16(a);
				cout << v;
				cout << endl;
			}
			if (bien[1] == "ror")
			{
				QInt a;
				a.ConvertHexa(bien[2]);
				//cout << "\na: " << endl;
				//a.xuat();
				a.ror();
				//cout << "\na: " << endl;
				//a.xuat();
				//cout << "\nc: " << endl;
				//c.xuat();
				string v = a.ConvertBinaryTo16(a);
				cout << v;
				cout << endl;
			}
			if (bien[1] == "rol")
			{
				QInt a;
				a.ConvertHexa(bien[2]);
				//cout << "\na: " << endl;
				//cout << a.ConvertBinary2(a) << endl;
				//a.xuat();
				a.rol();
				//cout << a.ConvertBinary2(a) << endl;
				//cout << "\na: " << endl;
				//a.xuat();
				//cout << "\nc: " << endl;
				//c.xuat();
				string v = a.ConvertBinaryTo16(a);
				cout << v;
				cout << endl;
			}

		}
		
		bien.clear();
		s1.clear();
	}



	f.close();
	
	return 0;
}