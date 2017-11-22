#include <iostream>
#include <bitset> 
#include <string>

using namespace std;
enum Options {
	OpAutoRedraw = 0x01,
	OpAntiAlias = 0x02,
	OpPixelShader = 0x04,
	OpVertexShader = 0x08,
	OpFullscreen = 0x10,
	OpDaylight = 0x20
	// ...
};

void DTB(int n, int SoBit)
{
	int temp = 0;
	int _bit = 0;
	switch (SoBit)
	{
	case 8: _bit = 0x80; break;
	case 16: _bit = 0x8000; break;
	}
	for (int i = 0; i<SoBit; i++)
	{
		temp = n;
		temp = temp&(_bit >> i);
		if (temp != 0)
			temp = 1;
		cout << temp;

	}
}

//void Div2(char* &a) {
//	char* b = new char[strlen(a) + 1];
//	strcpy(b, a);
//	a = { "0" };
//	for (int i = 0; i < strlen(b); i++) {
//		char* t = new char[strlen(b) - i + 1];
//		t[0] = b[i];
//		for (int j = 1; j < strlen(b) - i; j++) {
//			t[j] = '0';
//		}
//		t[strlen(b) - i] = '\0';
//		if ((t[0] - 48) >= 2) {
//			if (i != strlen(b) - 1){
//				t[1] = (((t[0] - 48) % 2) * 10) / 2 + 48;
//				t[0] = (t[0] - 48) / 2 + 48;
//				t[strlen(b) - i] = '\0';
//			}
//			else {
//				t[0] = (t[0] - 48) / 2 + 48;
//				t[strlen(b) - i] = '\0';
//			}
//		}
//		else {
//			if (i != strlen(b) - 1) {
//				if (t[0] - 48 < 2) {
//					t[0] = ((t[0] - 48) * 10 + (t[1] - 48) * 10) / 2 + 48;
//					t[strlen(b) - i - 1] = '\0';
//				}
//				else {
//					t[0] = ((t[0] - 48) * 10) / 2 + 48;
//					Add0(t, 1);
//					t[strlen(b) - i] = '\0';
//				}
//			}
//			else {
//				t[0] = (t[0] - 48) / 2 + 48;
//				t[strlen(b) - i] = '\0';
//			}
//		}
//		a = addDeximal(a, t);
//	}
//	if (a[0] == '0') {
//		a[0] = a[1];
//		a[1] = '\0';
//	}
//	//char* bit = deximalToBinary(a);
//	//bit = divisionBinary(bit, "2");
//	//a = binaryToDeximal(bit);
//} // chia nguyen cho 2

//string div2(string s)
//{
//	string s1;
//	for (int i = 0; i < s.length(); i++)
//	{
//		int x = (s[i] - '0');
//		if (x / 2 == 0 && x % 2 != 0)
//		{
//			x = (x % 2) * 10 + (s[i] - '0');
//			i++;
//		}
//
//		if (x / 2 != 0 || (x / 2 == 0 && x % 2 == 0))
//		{
//			s1 += (x / 2) + '0';
//
//		}
//	}
//	
//	return s1;
//}


//void nhan2(string s)
//{
//
//	int i = s.length()-1;
//	int du = 0;
//	string s1;
//	while (i >= 0)
//	{
//		int x = (s[i] - '0');	
//		if ((x * 2) < 10)
//		{
//			int t = (x * 2) + '0' + du;
//			s1 += t;
//			du = 0;
//			i--;
//		}
//		else
//		{
//			int t = (x * 2) + '0' + du -10;
//			s1 += t;
//			du = 1;
//			i--;
//		}
//		
//	}
//
//	for (int i = 0; i < s1.length()/2; i++)
//	{
//		swap(s1[i], s1[s1.length() - 1-i]);
//	}
//	if (du == 1)
//	{
//		s1.insert(0, "1");
//	}
//	while (s1[0] == '0')
//	{
//		s1.erase(0, 1);
//	}
//	if (s1 == "")
//	{
//		s1.insert(0, "0");
//	}
//
//	cout << s1 << endl;
//
//
//}
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
	s1 = strrev((char*)s1.c_str());
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
void chia2(string s,int nhiphan[128], int &j)
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
			s.erase(0,1);
		}
		du = 0;
		i = 0;
	}
}
int main()
{
	string s1;


	while (1)
	{ 
		cout << endl;
		fflush(stdin);
		getline(cin, s1);
		s1 = nhan2(s1);
		cout << s1 << endl;
		//int x;
		//string::size_type sz;   // alias of size_t

		//x = std::stoi(s1, &sz);
		//cout << x - 0; 
		
	}
	//string a = "1234500";
	//a = strrev((char*)a.c_str());
	//cout << a << endl;
	


	//int nhiphan[128];
	//int n;
	////while (1)
	////{ 
	//	cout << endl;
	//	fflush(stdin);
	//	getline(cin, s1);
	//	chia2(s1, nhiphan, n);
	//	for (int i = n-1; i >= 0 ; i--)
	//	{
	//		cout << nhiphan[i] << endl;
	//	}
	//}
	//cout << "\nmang nhi phan" << endl;
	//for (int i = 0; i < n; i++)
	//{
	//	cout << nhiphan[i] << " ";
	//}
	

	//int x = -10;
	//int a;
	////int a = (x >> 1) & 1;
	////x = ~(1 << 3) & x;
	////x = ~(1 << 1) & x;
	//for (int i = 0; i < 32; i++)
	//{
	//	int a = (x >> i) & 1;
	//	cout << a;
	//}
	//cout << x << endl;
	//int x;
	//cin >> x;

	//int i = x / 32;
	//int vt = x % 32;

	//cout << "i: " << i << " vt :  " << vt << endl;
	//DTB(65535, 16); //  Nếu để 16 thì sẽ hiện 16bit , 8 là 8bit thông thường 

	//_int64 z = 0x8000000000000000;
	//cout << endl;
	//cout << z << endl;
	//	//== 1 == "00000001"
	//	// 0x02 ==   2 == "00000010"
	//	// 0x04 ==   4 == "00000100"
	//	// 0x08 ==   8 == "00001000"
	//	// 0x10 ==  16 == "00010000"
	//	// 0x20 ==  32 == "00100000"
	//	// 0x40 ==  64 == "01000000"
	//	// 0x80 == 128 == "1000 0000"
	//unsigned char options;
	//options = OpAutoRedraw | OpVertexShader | OpFullscreen;


	//bitset<128> mybits;     // mybits: 0000
	//mybits.set();              // mybits: 1111

	//string mystring = mybits.to_string<char, std::string::traits_type, std::string::allocator_type>();

	//cout << "mystring: " << mystring << '\n';
	//bitset<4> foo(string("1011"));

	//std::cout << foo.reset(0) << '\n';    // 1001 => cách tắt bit
	//std::cout << foo.reset() << '\n';     // 0000

	//bitset<8> foo(std::string("10110011"));

	//std::cout << foo << " has ";
	//std::cout << foo.count() << " ones and ";// 5
	//std::cout << (foo.size() - foo.count()) << " zeros.\n";// 3

	//std::bitset<8> foo;

	//std::cout << "Please, enter an 8-bit binary number: ";
	//std::cin >> foo;


	//foo[1] = 1;             // 0010
	//foo[2] = foo[1];        // 0110


	//std::cout << "foo: " << foo << '\n';
	////dat bit ở vt bat ki =>  std::cout << "foo.size() is " << foo.size() << '\n'; //8
	//std::cout << foo.set() << '\n';       // 1111
	//std::cout << foo.set(2, 0) << '\n';    // 1011
	//std::cout << foo.set(2) << '\n';      // 1111

	//bitset<4> foo;

	//std::cout << "Please, enter a binary number: ";
	//std::cin >> foo;

	//bitset<4> foo1;
	//std::cout << "Please, enter a binary number: ";
	//std::cin >> foo1;

	//bitset<4> foo2;
	//foo2 = foo1 & foo;

	////if (foo.none())
	////	std::cout << foo << " has no bits set.\n";
	////else
	////	std::cout << foo << " has " << foo.count() << " bits set.\n";
	//cout << foo2 << endl;
	//cout << sizeof(foo[2]) << endl;

	//std::bitset<4> foo(std::string("1001"));
	//std::bitset<4> bar(std::string("0011"));

	//std::cout << (foo ^= bar) << '\n';       // 1010 (XOR,assign)
	//std::cout << (foo &= bar) << '\n';       // 0010 (AND,assign)
	//std::cout << (foo |= bar) << '\n';       // 0011 (OR,assign)

	//std::cout << (foo <<= 2) << '\n';        // 1100 (SHL,assign)
	//std::cout << (foo >>= 1) << '\n';        // 0110 (SHR,assign)

	//std::cout << (~bar) << '\n';           // 1100 (NOT)
	//std::cout << (bar << 1) << '\n';         // 0110 (SHL)
	//std::cout << (bar >> 1) << '\n';         // 0001 (SHR)

	//std::cout << (foo == bar) << '\n';       // false (0110==0011)
	//std::cout << (foo != bar) << '\n';       // true  (0110!=0011)

	//std::cout << (foo&bar) << '\n';        // 0010
	//std::cout << (foo | bar) << '\n';        // 0111
	//std::cout << (foo^bar) << '\n';        // 0101


	//std::bitset<4> foo(std::string("0101"));
	//std::bitset<4> foo1(std::string("0001"));
	//std::bitset<4> foo2;
	//for (int i = 0; i < foo.size(); i++)
	//{
	//	foo2 = foo[i] + foo1[i];
	//}
	//if (foo[2] == 1)
	//{
	//	cout << "\naaaaa\n";
	//	int a = foo[2];
	//	cout << a << endl;
	//}
//string s = "0101";
//
//	bitset<4> foo(s);
//	cout << foo[0];

	////lat bit tai vt pos
	//std::cout << foo.flip(2) << '\n';     // 0101
	//std::cout << foo.flip() << '\n';      // 1010


	//std::bitset<16> foo;
	//std::bitset<16> bar(0xfa2);
	//std::bitset<16> baz(std::string("0101111001"));

	//std::cout << "foo: " << foo << '\n';
	//std::cout << "bar: " << bar << '\n';
	//std::cout << "baz: " << baz << '\n';

	//0. toán tửsizeof
	//cout << sizeof(int) << endl;
	////1. miền giá trị của kiểu dữ liệu
	//// số nguyên 1 byte: -128 -> +127
	//// min = 1000 0000 = -128
	//// max = 0111 1111 = +127
	////  +1 = 1000 0000 = -128
	//char x = 128;
	//cout << (int)x << endl;
	////2. phép dịch bit (luậ n lý hay sốhọ c)?
	//char x3 = -24; //dịch số học
	//x3 = x3 >> 1;
	//cout << (int)x3 << endl;
	//unsigned charx3 = 24; // dịch luận lý
	//x3 = x3 >> 1;
	//cout << (int)x3 << endl;
	////3. biểu diễn Binary, Hexa của kiểu dữ liệu
	//// ta biết min = 1000 0000 0000....
	//__int64 x1 = 0x8000000000000000;
	//cout << x1 << endl;
	//// ta biết max = 0111 1111 1111...
	//__int64 x2 = 0x7FFFFFFFFFFFFFFF;
	//cout << x2 << endl;
	//4. đổi từ hệ 10 --> hệ 2
	//char x4 = 10;
	//int a[8] = { 0 };
	//unsigned char mask = 0x80;
	////bitset<16> mask(std::string(""));
	//for (int i = 0; i < 8; i++)
	//{
	//	if ((x4 & mask) != 0)
	//		a[i] = 1;
	//	mask = mask >> 1;
	//}
	//cout << endl;
	//for (int i = 0; i < 8; i++)
	//	cout << a[i];
	////5. đổi ngược từ hệ 2 --> hệ 10
	//string Bits = "10101100";
	//char k = 0; //nếu khai báo unsigned char thì điều gì xảy ra?
	//for (int i = 0; i < 8; i++)
	//	k = (k << 1) | (Bits[i] - 48);
	//cout << endl << (int)k << endl;


	
	return 0;
}
