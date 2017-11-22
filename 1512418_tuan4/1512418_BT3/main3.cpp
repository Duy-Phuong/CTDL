#include "thuvien3.h"

int main(int iThamSo, char* mangThSo[])
{
	//char* mangThSo[] = { "1512345_BT1.exe", "3", "100000", "output100000.txt" };
	if (iThamSo != 4)
	{
		cout << "cau lenh khong dung dinh dang!" << endl;
		return 0;
	}
	int dem = atoi(mangThSo[1]);
	int x = atoi(mangThSo[2]);

	char* s1 = "inputBT3.txt";
	ghiFile(dem, mangThSo[3], x);

	return 0;
}