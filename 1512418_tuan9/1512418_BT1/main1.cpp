#include "thuvien1.h"

int main(int soThamSo, char* mangThamSo[])
{
	if (strcmp(mangThamSo[1], "compress") == 0)
	{
		compress(mangThamSo[2], mangThamSo[3]);
	}
	if (strcmp(mangThamSo[1], "uncompress") == 0)
	{
		uncompress(mangThamSo[2], mangThamSo[3], mangThamSo[4]);
	}
	system("pause");
	return 0;
}