#include "thuvien2.h"

void uncompress(string s, string s1, string s2)
{

	///----------------tao cay huffman ----------------------
	NODE* a;
	fstream f1(s1, ios::in);
	char c;
	int b;
	vector <NODE*> C;
	while (!f1.eof())
	{
		f1.get(c);
		f1.ignore(256, ' ');
		f1 >> b;
		f1.ignore();
		if (f1.eof())//tranh doc du ki tu cuoi
		{
			break;
		}
		a = creatNode(c, b);
		C.push_back(a);
		
	}
	SORT(C);// sap xep truoc khi tao cay
	cout << "\n-------bang tan so--------\n";
	for (int i = 0; i < C.size(); i++)
	{
		cout << C[i]->c << " co tan so: " << C[i]->f << endl;
	}
	NODE* t;
	Init(t);
	t = huffman(C);
	if (t == NULL)
		cout << "fail" << endl;
	Print(t);
	vector <NODE*> table;
	Table(t, table);
	int sum = 0;//dung de tinh so bit ghi ra tap tin
	int sum1 = 0; // so chu cai
	cout << "\n----bang thong tin----\n";
	for (int i = 0; i < table.size(); i++)
	{
		cout << table[i]->c << " co tan so: " << table[i]->f << ", ma bit la: " << table[i]->code << endl;
		sum += table[i]->f * table[i]->code.length();
		sum1 += table[i]->f;
	}
	f1.close();

	////-----------------doc file --------------
	fstream f(s, ios::in | ios ::binary);
	fstream f2(s2, ios::out);
	int dem = 7;
	string kq;
	int n;
	////
	int p;
	p = 255;
	char v;
	v = p;
	NODE* p1;
	p1 = t;
	char tam;
	while (!f.eof())
	{
		f.read((char*)&tam, 1);/// ghi theo binary
		for (int j = 0; j < 8; j++)
		{
			n = getBit(tam, dem);
			dem--;
			if (n == 1)
			{
				p1 = p1->pRight;					
				if (p1->c != v && p1->pLeft == NULL && p1->pRight == NULL)
				{
					cout << p1->c;
					f2 << p1->c;
					p1 = t;
				}
				sum--;
			}
			else
			{
				p1 = p1->pLeft;
				if (p1->c != v && p1->pLeft == NULL && p1->pRight == NULL)
				{
					cout << p1->c;
					f2 << p1->c;
					p1 = t;
				}
				sum--;
			}
			if (sum == -1)//lay du so bit ghi ra file
			{
				break;
			}
		}
		if (dem == -1)
		{
			dem = 7;
		}
		if (sum == -1)//lay du so bit ghi ra file
		{
			break;
		}
	}
	f.close();
	f2.close();

	cout << endl;
}

NODE* huffman(vector<NODE*> Q)
{
	int n = Q.size();
	NODE* z = new NODE;
	for (int i = 1; i < n; i++)
	{
		NODE *x, *y;

		x = Q.back();
		Q.pop_back();
		if (x->pLeft == NULL && x->pRight == NULL)
		{
			x->code = "0";
		}
		else
		{
			phatSinhBit(x, "0");
		}

		y = Q.back();
		Q.pop_back();
		if (y->pLeft == NULL && y->pRight == NULL)
		{
			y->code = "1";
		}
		else
		{
			phatSinhBit(y, "1");
		}
		int p;
		p = 255;
		char j;
		j = p;
		Init(z);
		int m = x->f + y->f;
		InsertNode(z, j, m);
		InsertNode(z, x->c, x->f);
		InsertNode(z, y->c, y->f);
		z->pLeft = x;  // phai co tro toi pLeft vs pRight
		z->pRight = y;
		Q.push_back(z);
		SORT(Q);
	}
	return z;
}
void swap(NODE* &x, NODE* &y)
{
	NODE* t = new NODE;
	t->c = x->c;
	t->f = x->f;
	t->pLeft = x->pLeft;
	t->pRight = x->pRight;
	t->code = x->code;

	x->c = y->c;
	x->f = y->f;
	x->pLeft = y->pLeft;
	x->pRight = y->pRight;
	x->code = y->code;

	y->c = t->c;
	y->f = t->f;
	y->pLeft = t->pLeft;
	y->pRight = t->pRight;
	y->code = t->code;

}
void SORT(vector<NODE*> Q)
{
	int n = Q.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (Q[i]->f < Q[j]->f)
			{
				swap(Q[i], Q[j]);
			}
			if (Q[i]->f == Q[j]->f)
			{
				if (Q[i]->c < Q[j]->c)
				{
					swap(Q[i], Q[j]);
				}
			}
		}
	}
}
void Init(NODE* &t)
{
	t = NULL;
}
NODE* creatNode(char y, int x)
{
	NODE* q = new NODE;
	q->c = y;
	q->f = x;
	q->pLeft = q->pRight = NULL;
	q->code = "";
	return q;
}
void InsertNode(NODE* &t, char y, int x)
{
	if (t == NULL)//neu NODE rong
	{
		NODE* q = new NODE;
		q->c = y;
		q->f = x;
		q->pLeft = q->pRight = NULL;
		q->code = "";
		t = q;

	}
	else
	{
		if (t->pLeft == NULL)
			return InsertNode(t->pLeft, y, x);
		else
			return InsertNode(t->pRight, y, x);

	}
}

void Print(NODE* &t)//dao ma bit lai
{
	if (t == NULL)
		return;
	else
	{

		Print(t->pLeft);
		//cout << t->c << " ";
		t->code = strrev((char*)t->code.c_str());// dao lai cho dung thu tu code
		//cout << "code: " << t->code << " --- ";
		//cout << "tan so la: " << t->f << endl;
		Print(t->pRight);

	}
}



void phatSinhBit(NODE* &t, string c)
{
	if (t == NULL)
		return;
	else
	{

		phatSinhBit(t->pLeft, c);
		t->code += c;
		phatSinhBit(t->pRight, c);

	}
}



int getBit(char x, int vt)
{
	return (x >> vt) & 1;
}

void Table(NODE* t, vector <NODE*> &a)//tao vector la bang chua thong tin va ma bit
{
	
	if (t == NULL)
		return;
	else
	{
		int p;
		p = 255;
		char j;
		j = p;
		Table(t->pLeft, a);
		if (t->c != j && t->pLeft == NULL && t->pRight == NULL)
		{
			a.push_back(t);
		}
		Table(t->pRight, a);
	}
}

string timMaBit(vector <NODE*> t, char c)
{
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i]->c == c)
		{
			return t[i]->code;
		}
	}

}

//string giaiNen(NODE* t, string bit, int &vt)
//{
//	string dap_an;
//	int p;
//	p = 255;
//	char j;
//	j = p;
//	while (t != NULL)
//	{
//		char c = bit[vt];
//		if (bit[vt] == '0')
//		{
//			t = t->pLeft;
//			vt++;
//		}
//		else
//		{
//			t = t->pRight;
//			vt++;
//		}
//		if (t->c != j && t->pLeft == NULL && t->pRight == NULL)
//		{
//			
//			dap_an.append(1, t->c);
//			return dap_an;
//		}
//	}
//	return NULL;
//}