#include "thuvien4.h"

int main(int iThamSo, char* mangThamSo[])
{
	//char* mangThamSo[] = { "1", "inputBT4.txt", "outputBT4.txt" };
	if (iThamSo != 3)
	{
		cout << "cau lenh khong dung dinh dang!" << endl;
		return 0;
	}

	docFile(mangThamSo[1], mangThamSo[2]);

	return 0;
}