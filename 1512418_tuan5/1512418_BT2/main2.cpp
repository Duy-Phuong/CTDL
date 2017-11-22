#include "thuvien2.h"


//int main(int soThamSo, char* mangThamSo[])
int main()
{
	char* mangThamSo[] = { "a", "data.txt", "input_BT2.txt", "output_BT2.txt" };
	//if (soThamSo != 4)
	//{
	//	cout << "khong dung dinh dang!" << endl;
	//	return 0;
	//}
	docFile(mangThamSo[1], mangThamSo[2], mangThamSo[3]);

	return 0;
}