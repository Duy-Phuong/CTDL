#include "thuvien.h"

int main(int n, char* mangThamSo[])
{
	//char* mangThamSo[] = { "" , "2", "dulieu9.txt", "truyvan.txt", "ketqua.txt" };
	int a = atoi((char*)mangThamSo[1]);
	
	docFile(a, mangThamSo[2], mangThamSo[3], mangThamSo[4]);
	cout << endl;
	return 0;
}