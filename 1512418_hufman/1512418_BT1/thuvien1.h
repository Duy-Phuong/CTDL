#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string.h>

struct node 
{
	unsigned char c;  // ký tự tại nút
	unsigned int f;   // tần số xuất hiện
	struct node *pLeft, *pRight; // các nút con
	string code;
};
typedef struct node NODE;
void Init(NODE* &t);
NODE* creatNode(char y, int x);
void InsertNode(NODE* &t, char y, int x);
void Print(NODE* &t);

void compress(string s, string s1);
NODE* huffman(vector<NODE*> Q);
void SORT(vector<NODE*> Q);
void swap(NODE* &x, NODE* &y);

void phatSinhBit(NODE* &t, string c);
int getBit(char x, int vt);
void onBit(char &x, int vt);
void offBit(char &x, int vt);
void Table(NODE* t, vector <NODE*> &a);
string timMaBit(vector <NODE*> t, char c);

void uncompress(string s, string s1, string s2);