#include <iostream>
using namespace std;
#include <string>
#include <string.h>
#include <fstream>

struct node
{
	float data;
	struct node* pnext;
};

typedef struct node NODE;


struct list
{
	NODE* phead;
	NODE* ptail;
};

typedef struct list LIST;


NODE* Getnode(float x)
{
	NODE* p = new NODE;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void addLast(LIST &l, NODE* p)
{
	if (l.phead == NULL)
	{
		l.phead = l.ptail = p;
	}
	else
	{
		l.ptail->pnext = p;
		l.ptail = p;
	}
}

NODE* AddTail(LIST& l, float x)
{
	NODE* p = Getnode(x);
	if (p == NULL)
		return NULL;

	else
	{
		addLast(l, p);
		return p;
	}
	return NULL;
}

void print(LIST l)
{
	for (NODE* p = l.phead; p != NULL; p = p->pnext)
	{
		cout << p->data << " ";
	}
}
void InitList(list& l)
{
	// Khởi tạo cho DSLK rỗng nghĩa là pHead và pTail đều bằng NULL
	l.phead = NULL;
	l.ptail = NULL;
}

void docfile(string s)
{
	LIST l;
	InitList(l);
	fstream f(s, ios::in);
	float a;
	while (!f.eof())
	{
		f >> a;
		AddTail(l, a);
	}
	print(l);
	float b[100];
	int nb;
	nb = 0;
	for (NODE* p = l.phead; p != NULL; p = p->pnext)
	{
		float x = p->data;
		int c = floor(x);
		b[nb++] = p->data - c;
	}
	for (int i = 0; i < nb; i++)
		cout << b[i] << " ";
	f.close();
}
void sort(LIST &l)
{

}

int main()
{
	//string str = "We think, but we live in details.";
	// (quoting Alfred N. Whitehead)

	//string str2 = str.substr(3, 5);     // "think"
	//cout << str << endl;
	//int pos = str.find("live");      // position of "live" in str if it don,t exist return -1
	//cout << "vt: " << pos << endl;

	//string str3 = str.substr(pos);     // get from "live" to the end
	//cout << str << endl;
	//cout << str2 << "\n" << str3 << '\n';

	//string::size_type z;
	//str.clear();
	//fflush(stdin);
	//getline(cin, str);
	//int i = stoi(str, &z);
	//i++;
	//cout << "after convert string to number: " << i << endl;
	//
	//char* s;
	//s = strtok((char*)str.c_str(), " ,.");
	//while (s != NULL)
	//{
	//	cout << s << endl;
	//	s = strtok(NULL, " ,.");
	//	
	//}

	docfile("input.txt");
	return 0;
}