#include "thuvien2.h"



void Init(Queue &Q)
{
	Q.pHead = Q.pTail = NULL;
	Q.count = 0;
}

int Isempty(Queue Q) //kiem tra Queue rong
{
	if (Q.count == 0) //so phan tu = 0 => rong
		return 1;
	return 0;
}

NODE* GetNode(SV x)
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


void Push(Queue &Q, SV x) //them phan tu vao cuoi Queue
{
	NODE *p = GetNode(x); //Neu Q rong
	if (Isempty(Q))
	{
		Q.pHead = Q.pTail = p;
	}
	else //Khong rong
	{
		Q.pTail->pNext = p;
		Q.pTail = p;
	}
	Q.count++; //tang so phan tu len
}

SV Qfront(Queue Q) //xem thong tin phan tu dau hang
{
	if (Isempty(Q))
		printf("Hang doi rong !");
	else
		return Q.pHead->data;
}

SV Pop(Queue &Q) //Loai bo phan tu khoi dau hang doi
{
	if (Isempty(Q))
	{
		printf("Hang doi rong !");
		SV a;
		a.mssv = "";
		a.name = "";
		a.ngaysinh = "";
		return a;
	}
	else
	{
		NODE* p;
		p = Q.pHead;
		SV x = Q.pHead->data;
		if (Q.count == 1) //neu co 1 phan tu
			Init(Q);
		else
			Q.pHead = Q.pHead->pNext;
		Q.count--;
		if (Q.count < 0)
		{
			Q.count = 0;
		}
		delete p;
		return x; 
	}
}

void Delete(Queue &Q)
{
	while (!Isempty(Q))
	{
		SV x = Pop(Q);
	}
}

void docFile(string data, string s, string s2)
{
	
	fstream f0(data, ios::in);
	fstream f1(s2, ios::out);
	SV a;
	string s1;
	Queue Q;
	Init(Q);
	while (!f0.eof())
	{
		getline(f0, a.mssv, ',');
		getline(f0, a.name, ',');
		getline(f0, a.ngaysinh);
		Push(Q, a);
		a.mssv.clear();
		a.name.clear();
		a.ngaysinh.clear();
	}
	f0.close();
	fstream f(s, ios::in);
	a.mssv.clear();
	a.name.clear();
	a.ngaysinh.clear();
	while (!f.eof())
	{
		int pos = f.tellg();
		getline(f, s1);
		if (s1 == "deQueue")
		{
			Pop(Q);
		}
		else
		{
			f.seekg(pos);
			getline(f, s1, ' ');
			getline(f, a.mssv, ',');
			getline(f, a.name, ',');
			getline(f, a.ngaysinh);
			Push(Q, a);
		}
		s1.clear();
		a.mssv.clear();
		a.name.clear();
		a.ngaysinh.clear();
	}
	int x = Q.count;// gan cho x vi khi xoa Q.count se giam
	for (int i = 0; i < x; i++)
	{
		SV b;
		b = Qfront(Q);
		Pop(Q);
		f1 << b.mssv << ", " << b.name << ", " << b.ngaysinh << endl;
		//if (Isempty(Q))
		//{
		//	//f1 << "ds rong" << endl;
		//	break;
		//}
	}
	f.close();

	f1.close();
}