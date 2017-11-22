#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>

struct SV
{
	string name;
	string mssv;
	string ngaysinh;
};

struct node
{
	SV data;
	struct node *pNext;
};
typedef struct node NODE;

struct Queue
{
	NODE* pHead;
	NODE* pTail;
	int count;
};

void Init(Queue &Q);

int Isempty(Queue Q);
NODE* GetNode(SV x);

void Push(Queue &Q, SV x);
SV Qfront(Queue Q);
SV Pop(Queue &Q);
void Delete(Queue &Q);

void docFile(string data, string s, string s1);
