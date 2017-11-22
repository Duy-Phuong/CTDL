#include "thuvien2.h"


int main()
{
	char* mangThamSo[] = { "input1.txt", "input2.txt", "input3.txt" };
	cout << "--------ket qua sau khi doc tap tin input1.txt----------" << endl;
	DocFile(mangThamSo[0]);
	cout << "\n--------ket qua sau khi doc tap tin input2.txt----------" << endl;
	DocFile(mangThamSo[1]);
	cout << "\n--------ket qua sau khi doc tap tin input3.txt----------" << endl;
	DocFile(mangThamSo[2]);
	system("pause");
	return 0;
}