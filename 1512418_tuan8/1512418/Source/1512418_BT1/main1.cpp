#include "thuvien1.h"

int main()
{
	AVLNODE *tree;
	tree = NULL;// khoi tao cay AVL = NULL
	int Data;
	do
	{
		cout << "Nhap vao du lieu, -1 de ket thuc: ";
		cin >> Data;
		if (Data == -1)
			break;
		InsertNode(tree, Data);
	} while (Data != -1);
	cout << "\nCay AVL vua tao: \n";
	Traverse(tree);
	RemoveAll(tree);
	if (tree == NULL)
		cout << "xoa thanh cong\n";
	system("pause");
	return 0;
}