#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>

struct node
{
	float key;
	struct node *pLeft;
	struct node *pRight;
};
typedef struct node NODE;
typedef NODE* Tree;
void Init(Tree &t);
void InsertNode(Tree &t, float x);
void Print(Tree t);
NODE* Search(Tree t, float x);
void Delete(Tree &t, float x);
void TimPhanTuTheMang(Tree &p, Tree &q);
void Remove(Tree &t);
void DocFile(string s);
bool Check(Tree &t); // kem tra cay nhi phan day du
bool isFull(Tree &t); //la node du
void Find(Tree &t, float b[], int &nb); // tim nhu node k day du de chuyen thanh cay nhi phan day du
void ConvertFullBinaryTree(Tree &t);