#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>

struct node
{
	int key;
	struct node *pLeft;
	struct node *pRight;
};
typedef struct node NODE;
typedef NODE* Tree;
void Init(Tree &t);
void InsertNode(Tree &t, int x);
void Print(Tree t);
NODE* Search(Tree t, int x);
void Delete(Tree &t, int x);
void TimPhanTuTheMang(Tree &p, Tree &q);
void Remove(Tree &t);