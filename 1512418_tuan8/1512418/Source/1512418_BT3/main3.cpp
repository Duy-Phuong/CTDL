#include "thuvien3.h"

int main()
{
	AVLNODE *tree;
	tree = NULL;// khoi tao cay AVL = NULL
	SV Data;
	do
	{
		cout << "Nhap vao du lieu,mssv -1 de ket thuc: ";
		cout << "nhap mssv: ";
		cin >> Data.MSSV;
		if (Data.MSSV == -1)
			break;
		cout << "nhap ten: ";
		fflush(stdin);
		getline(cin, Data.name);

		InsertNode(tree, Data);
	} while (Data.MSSV != -1);
	cout << "\nCay AVL vua tao: \n";
	Traverse(tree);
	SV x;
	cout << "nhap mssv: ";
	cin >> x.MSSV;
	AVLNODE* a = Search(tree, x);
	if (a != NULL)
	{
		cout << " co ton tai trong cay\n";
	}
	else
	{
		cout << " khong ton tai trong cay\n";
	}
	cout << "\n4. xoa 1 node: \n";
	SV x1;
	cout << "nhap mssv: ";
	cin >> x1.MSSV;
	getline(cin, x1.name);
	Delete(tree, x1);
	cout << "\nCay AVL sau khi xoa: \n";
	Traverse(tree);

	RemoveAll(tree);
	if (tree == NULL)
		cout << "xoa thanh cong\n";

	system("pause");
	return 0;
}