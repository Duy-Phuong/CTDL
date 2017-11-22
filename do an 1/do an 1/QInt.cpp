#include "QInt.h"


QInt::QInt()
{
	for (int i = 0; i < 4; i++)
	{
		arrayBits[i] = 0;
	}

}

void QInt::resetBit()
{
	for (int i = 0; i < 4; i++)
	{
		arrayBits[i] = 0;
	}
}
void QInt::nhap()
{
	for (int i = 0; i <= 3; i++)
	{
		cout << "nhap a[" << i << "]: " << endl;
		cin >> arrayBits[i];
	}
}

QInt::QInt(string s)
{
	int data[128];
	QInt a;
	string s1;
	for (int i = 0; i< 128; i++)
	{
		data[i] = 0;
	}
	for (int i = 0; i < s.length(); i++)
	{
		data[128 + i - s.length()] = s[i] - '0';
	}
	int j = 0;
	for (int i = 127; i >= 0; i--)
	{
		if (data[i] == 0)
		{
			offBit(j);
		}
		else
		{
			onBit(j);
		}
		j++;
	}

}

QInt::QInt(const QInt &a)
{
	for (int i = 3; i >= 0; i--)
	{
		arrayBits[i] = a.arrayBits[i];
	}
}

int QInt::getBit(int x)
{
	
	//x--;	bit nhap vao khoi tru max = 128
	int i1 = x / 32;
	int vt = x % 32;
	int i;
	if (i1 == 0)
	{
		i = 3;
	}
	if (i1 == 1)
	{
		i = 2;
	}
	if (i1 == 2)
	{
		i = 1;
	}
	if (i1 == 3)
	{
		i = 0;
	}
	return (arrayBits[i] >> vt) & 1;
}
void QInt::onBit(int x)
{
	int i1 = x / 32;
	int vt = x % 32;
	int i;
	if (i1 == 0)
	{
		i = 3;
	}
	if (i1 == 1)
	{
		i = 2;
	}
	if (i1 == 2)
	{
		i = 1;
	}
	if (i1 == 3)
	{
		i = 0;
	}
	arrayBits[i] = (1 << vt) | arrayBits[i];
	
}
void QInt::offBit(int x)
{
	int i1 = x / 32;
	int vt = x % 32;
	int i;
	if (i1 == 0)
	{
		i = 3;
	}
	if (i1 == 1)
	{
		i = 2;
	}
	if (i1 == 2)
	{
		i = 1;
	}
	if (i1 == 3)
	{
		i = 0;
	}
	arrayBits[i] = ~(1 << vt) & arrayBits[i];
}

void QInt::xuat()
{
	int x = 0;
	for (int i = 127; i >= 0; i--)
	{
		if (getBit(i) != 0)
		{
			x = i;
			break;
		}
	}
	for (int i = x; i >= 0; i--)
	{
		int x = getBit(i);
		//if (i == 95 || i == 63 || i == 31)
		//{
		//	cout << endl;
		//}
		cout << x;
	}
}

QInt& QInt::operator = (const QInt &a)
{
	for (int i = 3; i >= 0; i--)
	{
		arrayBits[i] = a.arrayBits[i];
	}
	return *this;
}

QInt QInt::operator + (QInt a)
{
	QInt b;
	int nho = 0;
	for (int i = 0; i < 128; i++)
	{
		int x = a.getBit(i);
		int y = getBit(i);
		int tg = a.getBit(i) + getBit(i) + nho;

		if (tg == 2)
		{
			b.offBit(i);
			nho = 1;
		}
		if (tg == 3)
		{
			b.onBit(i);
			nho = 1;
		}
		if (tg == 1)
		{
			b.onBit(i);
			nho = 0;
		}
		if (tg == 0)
		{
			b.offBit(i);
			nho = 0;
		}
	}
	return b;
}
QInt QInt::operator - (QInt a)
{

	QInt b, c;
	QInt d(*this);
	~a;

	QInt bit1;
	bit1.arrayBits[3] = 1;

	c = a + bit1;

	b = d + c;
	return b;
}
QInt QInt::operator * (QInt a1)
{

	QInt a(*this);
	string s2 = a.ConvertBinary2(a);
	string s1 = a1.ConvertBinary2(a1);
	string s = nhanthapphan(s2, s1);
	QInt c;
	c = c.ConvertDecimal(s);
	return c;
}
QInt QInt::operator / (QInt m)
{
	QInt a;
	QInt q(*this);
	int kt = 0;
	string s1 = q.ConvertBinary2(q);
	string s2 = m.ConvertBinary2(m);
	if (s1[0] == '-' && s2[0] != '-')
	{
		q.timBu2NhiPhan(q);
		kt = 1;
		s1.clear();
	}
	
	if (s1[0] != '-' && s2[0] == '-')
	{
		m.timBu2NhiPhan(m);
		kt = 1;
		s2.clear();
	}
	if (s1[0] == '-' && s2[0] == '-')
	{
		q.timBu2NhiPhan(q);
		m.timBu2NhiPhan(m);
	}
	if (s2 == "0")
	{
		cout << "so bi chia khong hop le!" << endl;
		return a;
	}
	int k = 128;
	while (k > 0)
	{
		//SHL [A, Q]
		a << 1;
		//cout << "\na: " << endl;
		//a.xuat();
		if (q.getBit(127) == 1)
		{
			a.onBit(0);
		}
		q << 1;
		//cout << "\nq: " << endl;
		//q.xuat();
		a = a - m;
		if (a.getBit(127) == 1)
		{
			a = a + m;
			q.offBit(0);
		}
		else
		{
			q.onBit(0);
		}
		k--;
	}
	if (kt == 1)
	{
		q.timBu2NhiPhan(q);
	}
	return q;

}

QInt& QInt::operator >> (const int &a)
{
	bitset<128> foo;
	for (int i = 127; i >= 0; i--)
	{
		foo[i] = getBit(i);
	}
	foo >>= a;
	//cout << foo << endl;
	for (int i = 127; i >= 0; i--)
	{
		if (foo[i] == 1)
		{
			onBit(i);
		}
		else
		{
			offBit(i);
		}
	}
	return *this;
}
QInt& QInt::operator << (const int &a)
{
	bitset<128> foo;
	for (int i = 127; i >= 0; i--)
	{
		foo[i] = getBit(i);
	}
	foo <<= a;
	for (int i = 127; i >= 0; i--)
	{
		if (foo[i] == 1)
		{
			onBit(i);
		}
		else
		{
			offBit(i);
		}
	}
	return *this;
}
void QInt::ror()
{
	bitset<128> foo;
	int kt = 0;
	if (getBit(0) == 1)
	{
		kt = 1;
	}
	for (int i = 127; i >= 0; i--)
	{
		foo[i] = getBit(i);
	}
	foo >>= 1;
	for (int i = 127; i >= 0; i--)
	{
		if (foo[i] == 1)
		{
			onBit(i);
		}
		else
		{
			offBit(i);
		}
	}
	if (kt == 1)
	{
		onBit(127);
	}
		
}

void QInt::rol()
{
	bitset<128> foo;
	int kt = 0;
	if (getBit(127) == 1)
	{
		kt = 1;
	}
	for (int i = 127; i >= 0; i--)
	{
		foo[i] = getBit(i);
	}
	foo <<= 1;
	for (int i = 127; i >= 0; i--)
	{
		if (foo[i] == 1)
		{
			onBit(i);
		}
		else
		{
			offBit(i);
		}
	}
	if (kt == 1)
	{
		onBit(0);
	}
}
QInt& QInt::operator & (const QInt &a)
{
	QInt c(a);
	QInt d(*this);
	for (int i = 127; i >= 0; i--)
	{
		if (c.getBit(i) == 1 && d.getBit(i) == 1)
		{
			onBit(i);
		}
		else
		{

			offBit(i);
		}
	}
	return *this;
}
QInt& QInt::operator | (const QInt &a)
{
	QInt c(a);
	QInt d(*this);
	for (int i = 127; i >= 0; i--)
	{
		if (c.getBit(i) == 0 && d.getBit(i) == 0)
		{
			offBit(i);
		}
		else
		{

			onBit(i);
		}
	}
	return *this;
}
QInt& QInt::operator ^ (const QInt &a)
{
	QInt c(a);
	QInt d(*this);
	for (int i = 127; i >= 0; i--)
	{
		if (c.getBit(i) == d.getBit(i))
		{
			offBit(i);
		}
		else
		{

			onBit(i);
		}
	}
	return *this;
}
QInt& QInt::operator ~()
{
	for (int i = 127; i >= 0; i--)
	{
		int x = getBit(i);
		if (x == 1)
		{
			offBit(i);
		}
		else
		{
			onBit(i);
		}

	}
	return *this;
}

void QInt::ConvertHexa(string a)
{
	string s1;
	int kt = 0;
	int x = 0;
	if (a[0] == '-')
	{
		kt = 1;//danh dau la so am
		x++;
	}
	for (int i = x; i < a.length(); i++)
	{
		if (a[i] == '0')
		{
			s1 += "0000";
		}
		if (a[i] == '1')
		{
			s1 += "0001";
		}
		if (a[i] == '2')
		{
			s1 += "0010";
		}
		if (a[i] == '3')
		{
			s1 += "0011";
		}
		if (a[i] == '4')
		{
			s1 += "0100";
		}
		if (a[i] == '5')
		{
			s1 += "0101";
		}
		if (a[i] == '6')
		{
			s1 += "0110";
		}
		if (a[i] == '7')
		{
			s1 += "0111";
		}
		if (a[i] == '8')
		{
			s1 += "1000";

		}
		if (a[i] == '9')
		{
			s1 += "1001";

		}
		if (a[i] == 'A')
		{
			s1 += "1010";

		}
		if (a[i] == 'B')
		{
			s1 += "1011";

		}
		if (a[i] == 'C')
		{
			s1 += "1100";

		}
		if (a[i] == 'D')
		{
			s1 += "1101";

		}
		if (a[i] == 'E')
		{
			s1 += "1110";

		}
		if (a[i] == 'F')
		{
			s1 += "1111";

		}
	}
	bitset<128> foo(s1);
	QInt tam;
	for (int i = 127; i >= 0; i--)
	{
		if (foo[i] == 1)
		{
			tam.onBit(i);
		}
		else
		{
			tam.offBit(i);
		}
	}
	//so am
	if (kt == 1)
	{
		tam.timBu2NhiPhan(tam);
	}
	for (int i = 127; i >= 0; i--)
	{
		if (tam.getBit(i) == 1)
		{
			onBit(i);
		}
		else
		{
			offBit(i);
		}
	}

}

void QInt::timBu2NhiPhan(QInt a)
{
	QInt b, c;
	QInt d(*this);
	~a;
	QInt bit1;
	bit1.arrayBits[3] = 1;
	c = a + bit1;
	for (int i = 3; i >= 0; i--)
	{
		arrayBits[i] = c.arrayBits[i];
	}


}

string QInt::ConvertBinaryTo16(const QInt &a)
{
	QInt e(a);
	string s, s1;
	stringstream ss;
	int kt = 0;
	int dem = 0;
	//int b = (size) % 4;
	//int z = 128 - e.size - (4 - b);// lui ve truoc cho co the lay du 4 byte
	for (int i = 0; i  <= 127; i++) //lay theo thu tu day bit
	{
		int x = e.getBit(i);
		ss << e.getBit(i);
		dem++;
		if (dem % 4 == 0)
		{
			s = ss.str();
			for (int k = 0; k < s.length() / 2; k++)
			{
				swap(s[k], s[s.length() - 1 - k]);
			}
			if (s == "0000")
			{
				s1 += "0";
			}
			if (s == "0001")
			{
				s1 += "1";
			}
			if (s == "0010")
			{
				s1 += "2";
			}
			if (s == "0011")
			{
				s1 += "3";
			}
			if (s == "0100")
			{
				s1 += "4";
			}
			if (s == "0101")
			{
				s1 += "5";
			}
			if (s == "0110")
			{
				s1 += "6";
			}
			if (s == "0111")
			{
				s1 += "7";
			}
			if (s == "1000")
			{
				s1 += "8";

			}
			if (s == "1001")
			{
				s1 += "9";

			}
			if (s == "1010")
			{
				s1 += "A";

			}
			if (s == "1011")
			{
				s1 += "B";

			}
			if (s == "1100")
			{
				s1 += "C";

			}
			if (s == "1101")
			{
				s1 += "D";

			}
			if (s == "1110")
			{
				s1 += "E";

			}
			if (s == "1111")
			{
				s1 += "F";

			}
			s.clear(); //xoa s

			ss.clear();
			ss.str("");

		}
				
	}
	for (int i = 0; i < s1.length() / 2; i++)
	{
		swap(s1[i], s1[s1.length() - 1 - i]);
	}
	if (kt == 1)
	{
		s1.insert(0, 1, '-');
	}
	while (s1[0] == '0')
	{
		s1.erase(0, 1);
	}
	if (s1 == "")
	{
		s1 = "0";
	}
	return s1;
}

QInt& QInt::ConvertDecimal(string str)
{
	int nhiphan[128] = { 0 };
	int n;
	int kt = 0;
	if (str[0] == '-')
	{
		kt = 1;
		str.erase(0, 1);

	}
	chia2(str, nhiphan, n);
	QInt a;
	for (int i = 0; i < 128; i++)
	{
		if (nhiphan[i] == 1)
		{
			a.onBit(i);
		}
	}

	if (kt == 1)
	{
		a.timBu2NhiPhan(a);
	}
	return a;
}

void chia2(string s, int nhiphan[128], int &j)
{
	int i = 0;
	int du = 0;
	string s1;
	j = 0;

	while (s != "")
	{
		int z = s.length();
		while (i < s.length())
		{
			int x = (s[i] - '0');
			int t = ((x + du * 10) / 2) + '0';
			s1 += t;
			du = (x) % 2;
			i++;
		}
		//cout << "du la: " << du << endl;
		nhiphan[j] = du;
		j++;
		s.clear();
		s = s1;
		s1.clear();
		while (s[0] == '0')
		{
			s.erase(0, 1);
		}
		du = 0;
		i = 0;
	}
}
string nhan2(string s)
{

	int i = s.length() - 1;
	int du = 0;
	string s1;
	while (i >= 0)
	{
		int x = (s[i] - '0');
		if ((x * 2) < 10)
		{
			int t = (x * 2) + '0' + du;
			s1 += t;
			du = 0;
			i--;
		}
		else
		{
			int t = (x * 2) + '0' + du - 10;
			s1 += t;
			du = 1;
			i--;
		}

	}
	for (int i = 0; i < s1.length() / 2; i++)
	{
		swap(s1[i], s1[s1.length() - 1 - i]);
	}
	if (du == 1)
	{
		s1.insert(0, "1");
	}
	while (s1[0] == '0')
	{
		s1.erase(0, 1);
	}
	if (s1 == "")//neu nhan vs 0
	{
		s1.insert(0, "0");
	}
	return s1;


}
string QInt::ConvertBinary2(QInt a)
{
	vector <string> arr;
	string c = "2";
	string b = "1";
	string tam;
	QInt e;
	e = a;
	arr.push_back(b);
	for (int i = 1; i < 128; i++)
	{
		tam = nhan2(b);
		arr.push_back(tam);
		b.clear();
		b = tam;
		tam.clear();
		
	}
	for (int i = 0; i < 128; i++) // xuat ra mang nhi phan vs gia tri toi 2^128, so cuoi la số âm, bit dau la dau
	{
		cout << arr[i];
		cout << endl;
	}

	//neu so co dau chuyen ve bu 2
	int kt = 0;
	if (e.getBit(127) == 1)
	{
		kt = 1;
		e.timBu2NhiPhan(e);

	}
	string d ="0";
	int j = 0;
	for (int i = 0; i <= 127; i++)
	{
		if (e.getBit(i) == 1)
		{
			
			tam = congthapphan(d, arr[j]);
			d.clear();
			d = tam;
			tam.clear();
		}
		j++;
	}
	if (kt == 1)// chuyen dau lai cho so thap phan
	{
		d.insert(0, 1, '-');
	}
	return d;
}

string congthapphan(string a1, string b1)
{
	string s;
	int data[128];
	int a[128];
	int b[128];
	int nho = 0;
	int length1 = a1.length();
	int length2 = b1.length();
	for (int i = 0; i< 128; i++)
	{
		a[i] = 0;
		b[i] = 0;
		data[i] = 0;
	}
	for (int i = 0; i < length1; i++)
	{
		a[128 + i - length1] = a1[i] - '0';
	}
	for (int i = 0; i < length2; i++)
	{
		b[128 + i - length2] = b1[i] - '0';
	}
	int size = (length1 > length2) ? length1 : length2;
	for (int i = 127; i >= 0; i--)
	{
		int tg = a[i]  + b[i] + nho;
		nho = tg / 10;
		data[i] = tg % 10;
	}
	//for (int i = 0; i <= 127; i++)
	//{
	//	cout << data[i];
	//}
	for (int i = 128 - size-1; i <= 127; i++)
	{
		s += data[i] + '0';
	}
	while (s[0] == '0')
	{
		s.erase(0, 1);
	}
	if (s == "")//neu nhan vs 0
	{
		s.insert(0, "0");
	}
	return s;
}

string nhanthapphan(string a1, string b1)
{
	string s;
	int data[128];
	int a[128];
	int b[128];
	int nho = 0;
	int kt = 0;
	if (a1[0] == '-' && b1[0] != '-')
	{
		kt = 1;
		a1.erase(0, 1);
	}
	if (a1[0] != '-' && b1[0] == '-')
	{
		kt = 1;
		b1.erase(0, 1);
	}
	if (a1[0] == '-' && b1[0] == '-')
	{
		a1.erase(0, 1);
		b1.erase(0, 1);
	}
	int length1 = a1.length();
	int length2 = b1.length();
	for (int i = 0; i< 128; i++)
	{
		a[i] = 0;
		b[i] = 0;
		data[i] = 0;
	}
	for (int i = 0; i < length1; i++)
	{
		a[128 + i - length1] = a1[i] - '0';
	}
	for (int i = 0; i < length2; i++)
	{
		b[128 + i - length2] = b1[i] - '0';
	}
	int size = (length1 + length2);
	
	for (int i = 128 - 1; i >= 128 - length1; i--)
	{
		for (int j = 128 - 1; j >= 128 - length2; j--)
		{
			//int x = a.data[i];
			//int y = b.data[j];
			data[i + j - 127] += a[i] * b[j];// cong don

		}

	}
	for (int k = 128 - 1; k >= 128 - size; k--)
	{
		if (data[k] > 9)
		{
			data[k - 1] += data[k] / 10;
			data[k] %= 10;
		}
	}


	for (int i = 128 - size - 1; i <= 127; i++)
	{
		s += data[i] + '0';
	}
	while (s[0] == '0')
	{
		s.erase(0, 1);
	}
	if (s == "")//neu nhan vs 0
	{
		s.insert(0, "0");
	}
	if (kt == 1 && s != "0")
	{
		s.insert(0, "-");
	}
	return s;
	
}

//void QInt::docFile(ifstream &a)
//{
//	fstream f;
//	f.open(a, ios_base::in);
//	
//	
//	vector <string> s;
//	string s1;
//	int i = 0;
//	while (!f.eof())
//	{
//		fflush(stdin);
//		getline(f, s1, ' ');
//		f.ignore(256, ' ');
//		s.push_back(s1);
//		i++;
//	}
//	for (int i = 0; i < s.size(); i++)
//	{
//		cout << s[i] << endl;
//	}
//	cout << i << endl;
//	f.close();
//}
QInt::~QInt()
{
}
