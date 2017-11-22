#include <iostream>
using namespace std;
#include <string>
#include <fstream>

void mahoa(string& s, int k)
{
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = 'A' + ((s[i] - 'A' + k) % 26);
		}
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = 'a' + ((s[i] - 'a' + k) % 26);
		}
	}
	for (int i = 0; i < n-1; i++)
	{
		if (s[i] == '~' && s[i + 1] == '.')
		{
			s.erase(i, 2);
			s += "(SOH)1";
		}
	}
}

void giaima(string &s, int k)
{
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = 'A' + ((s[i] - 'A' + 26 - k) % 26);
		}
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = 'a' + ((s[i] - 'a' +26 - k) % 26);
		}
	
	}
	string s2 = "(PLE)1";// sau khi cong no thay doi tu (HOS)1 thanh (PLE)1
	int x = s.find(s2);
	s.erase(x, 6);
	s += "~.";
}

void Xuat(string name, string s)
{
	fstream f(name, ios_base::out);
	f << s;
	f.close();
}

void Nhap(string name, string &s)
{
	fstream f(name, ios_base::in);
	getline(f, s);
	f.close();
}
int main()
{
	string s;
	cout << "nhap: " << endl;
	fflush(stdin);
	getline(cin, s);
	mahoa(s, 3);
	Xuat("mahoa.txt", s);
	Nhap("giaima.txt", s);
	giaima(s, 3);
	cout << "sau khi giai ma: " << endl;
	for (int i = 0; i < s.length(); i++)
	{
		cout << s[i] ;

	}

	return 0;
}
