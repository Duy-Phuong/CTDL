#include <iostream>
using namespace std;
#include <fstream>
#include <string>

struct SV
{
	int MSSV;
	string name;
};

struct AVLNODE
{
	SV Key;
	int bal; // thuộc tính cho biết giá trị cân bằng
	// 0: cân bằng, 1: lệch trái, 2: lệch phải
	AVLNODE* pLeft;
	AVLNODE* pRight;
};
AVLNODE* CreateNode(SV Data);
void LeftRotate(AVLNODE* &P);
void RightRotate(AVLNODE* &P);
void LeftBalance(AVLNODE* &P);
void RightBalance(AVLNODE* &P);
int InsertNode(AVLNODE* &tree, SV x);
void Traverse(AVLNODE* t);
int TimPhanTuTheMang(AVLNODE* &p, AVLNODE* &q);
int Balance_Right(AVLNODE* t);
int Balance_Left(AVLNODE* t);
int Delete(AVLNODE* &t, SV x);
void RemoveAll(AVLNODE* &t);
AVLNODE* Search(AVLNODE* t, SV x);