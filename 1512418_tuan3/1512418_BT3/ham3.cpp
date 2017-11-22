#include "thuvien3.h"


int hamBam1(const int k, const int M) 
{
	return (k%M);
}

bool timKiem(list<int> k, int key) 
{
	if (k.empty()) 
	{
		return false;
	}
	for (list<int>::iterator it = k.begin(); it != k.end(); it++)
	{
		if (*it == key)
		{
			return true;
		}
	}
	return false;
}

void DuyetDS(ofstream& f, list<int> l)
{
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		f << *it << " ";
	}
}

void ChainingMethod(string input, string output, int key)
{

	fstream f(input, ios::in);
	int kichThuoc;
	f >> kichThuoc;
	f.ignore();
	vector< list<int> > table(kichThuoc);
	int t;
	int soPhanTu;		
	f >> soPhanTu;
	f.ignore();
	int k;
	for (int i = 0; i < soPhanTu; i++) {
		f >> t; 
		k = hamBam1(t, kichThuoc); 
		table[k].push_back(t); 
	}

	ofstream f1(output); 

	k = hamBam1(key, kichThuoc); 
	for (int i = 0; i < kichThuoc; i++) {
		if (table[i].empty())
		{
			f1 << endl;
			continue;
		}
		list<int>::iterator first = table[i].begin(); 
		while (first != table[i].end()) {
			f1 << *first << " ";
			first++;
		}
		f1 << endl;
	}
	bool kq = timKiem(table[k], key);
	if (kq)
		f1 << k;
	else
		f1 << -1 << endl;

	f.close();
	f1.close();
}



void Init(int* &table, int M) {
	for (int i = 0; i < M; i++)
		table[i] = NULL;
	::N = 0;
}

bool Full(int M) {
	return ::N >= (M - 1);
}

int FindTableLinear(int* table, int M, int key) {
	int count = M - 1;
	int index = hamBam1(key, M); 
	while (count != 0 && table[index] != key && table[index] != NULL) {
		index++; 
		count--;
		if (index >= M)
			index = index - M;
	}
	if (table[index] == key)
		return index;
	return -1;
}


void InsertTableLinear(int* &table, int M, int key) {
	if (Full(M)) {
		cout << "bang bam day!" << endl;
		return;
	}
	if (FindTableLinear(table, M, key) != -1) {
		cout << "phan tu " << key << " da ton tai" << endl;
		return;
	}
	int index = hamBam1(key, M);
	while (table[index] != NULL) { 
		index++; 
		if (index >= M)
			index -= M;
	}
	table[index] = key;
	::N = ::N + 1;
}


void LinearProbe(string input, string output, int key) {
	ifstream f(input);

	ofstream f1(output);
	int temp; 
	f >> temp;
	int kichthuoc = temp;
	if (kichthuoc % 2 == 0)
		kichthuoc += 1;
	int i;

	int *table = new int[kichthuoc]; 

	int n;
	f >> n;
	Init(table, kichthuoc);

	for (i = 0; i < n; i++) {
		f >> temp;
		InsertTableLinear(table, kichthuoc, temp);
	}

	for (i = 0; i < kichthuoc; i++) {
		if (table[i] == NULL)
			f1 << endl;
		else
			f1 << table[i] << endl;
	}
	int index = FindTableLinear(table, kichthuoc, key);
	f1 << index << endl;

	f.close();
	f1.close();
	delete[]table;
}

