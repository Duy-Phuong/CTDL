#include "thuvien2.h"

int main()
{
	char* mangThamSo[] = { "uncompress", "1512418.out.txt", "output.huf.txt", "1512418.ketqua.txt"};

	uncompress(mangThamSo[1], mangThamSo[2], mangThamSo[3]);
	system("pause");
	return 0;
}