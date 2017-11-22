#include "thuvien1.h"

int main()
{
	//char* mangThamSo[] = {"compress", "1512418.in0.txt", "1512418.out.txt"};
	char* mangThamSo[] = { "uncompress", "1512418.out.txt", "output.huf.txt", "1512418.ketqua.txt" };
	//compress(mangThamSo[1], mangThamSo[2]);
	uncompress(mangThamSo[1], mangThamSo[2], mangThamSo[3]);
	system("pause");
	return 0;
}