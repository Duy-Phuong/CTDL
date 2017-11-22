#include "thuvien1.h"

int main(int iSoThSo, char* mangThSo[])
{
	cout << "--------BAI 1--------\n";
	//char* mangThSo[] = {"1512418_BT1.exe", "1", "3", "test1.txt", "output1.txt"};
	//char* mangThSo[] = {"1512418_BT1.exe", "2", "3", "test2.txt", "output2.txt"};
	//char* mangThSo[] = {"1512418_BT1.exe", "3", "3", "test3.txt", "output3.txt"};
	if (iSoThSo < 4)
	{
		printf("Nhap sai qui dinh");
	}
	int dem = atoi(mangThSo[1]);
	int x = atoi(mangThSo[2]);
	ghiFile(dem, x, mangThSo[4], mangThSo[3]);
		return 0;
}
