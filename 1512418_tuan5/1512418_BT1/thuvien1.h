#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>

struct node
{
	char data;
	struct node *pNext;
};
typedef struct node NODE;


typedef struct stack
{
	NODE* Top;
};


void InitStack(stack &s);
bool IsEmpty(stack &s);
NODE* GetNode(char x);
void Push_back(stack &s, char x);
char Pop_back(stack &s);
char TopStack(stack &s);
void DeleteStack(stack &s);
void docFile(string s, string s1);
