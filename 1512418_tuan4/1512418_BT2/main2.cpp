#include "thuvien2.h"

int main(int iThamSo, char* mangThamSo[])
{
	//char* mangThamSo[] = { "1", "3", "inputBT2.txt", "outputBT2.txt" };
	if (iThamSo != 4)
	{
		cout << "cau lenh khong dung dinh dang!" << endl;
		return 0;
	}
	int  x = atoi(mangThamSo[1]);
	docFile(x, mangThamSo[2], mangThamSo[3]);
	return 0;
}