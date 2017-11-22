#include<iostream>
#include<string>
using namespace std;
#include <vector>
#include <sstream>

class HU{
private:
	int data[128];
	int size;
public:
	HU();
	HU(const HU &a);
	HU(int n, int a[]);
	void nhap();

	void cong(HU, HU);
	void nhan(HU, HU);
	void tru(HU, HU);
	void chia(HU, HU);

	void truthapphan(HU, HU);
	void congthapphan(HU, HU);
	void nhanthapphan(HU, HU);
	void chiathapphan(HU, HU);

	string congthaplucphan(string, string);
	string nhanthaplucphan(string, string);
	string truthaplucphan(string, string);
	void chiathaplucphan(string, string);

	HU(string a); 
	void DaoBit();
	
	bool kiemtrasolonhon(HU, HU);
	HU& operator = (const HU &a);
	HU& operator >> (const int &a);
	HU& operator << (const int &a);
	void ror();
	void rol();
	HU& operator & (const HU &a);
	HU& operator | (const HU &a);
	HU& operator ^ (const HU &a);
	HU& operator ~ ();

	HU& ConvertBinary2(const HU &a);
	string ConvertBinary16(const HU &a);
	HU& ConvertDecimal(const HU &a);
	void ConvertHexa(string a);
	int Getsize();
	void xuat();
};

HU::HU(){
	size = 0;
	for (int i = 0; i< 128; i++) data[i] = 0;
}
int HU::Getsize()
{
	// xac dinh lai size*****
	for (int i = 1; i < 128; i++)
	{
		if (data[i] != 0)
		{
			size = 128 - i;
			break;

		}
		else
		{
			size = 1;//neu tat ca = 0 thi xuat ra 0
		}
	}
	return size;
}
HU::HU(const HU &a)
{
	size = a.size;
	for (int i = 0; i< 128; i++) data[i] = a.data[i];
}

HU::HU(int n, int a[])
{
	size = n;
	for (int i = 0; i< 128; i++) data[i] = a[i];
}
HU::HU(string a)
{
	size = a.length();
	int j = 0;
	for (int i = 0; i< 128; i++) data[i] = 0;
	for (int i = 128 - a.length(); i< 128; i++) data[i] = a[j++] - '0';
}
void HU::nhap(){
	string  str;
	cout << "\nNhap: ";
	fflush(stdin);
	cin >> str;
	size = str.size();
	for (int i = 0; i < size; i++){
		data[128 + i - size] = str.at(i) - '0';
	}
}

void HU::cong(HU a, HU b){
	int nho = 0;
	size = (a.size > b.size) ? a.size : b.size;
	for (int i = 128 - 1; i >= 1; i--)//bit dau the hien dau
	{
		int tg = a.data[i] + b.data[i] + nho;
	
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
	// xac dinh lai size
	for (int i = 0; i < 128; i++)
	{
		if (data[i] != 0)
		{
			size = 128 - i;
			break;

		}
		else
		{
			size = 1;//neu tat ca = 0 thi xuat ra 0
		}
	}
}

void HU::congthapphan(HU a, HU b){
	int nho = 0;
	size = (a.size > b.size) ? a.size : b.size;
	for (int i = 128 - 1; i >= 0; i--){
		int tg = a.data[i] + b.data[i] + nho;
		nho = tg / 10;
		data[i] = tg % 10;
	}
	// xac dinh lai size
	for (int i = 0; i < 128; i++)
	{
		if (data[i] != 0)
		{
			size = 128 - i;
			break;

		}
		else
		{
			size = 1;//neu tat ca = 0 thi xuat ra 0
		}
	}
}

bool HU::kiemtrasolonhon(HU a, HU b)
{
	if (a.Getsize() < b.Getsize())
	{
		return 0;
	}
	if (a.Getsize() == b.Getsize())
	{
		for (int i = 128 - a.Getsize(); i < 128; i++)
		{
			if (a.data[i] > b.data[i])
			{
				return 1;
			}
			if (a.data[i] < b.data[i])
				return 0;
		}

	}
	return 1;
}
void HU::truthapphan(HU a, HU b)
{
	int nho = 0;
	size = (a.size > b.size) ? a.size : b.size;

	if (kiemtrasolonhon(a, b) == 1)
	{
		for (int i = 128 - 1; i >= 1; i--)
		{
			int tg = a.data[i] - b.data[i] - nho;
			if (tg < 0)
			{
				data[i] = a.data[i] + 10 - b.data[i] - nho;
				nho = 1;
			}
			else
			{
				nho = 0;
				data[i] = tg;
			}
		}

	}
	else
	{

		if (kiemtrasolonhon(b, a) == 1)
		{
			for (int i = 128 - 1; i >= 1; i--)
			{
				int tg = b.data[i] - a.data[i] - nho;
				if (tg < 0)
				{
					data[i] = b.data[i] + 10 - a.data[i] - nho;
					nho = 1;
				}
				else
				{
					nho = 0;
					data[i] = tg;
				}
			}
		}

	}
	// xac dinh lai size
	for (int i = 0; i < 128; i++)
	{
		if (data[i] != 0)
		{
			size = 128 - i;
			break;

		}
		else
		{
			size = 1;//neu tat ca = 0 thi xuat ra 0
		}
	}
}
void HU::DaoBit()
{
	for (int i = 128 - size; i < 128; i++)
	{
		if (data[i] == 1)
		{
			data[i] = 0;
		}
		else
		{
			data[i] = 1;
		}
	}
}


void HU::tru(HU a, HU b)
{
	HU  d, ketqua;
	b.DaoBit();
	HU f("1");
	d.cong(f, b);

	//cout << "\nbit cua d: " << endl;
	//for (int i = 128 - d.size - 1; i < 128; i++)
	//	cout << d.data[i] << endl;
	ketqua.cong(a, d);
	//ketqua.xuat();
	//size = ketqua.size;
	size = ketqua.Getsize();
	for (int i = 0; i< 128; i++) data[i] = ketqua.data[i];

	
}

void HU::nhan(HU a, HU b)
{
	size = a.size + b.size;
	HU e(size, data);
	int x = 0;
	for (int i = 128 - 1; i >= 128 - a.size; i--)
	{
		HU c(e);
		for (int j = 128 - 1; j >= 128 - b.size; j--)
		{
			//int x = a.data[i];
			//int y = b.data[j];
			//int tam = data[i + j - 127];
			data[i + j - 127] = a.data[i] * b.data[j];
		
		}
		HU d(size, data);
		for (int l = 0; l < x; l++)
		{
			d.data[128 - l - 1] = 0;
		}
		x++;
		e.cong(c, d);

	}
	//size = e.size;
	size = e.Getsize();
	for (int i = 0; i< 128; i++) data[i] = e.data[i];

}
void HU::nhanthapphan(HU a, HU b)
{
		size = a.size + b.size;
		
		for (int i = 128 - 1; i >= 128-a.size; i--)
		{
			for (int j = 128 - 1; j >= 128-b.size; j--)
			{
				int x = a.data[i];
				int y = b.data[j];
				data[i+j -127] += a.data[i] * b.data[j];// cong don
				
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

}
HU& HU::operator >> (const int &a)
{
	string s;
	stringstream ss;

	for (int i = 128 - size; i < 128 - a; i++) // chi can chay toi phu tu thu 128-a vì khi dich bit no se mat
	{
		ss.clear();
		ss.str("");
		ss << data[i];
		s += ss.str();
	}
	for (int i = 0; i < a; i++)
	{
		s.insert(0, 1, '0');
	}
	HU b(s);
	for (int i = 0; i < 128; i++)
	{
		data[i] = b.data[i];
	}
	// xac dinh lai size
	for (int i = 0; i < 128; i++)
	{
		if (data[i] != 0)
		{
			size = 128 - i;
			break;

		}
		else
		{
			size = 1;//neu tat ca = 0 thi xuat ra 0
		}
	}
	return *this;
}
HU& HU::operator << (const int &a)
{
	string s;
	stringstream ss;

	for (int i = 128 - size + a; i < 128; i++) // chi can chay toi phu tu thu 128-size+a vì khi dich bit no se mat
	{
		ss.clear();
		ss.str("");
		ss << data[i];
		s += ss.str();
	}
	for (int i = 0; i < a; i++)
	{
		s += "0";
	}
	HU b(s);
	for (int i = 0; i < 128; i++)
	{
		data[i] = b.data[i];
	}
	// xac dinh lai size
	for (int i = 0; i < 128; i++)
	{
		if (data[i] != 0)
		{
			size = 128 - i;
			break;

		}
		else
		{
			size = 1;//neu tat ca = 0 thi xuat ra 0
		}
	}
	return *this;
}
void HU::ror()
{
	string s;
	stringstream ss;

	for (int i = 128 - size; i < 128; i++) // chi can chay toi phu tu thu 128-a vì khi dich bit no se mat
	{
		ss.clear();
		ss.str("");
		ss << data[i];
		if (i == 127)// de doc bit cuoi do ss
		{
			break;
		}
		s += ss.str();
	}
	s.insert(0, ss.str()); // lay bit cuoi dua len dau
	HU b(s);
	for (int i = 0; i < 128; i++)
	{
		data[i] = b.data[i];
	}
	// xac dinh lai size
	for (int i = 0; i < 128; i++)
	{
		if (data[i] != 0)
		{
			size = 128 - i;
			break;

		}
		else
		{
			size = 1;//neu tat ca = 0 thi xuat ra 0
		}
	}
}
void HU::rol()
{
	string s, s1;
	stringstream ss;

	for (int i = 128 - size; i < 128; i++) // chi can chay toi phu tu thu 128-size vì khi dich bit no se mat
	{
		ss.clear();
		ss.str("");
		ss << data[i];
		if (i == 128-size)// de doc bit dau do ss
		{
			s1 = ss.str();
		}
		else
		{
			s += ss.str();
		}
	}
	s += s1;

	HU b(s);
	for (int i = 0; i < 128; i++)
	{
		data[i] = b.data[i];
	}
	// xac dinh lai size***** 
	// xac dinh lai size
	for (int i = 0; i < 128; i++)
	{
		if (data[i] != 0)
		{
			size = 128 - i;
			break;

		}
		else
		{
			size = 1;//neu tat ca = 0 thi xuat ra 0
		}
	}
}
void HU::xuat(){
	//int x;
	//for (int i = 0; i < 128; i++)
	//{
	//	if (data[i] != 0)
	//	{
	//		x = i;
	//		break;

	//	}
	//}
	for (int i = 128 - size; i < 128; i++)
	{
		cout << data[i];
	}
}
HU& HU::operator = (const HU &a)
{
	size = a.size;
	for (int i = 0; i < 128; i++)
	{
		data[i] = a.data[i];
	}
	return *this;
}
HU& HU::ConvertBinary2(const HU &a)
{
	//cout << "\n a: \n";
	//for (int i1 = 128 - a.size - 1; i1 < 128; i1++)
	//	cout << a.data[i1] << endl;
	vector <HU> arr;
	HU b("1");
	HU c("2");
	HU tam;
	arr.push_back(b);
	for (int i = 1; i < 128; i++)
	{
		for (int i = 0; i < 128; i++)
		{
			tam.data[i] = 0;//gan lai de tranh cong don khi nhan voi so cu
		}
		tam.nhanthapphan(b, c);
		b = tam;
		arr.push_back(tam);
	}
	//for (int i = 0; i < 128; i++) // xuat ra mang nhi phan vs gia tri toi 2^127, bit dau la dau
	//{
	//	cout << "a["<< i << "]: ";
	//	arr[i].xuat();
	//	cout << endl;
	//}
	HU d;
	int j = 0;
	for (int i = 128 - 1; i >= 128 - size; i--)
	{
		if (a.data[i] == 1)
		{
			for (int i1 = 0; i1 < 128; i1++)
			{
				tam.data[i1] = 0;//gan lai de tranh cong don khi nhan voi so cu
			}
			tam.congthapphan(d, arr[j]);
			d = tam;
		}
		j++;
	}
	return tam;
}
void HU::ConvertHexa(string a)
{
	//vector <HU> arr;
	//HU b;
	//HU c("1");
	//HU tam;
	//arr.push_back(b);
	//for (int i = 1; i <= 15; i++)
	//{
	//	tam.cong(b, c);
	//	b = tam;
	//	arr.push_back(tam);
	//}
	string s1;
	for (int i = 0; i < a.length(); i++)
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
	HU tam(s1);
	size = tam.size;
	for (int i1 = 128 - tam.size - 1; i1 < 128; i1++)
	{
		data[i1] = tam.data[i1];
	}
	
}
string HU::ConvertBinary16(const HU &a)
{
	string s, s1;
	stringstream ss;
	int dem = 0;
	int b = (size) % 4;
	int z = 128 - a.size - (4-b);// lui ve truoc cho co the lay du 4 byte
	for (int i = 128 - 1; i >= z; i--)
	{
		int x = a.data[i];
		ss << a.data[i];
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
	return s1;
}
HU& HU::ConvertDecimal(const HU &a)
{
	vector <HU> arr;
	HU b("1");
	HU c("2");
	HU tam;
	arr.push_back(b);
	for (int i = 1; i < 128; i++)
	{
		for (int i = 0; i < 128; i++)
		{
			tam.data[i] = 0;//gan lai de tranh cong don khi nhan voi so cu
		}
		tam.nhanthapphan(b, c);
		b = tam;
		arr.push_back(tam);
	}
	HU d(a);
	HU e, f;
	f.size = 1;
	for (int i = 128 - 1; i >= 0; i--)
	{
		if (kiemtrasolonhon(d, arr[i]) == 1)
		{
			//int x = 128 - i;
			f.data[128-i-1] = 1;
			f.size++;
			e.truthapphan(d, arr[i]);
			d = e;
			//cout << "\ne:\n";
			//cout << "\ni: " << i << " x: " << x << endl;
			//for (int i = 128 - e.size; i < 128; i++)
			//{
			//	cout << e.data[i] << endl;
			//}
		}
		else
		{
			f.data[128-i-1] = 0;
			f.size++;
		}
	}
	f.Getsize(); // cap nhat size
	return f;
}
void HU::chiathapphan(HU a, HU b)
{
	HU tam("0");
	HU dem("1");
	HU c, d;
	while (kiemtrasolonhon(a, b) == 1)
	{
		c.truthapphan(a, b);
		for (int i1 = 0; i1 < 128; i1++)
		{
			a.data[i1] = 0;//gan lai de tranh cong don khi nhan voi so cu
		}

		a = c;

		for (int i1 = 0; i1 < 128; i1++)
		{
			c.data[i1] = 0;//gan lai de tranh cong don khi nhan voi so cu
		}

		for (int i2 = 0; i2 < 128; i2++)
		{
			tam.data[i2] = 0;//gan lai de tranh cong don khi nhan voi so cu
		}

		tam.congthapphan(d, dem);
		d = tam;
	}


	cout << "\nthuong: \n";
	tam.xuat();
	cout << "\nso du: \n";
	a.xuat(); // a la so con du
}
void HU::chia(HU c1, HU d1)
{
	HU a, b;
	a = c1.ConvertBinary2(c1);
	b = d1.ConvertBinary2(d1);


	HU tam("0");
	HU dem("1");
	HU c, d;
	while (kiemtrasolonhon(a, b) == 1)
	{
		c.truthapphan(a, b);
		for (int i1 = 0; i1 < 128; i1++)
		{
			a.data[i1] = 0;//gan lai de tranh cong don khi nhan voi so cu
		}

		a = c;

		for (int i1 = 0; i1 < 128; i1++)
		{
			c.data[i1] = 0;//gan lai de tranh cong don khi nhan voi so cu
		}

		for (int i2 = 0; i2 < 128; i2++)
		{
			tam.data[i2] = 0;//gan lai de tranh cong don khi nhan voi so cu
		}

		tam.congthapphan(d, dem);
		d = tam;
	}

	HU a1, b1;
	a1 = tam.ConvertDecimal(tam);
	b1 = a.ConvertDecimal(a);

	cout << "\nthuong: \n";
	a1.xuat();
	cout << "\nso du: \n";
	b1.xuat(); // a la so con du
	
}
void HU::chiathaplucphan(string c2, string d2)
{
	//chuyen ve bibnary
	HU c1, d1;
	c1.ConvertHexa(c2);
	d1.ConvertHexa(d2);



	HU a, b;
	a = c1.ConvertBinary2(c1);
	b = d1.ConvertBinary2(d1);

	HU tam("0");
	HU dem("1");
	HU c, d;
	while (kiemtrasolonhon(a, b) == 1)
	{
		c.truthapphan(a, b);
		for (int i1 = 0; i1 < 128; i1++)
		{
			a.data[i1] = 0;//gan lai de tranh cong don khi nhan voi so cu
		}

		a = c;

		for (int i1 = 0; i1 < 128; i1++)
		{
			c.data[i1] = 0;//gan lai de tranh cong don khi nhan voi so cu
		}

		for (int i2 = 0; i2 < 128; i2++)
		{
			tam.data[i2] = 0;//gan lai de tranh cong don khi nhan voi so cu
		}

		tam.congthapphan(d, dem);
		d = tam;
	}

	//HU a2, b2;
	//doi tu 10 => 2
	HU a1, b1;
	a1 = tam.ConvertDecimal(tam);
	b1 = a.ConvertDecimal(a);

	//xuat 10
	//cout << "\nthuong: \n";
	//tam.xuat();
	//cout << "\nso du: \n";
	//a.xuat(); // a la so con du


	//doi tu nhi phan qua he 16
	string x1, x2;
	x1 = a1.ConvertBinary16(a1);
	x2 = b1.ConvertBinary16(b1);
	cout << "\nthuong: \n";
	cout << x1;
	cout << "\nso du: \n";
	cout << x2; // a la so con du


}
string HU::congthaplucphan(string s1, string s2)
{
	HU a, b, c, d;
	a.ConvertHexa(s1);
	b.ConvertHexa(s2);
	c.cong(a, b);
	string s;
	s = ConvertBinary16(c);
	return s;
}
string HU::truthaplucphan(string s1, string s2)
{
	HU a, b, c, d;
	a.ConvertHexa(s1);
	b.ConvertHexa(s2);
	c.tru(a, b);
	string s;
	s = ConvertBinary16(c);
	return s;
}
string HU::nhanthaplucphan(string s1, string s2)
{
	HU a, b, c, d;
	a.ConvertHexa(s1);
	b.ConvertHexa(s2);
	c.nhan(a, b);
	string s;
	s = ConvertBinary16(c);
	return s;
}

HU& HU::operator & (const HU &b)
{
	HU a(size, data);
	
	for (int i = 0; i < 128; i++)
	{
		if (a.data[i] == 1 && b.data[i] == 1)
		{
			data[i] = 1;
		}
		else
		{
			data[i] = 0;
		}
	}
	// xac dinh lai size
	for (int i = 0; i < 128; i++)
	{
		if (data[i] != 0)
		{
			size = 128 - i;
			break;

		}
		else
		{
			size = 1;//neu tat ca = 0 thi xuat ra 0
		}
	}
	return(*this);
}
HU& HU::operator | (const HU &b)
{
	HU a(size, data);

	for (int i = 0; i < 128; i++)
	{
		if (a.data[i] == 0 && b.data[i] == 0)
		{
			data[i] = 0;
		}
		else
		{
			data[i] = 1;
		}
	}
	// xac dinh lai size
	for (int i = 0; i < 128; i++)
	{
		if (data[i] != 0)
		{
			size = 128 - i;
			break;

		}
		else
		{
			size = 1;//neu tat ca = 0 thi xuat ra 0
		}
	}
	return(*this);
}
HU& HU::operator ^ (const HU &b)
{
	HU a(size, data);
	for (int i = 0; i < 128; i++)
	{
		if ((a.data[i] == 1 && b.data[i] == 1) || (a.data[i] == 0 && b.data[i] == 0))
		{
			data[i] = 0;
		}
		else
		{
			data[i] = 1;
		}
	}
	// xac dinh lai size*****
	for (int i = 0; i < 128; i++)
	{
		if (data[i] != 0)
		{
			size = 128 - i;
			break;

		}
		else
		{
			size = 1;
		}
	}

	return(*this);
}
HU& HU::operator ~ ()
{
	HU a(size, data);
	a.DaoBit();

	for (int i = 0; i < 128; i++)
	{
		data[i] = a.data[i];
	}
	size = a.Getsize();
	return(*this);
}

int main(){
	HU a, b, kqc, kqt, kqn;
	a.nhap();
	b.nhap();
	////kqc.cong(a, b);
	//kqc.tru(a, b);
	////kqn.nhanthapphan(a, b);
	////a >> 1;
	kqc.truthapphan(a, b);
	a.xuat(); cout << " - "; b.xuat(); cout << " = "; kqc.xuat();
	//kqn.xuat();
	//a.xuat();
	cout << endl;

	//HU a, a1;
	//cout << "nhap so :";
	//a.nhap();
	//cout << "doi tu nhi phan qua thap phan: " << endl;
	//HU d1 = a.ConvertBinary2(a);
	//d1.xuat();

	//HU d;
	//cout << "\nnhap so :";
	//a1.nhap();
	//cout << "doi tu thap phan qua nhi phan: " << endl;
	//d =a1.ConvertDecimal(a1);
	//d.xuat();

	//HU a, a1;
	//string s;
	//HU d1;
	//cout << "\nnhap chuoi hexan: ";
	//fflush(stdin);
	//getline(cin, s);
	//cout << "\nchuoi nhi phan: ";
	//d1.ConvertHexa(s);
	//d1.xuat();


	//cout << "\ndoi tu thap nhi phan qua thap luc phan: " << endl;
	//cout << "nhap so :";
	//a1.nhap();
	//string s1;
	//s1 = a1.ConvertBinary16(a1);
	//cout << s1 << endl;

	//cout << "\nthap luc phan\n";
	//string s1, s2;
	//cout << "nhap s1: ";
	//fflush(stdin);
	//getline(cin, s1);
	//cout << "\nnhap s2: ";
	//fflush(stdin);
	//getline(cin, s2);
	//HU a;
	//string a1;
	//a1 = a.congthaplucphan(s1, s2);
	//cout << "\nket qua cong: " << a1 << endl;
	//string a2;
	//a2 = a.truthaplucphan(s1, s2);
	//cout << "\nket qua tru: " << a2 << endl;
	//string a3;
	//a3 = a.nhanthaplucphan(s1, s2);
	//cout << "\nket qua nhan: " << a3 << endl;

	//HU c;
	//c.nhap();
	////c << 2;
	////c.ror();			// xoay neu o cuoi la 0 thi k hien
	//c.rol();
	//c.xuat();

	//HU d, e;
	//d.nhap();
	//e.nhap();
	////d|e;
	//~d;
	////d.Getsize();
	//d.xuat();

	//kqc.chiathapphan(a, b);
	//kqc.chia(a, b);
	//a.xuat(); cout << " - "; b.xuat(); cout << " = "; kqc.xuat();

	//cout << "\nchia thap luc phan\n";
	//string s1, s2;
	//cout << "nhap s1: ";
	//fflush(stdin);
	//getline(cin, s1);
	//cout << "\nnhap s2: ";
	//fflush(stdin);
	//getline(cin, s2);
	//HU c;
	//c.chiathaplucphan(s1, s2);


	//so nguyen co dau

}