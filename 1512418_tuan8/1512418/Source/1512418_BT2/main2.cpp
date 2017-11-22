#include "thuvien2.h"

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
	int x;
	cout << "\n1. nhap vao khoa x: ";
	cin >> x;
	AVLNODE* a = Search(tree, x);
	if (a != NULL)
	{
		cout << "phan tu " << x << " co ton tai trong cay\n";
	}
	else
	{
		cout << "phan tu " << x << " khong ton tai trong cay\n";
	}
	cout << "\n4. xoa 1 node: \n";
	int x1;
	cout << "nhap x: ";
	cin >> x1;
	Delete(tree, x1);
	cout << "\nCay AVL sau khi xoa: \n";
	Traverse(tree);

	RemoveAll(tree);
	if (tree == NULL)
		cout << "xoa thanh cong\n";


	cout << "\n2.\n";
	DocFile("input.txt");
	system("pause");
	return 0;
}