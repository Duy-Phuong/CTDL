#include "thuvien2.h"

void Init(Tree &t)
{
	t = NULL;
}
void InsertNode(Tree &t, float x)
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

NODE* Search(Tree t, float x)
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

void Delete(Tree &t, float x)
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
		Delete(t, t->key);
	}


}
void DocFile(string s)
{
	int n;
	float a[100];
	//cau a
	Tree t;
	Init(t);
	fstream f(s, ios::in);
	f >> n;
	for (int i = 0; i < n; i++)
	{
		f >> a[i];
		InsertNode(t, a[i]);
	}
	f.close();
	cout << "LNR: ";
	Print(t);
	//cau b
	if(Check(t) == true)
		cout << "\ncay nhi phan day du" << endl;
	else
	{
		cout << "\ncay nhi phan khong day du" << endl;
		//cau c
		ConvertFullBinaryTree(t);
		cout << "\nsau khi chuyen thanh cay nhi phan day du: " << endl;
		Print(t);

		if (Check(t) == true)
			cout << "\ncay nhi phan day du" << endl;
		else
			cout << "\ncay nhi phan khong day du" << endl;
	}
}

bool Check(Tree &t)
{
	if (t != NULL)
	{
		if (!isFull(t))
			return false;
		return (Check(t->pLeft) && Check(t->pRight));
	}
	return true;
}

bool isFull(Tree &t)
{
	if (t != NULL)
	{
		if (t->pLeft != NULL && t->pRight != NULL)
			return true;
		if (t->pLeft == NULL && t->pRight == NULL)
			return true;
	}
	
	return false;
}

void Find(Tree &t, float b[], int &nb)
{
	if (t == NULL)
		return;
	else
	{
		if (!isFull(t))
		{
			b[nb++] = t->key;
		}
		Find(t->pLeft, b, nb);
		Find(t->pRight, b, nb);

	}
}

void ConvertFullBinaryTree(Tree &t)
{
	float b[100];
	int nb = 0;
	Find(t, b, nb);
	for (int i = 0; i < nb; i++)
	{
		Delete(t, b[i]);
	}

}