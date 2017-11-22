#include "thuvien1.h"

void Init(Tree &t)
{
	t = NULL;
}
void InsertNode(Tree &t, int x)
{
	if (t == NULL)//neu NODE rong
	{
		NODE* q = new NODE;
		q->key = x;
		q->pLeft = q->pRight = NULL;
		t = q;
		
	}
	else
	{
		if (t->key == x)
			return;
		if (t->key > x)
			return InsertNode(t->pLeft, x);
		else
			return InsertNode(t->pRight, x);
		
	}
}

void Print(Tree t)
{
	if (t == NULL)
		return;
	else
	{
		
		Print(t->pLeft);
		cout << t->key << "  ";
		Print(t->pRight);
		
	}
}

NODE* Search(Tree t, int x)
{
	if (t == NULL)//neu NODE rong
	{
		return NULL;
	}
	else
	{
		if (t->key > x)
			return Search(t->pLeft, x);
		if (t->key < x)
			return Search(t->pRight, x);
		if (t->key == x)
		{
			return t;
		}
	}
}
void TimPhanTuTheMang(Tree &p, Tree &q)
{
	if (q->pLeft != NULL)//tim phan tu trai nhat cay con phai
	{
		TimPhanTuTheMang(p, q->pLeft);
	}
	else
	{
		p->key = q->key;
		p = q;
		q = q->pRight;
	}
}
//xoa TH bang de cuoi
void Delete(Tree &t, int x)
{
	if (t == NULL)//neu NODE rong
	{
		return;
	}
	else
	{
		if (t->key > x)
			return Delete(t->pLeft, x);
		if (t->key < x)
			return Delete(t->pRight, x);
		if (t->key == x)
		{
			NODE* p = t;
			if (t->pLeft == NULL)
			{
				t = t->pRight;
			}
			else if (t->pRight == NULL)
			{
				t = t->pLeft;
			}
			//xoa node có 2 con
			else
			{
				TimPhanTuTheMang(p, t->pRight);
			}
			delete p;
		}
	}
}

void Remove(Tree &t)
{
	if (t == NULL)
		return;
	else
	{
		Remove(t->pLeft);
		Remove(t->pRight);
		Delete(t, t->key);//xoa la
	}

	
}
