#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <vector>

struct CN
{
	string ID;
	string name;
	int birth_year;
};
void shift(vector <CN> &a, int l, int r);
void CreateHeap(vector <CN> &a);
void HeapSort(vector <CN> &a);
void docFile(string s1, string s2);

