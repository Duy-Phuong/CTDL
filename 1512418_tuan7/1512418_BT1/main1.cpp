#include "thuvien1.h"


int main()
{
	Tree t;
	Init(t);
	int a[] = { 18, 13, 37, 15, 23, 40};
	for (int i = 0; i < 6; i++)
	{
		InsertNode(t, a[i]);
	}
	cout << "LNR: ";
	Print(t);
	int x, y;
	cout << "\nnhap phan tu can tim: ";
	cin >> x;

	NODE* q = Search(t, x);
	if (q == NULL)
	{
		cout << "\nkhong tim thay phan tu" << endl;
	}
	else
	{
		cout << "\ntim thay phan tu: " <<q->key << " " << endl;
	}
	cout << "nhap phan tu can xoa: ";
	cin >> y;
	cout << "sau khi xoa: " << endl;
	Delete(t, y);
	Print(t);
	Remove(t);
	if (t == NULL)
		cout << "\nxoa thanh cong cay" << endl;
	system("pause");
	return 0;
}