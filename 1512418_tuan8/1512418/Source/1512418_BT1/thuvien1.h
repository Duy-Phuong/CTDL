#include <iostream>
using namespace std;
#include <fstream>
#include <string>



struct AVLNODE
{
	int Key;
	int bal; // thuộc tính cho biết giá trị cân bằng
	// 0: cân bằng, 1: lệch trái, 2: lệch phải
	AVLNODE* pLeft;
	AVLNODE* pRight;
};
AVLNODE* CreateNode(int Data);
void LeftRotate(AVLNODE* &P);
void RightRotate(AVLNODE* &P);
void LeftBalance(AVLNODE* &P);
void RightBalance(AVLNODE* &P);
int InsertNode(AVLNODE* &tree, int x);
void Traverse(AVLNODE* t);
int TimPhanTuTheMang(AVLNODE* &p, AVLNODE* &q);
int Balance_Right(AVLNODE* t);
int Balance_Left(AVLNODE* t);
int Delete(AVLNODE* &t, int x);
void RemoveAll(AVLNODE* &t);