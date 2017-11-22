#include "thuvien1.h"



void InitStack(stack &s)
{
	s.Top = NULL;
}

bool IsEmpty(stack &s)
{
	return (s.Top == NULL);
}

NODE* GetNode(char x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		return NULL;
	}
	else
	{
		p->data = x;
		p->pNext = NULL;
	}
	return p;
}

void Push_back(stack &s, char x)
{
	NODE* p = GetNode(x);
	if (p != NULL)
	{
		p->pNext = s.Top;
		s.Top = p;
	}
}

char Pop_back(stack &s)
{
	if (!IsEmpty(s))
	{
		NODE* p = s.Top;
		char x = s.Top->data;
		s.Top = s.Top->pNext;
		delete p;
		return x;
	}

}

char TopStack(stack &s)
{
	return s.Top->data;
}

void DeleteStack(stack &s)
{
	while (!IsEmpty(s))
	{
		char x = Pop_back(s);
	}
}


void docFile(string s, string s2)
{
	fstream f(s, ios::in);
	fstream f1(s2, ios::out);
	int n;
	string s1;
	vector <string> a;
	string bieuthuc;
	while (!f.eof())
	{
		f >> n;
		f.ignore();
		getline(f, s1);
		a.push_back(s1);
	}
	s1.clear();
	int x;
	stack kq;
	InitStack(kq); //khoi tao de tranh loi
	int kt = 0;
	for (int j = 0; j < a.size(); j++)
	{
		while (1)
		{
			x = a[j].find(' ', 0);
			if (x == -1)
			{
				break;
			}
			a[j].erase(x, 1);
		}
	}
	//sau khi xoa tat ca cac dau cach
	for (int i = 0; i < a.size(); i++)// duyet tung dong kt dau co hop le hay khong
	{
		int *b = new int[100];
		int nb = 0;
		for (int j = 0; j < a[i].size(); j++)
		{
			char c = a[i][j];
			
			if (j != a[i].size() - 1)
			{
				char d = a[i][j + 1];
				if ((c == '+' || c == '-' || c == '*' || c == '/') && !(d >= '0' && d <= '9') && d != '(' && d != '[') // sau dau ma k co so
				{
					b[nb++] = j + 1;
					kt = 1;
				}
				if ((d == '+' || d == '-' || d == '*' || d == '/') && (c == '(' || c == '[')) // truoc dau ma k co so
				{
					b[nb++] = j + 1;
					kt = 1;
				}
				if ((c == ')' || c == ']') && (d >= '0' && d <= '9')) // sau  dau ] ) k co phep tinh
				{
					b[nb++] = j + 1;
					kt = 1;
				}
				if ((d == '(' || d == '[') && (c >= '0' && c <= '9')) // trk  dau ( [ k co phep tinh
				{
					b[nb++] = j + 1;
					kt = 1;
				}
				if ((c >= '0' && c <= '9') && (d >= '0' && d <= '9')) //2 so lien tiep
				{
					kt = 1;
					b[nb++] = j + 1;
				}
				if ((c == ')' || c == ']') && (d == '(' || d == '['))//2 dau lien tiep
				{
					b[nb++] = j + 1;
					kt = 1;
				}
			}
			// TH dong ngoac sai
			if (c == '(' || c == '[')
			{
				Push_back(kq, c);
			}
			if (c == ')')
			{
				char z;
				z = Pop_back(kq);
				if (z != '(')
				{
					b[nb++] = j;
					kt = 1;
				}
			}
			if (c == ']')
			{
				char z;
				z = Pop_back(kq);
				if (z != '[')
				{
					b[nb++] = j;
					kt = 1;
				}
			}
			
		}

		if (kt == 0)
		{
			f1 << "bieu thuc hop le\n";
		}
		else
		{
			f1 << "bieu thuc khong hop le tai vi tri: ";
			for (int k = 0; k < nb -1; k++)
			{
				f1 << b[k] << ", ";
			}
			f1 << b[nb - 1];
			f1 << endl;
			kt = 0;
		}
		
		delete[] b;
		DeleteStack(kq);
	}
	f1.close();
	f.close();
}
