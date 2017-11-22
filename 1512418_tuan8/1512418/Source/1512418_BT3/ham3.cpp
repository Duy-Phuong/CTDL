#include "thuvien3.h"


AVLNODE* CreateNode(SV Data)
{
	AVLNODE* pNode;
	pNode = new AVLNODE; //Xin cấp phát bộ nhớ động để tạo một phần tử (node) mới
	if (pNode == NULL){
		return NULL;
	}
	pNode->Key.MSSV = Data.MSSV;
	pNode->Key.name = Data.name;
	pNode->pLeft = NULL;
	pNode->pRight = NULL;
	pNode->bal = 0; //khoi tao he so can bang la 0
	return pNode;
}
void LeftRotate(AVLNODE* &P)
{
	AVLNODE *Q;
	Q = P->pRight;
	P->pRight = Q->pLeft;
	Q->pLeft = P;
	P = Q;
}
void RightRotate(AVLNODE* &P)
{
	AVLNODE *Q;
	Q = P->pLeft;
	P->pLeft = Q->pRight;
	Q->pRight = P;
	P = Q;
}
void LeftBalance(AVLNODE* &P)
{
	switch (P->pLeft->bal){
	case 1: //mất cân bằng trái trái
		RightRotate(P);
		P->bal = 0;
		P->pRight->bal = 0;
		break;
	case 2: //mat can bang trai phai
		LeftRotate(P->pLeft);
		RightRotate(P);
		switch (P->bal){
		case 0:
			P->pLeft->bal = 0;
			P->pRight->bal = 0;
			break;
		case 1:
			P->pLeft->bal = 0;
			P->pRight->bal = 2;
			break;
		case 2:
			P->pLeft->bal = 1;
			P->pRight->bal = 0;
			break;
		}
		P->bal = 0;
		break;
	}
}
void RightBalance(AVLNODE* &P)
{
	switch (P->pRight->bal){
	case 1: //mat can bang phai trai
		RightRotate(P->pRight);
		LeftRotate(P);
		switch (P->bal){
		case 0:
			P->pLeft->bal = 0;
			P->pRight->bal = 0;
			break;
		case 1:
			P->pLeft->bal = 1;
			P->pRight->bal = 0;
			break;
		case 2:
			P->pLeft->bal = 0;
			P->pRight->bal = 2;
			break;
		}
		P->bal = 0;
		break;
	case 2: //mat can bang phai phai
		LeftRotate(P);
		P->bal = 0;
		P->pLeft->bal = 0;
		break;
	}
}
int InsertNode(AVLNODE* &tree, SV x)
{
	int res;
	if (tree == NULL)
	{ //neu cay rong
		tree = CreateNode(x);
		if (tree == NULL)
		{
			return -1; //thêm ko thành công vì thiếu bộ nhớ
		}
		return 2;//thêm thành công và làm tăng chiều cao cây
	}
	else
	{
		if (tree->Key.MSSV == x.MSSV)
		{
			return 0; //khóa này đã tồn tại trong cây
		}
		else if (tree->Key.MSSV > x.MSSV)
		{
			res = InsertNode(tree->pLeft, x);// chen vao cay con ben trai
			if (res < 2) // neu da ton tai hoac them khong thanh cong
			{
				return res;
			}
			switch (tree->bal)
			{ //neu them thanh cong kiem tra cay can bang
			case 0://dang can bang
				tree->bal = 1;//lech trai
				return 2;
			case 1://dang lech trai
				LeftBalance(tree);//can bang trai
				return 1;
			case 2://dang lech phai
				tree->bal = 0;//them trai => can bang
				return 1;
			}
		}
		else// x > tree->Key
		{
			res = InsertNode(tree->pRight, x);// chen vao cay con ben phai
			if (res<2)
			{
				return res;
			}
			switch (tree->bal)
			{
			case 0:
				tree->bal = 2;
				return 2;
			case 1:
				tree->bal = 0;
				return 1;
			case 2:
				RightBalance(tree);
				return 1;
			}
		}
	}
}
void Traverse(AVLNODE* t)
{
	if (t != NULL)
	{
		Traverse(t->pLeft);
		cout << "mssv: " << t->Key.MSSV << " ten: " << t->Key.name << " can bang: " << t->bal << endl;
		Traverse(t->pRight);
	}
}
int TimPhanTuTheMang(AVLNODE* &p, AVLNODE* &q)
{
	int res;
	if (q->pLeft != NULL)//tim phan tu trai nhat cay con phai
	{
		res = TimPhanTuTheMang(p, q->pLeft);
		if (res < 2)
			return res;
		switch (q->bal)
		{
		case 0://dang can bang
			q->bal = 2;//lech phai
			return 1;//chieu cao khong thay doi
		case 1://lech trai
			q->bal = 0;// can bang
			return 2;// chieu dai cay thay doi
		case 2:
			return Balance_Right(q);
		}
	}
	else
	{
		p->Key = q->Key;
		p = q;
		q = q->pRight;
		return 2;
	}

}
int Balance_Right(AVLNODE* t)
{
	AVLNODE* T1 = t->pRight;

	switch (T1->bal)
	{
	case 0://dang can bang
		RightBalance(t);
		return 1; //chieu dai cay khong thay doi
	case 1://dang lech trai
		RightBalance(t);
		return 2;
	case 2://dang lech phai
		RightBalance(t);
		return 2;
	}
	return 0;
}
int Balance_Left(AVLNODE* t)
{
	AVLNODE* T1 = t->pLeft;

	switch (T1->bal)
	{
	case 0://dang can bang
		LeftBalance(t);
		return 1; //chieu dai cay khong thay doi
	case 1://dang lech trai
		LeftBalance(t);
		return 2;
	case 2://dang lech phai
		LeftBalance(t);
		return 2;
	}
	return 0;
}
int Delete(AVLNODE* &t, SV x)
{
	int res;
	if (t == NULL)//neu NODE rong
	{
		return 0;
	}
	else
	{
		if (t->Key.MSSV > x.MSSV)
		{
			res = Delete(t->pLeft, x);
			if (res < 2)
			{
				return res;
			}
			switch (t->bal)
			{
			case 0://dang can bang
				t->bal = 2;//lech phai sau khi xoa
				return 1; //chieu dai cay khong thay doi
			case 1://dang lech trai
				t->bal = 0;//can bang sau khi xoa
				return 2;
			case 2://dang lech phai xoa khong thay doi nen ta chi can can bang
				return Balance_Right(t);
			}

		}
		if (t->Key.MSSV < x.MSSV)
		{
			res = Delete(t->pRight, x);
			if (res < 2)
			{
				return res;
			}
			switch (t->bal)
			{
			case 0://dang can bang
				t->bal = 1;//lech trai sau khi xoa
				return 1; //chieu dai cay khong thay doi
			case 2://dang lech phai
				t->bal = 0;//can bang sau khi xoa
				return 2;
			case 1://dang lech trai xoa khong thay doi nen ta chi can can bang
				return Balance_Left(t);
			}

		}
		if (t->Key.MSSV == x.MSSV)
		{
			AVLNODE* p = t;
			if (t->pLeft == NULL)
			{
				t = t->pRight;
				res = 2;
			}
			else if (t->pRight == NULL)
			{
				t = t->pLeft;
				res = 2;
			}
			//xoa node có 2 con
			else
			{
				res = TimPhanTuTheMang(p, t->pRight);
				if (res < 2)
				{
					return 2;
				}
				switch (t->bal)
				{
				case 0://dang can bang
					t->bal = 1; //lech trai
					return 1;
				case 2:// lech phai
					t->bal = 0;// xoa can bang lai
					return 2;
				case 1:// lech trai
					return Balance_Left(t);// sau khi xoa can bang lai
				}
			}
			delete p;
			return res;
		}
	}
}
void RemoveAll(AVLNODE* &t)
{
	if (t == NULL)
		return;
	if (t != NULL)
	{
		RemoveAll(t->pLeft);
		RemoveAll(t->pRight);
		Delete(t, t->Key);
	}
}
AVLNODE* Search(AVLNODE* t, SV x)
{
	if (t == NULL)//neu NODE rong
	{
		return NULL;
	}
	else
	{
		if (t->Key.MSSV > x.MSSV)
			return Search(t->pLeft, x);
		if (t->Key.MSSV < x.MSSV)
			return Search(t->pRight, x);
		if (t->Key.MSSV == x.MSSV)
		{
			return t;
		}
	}
}
