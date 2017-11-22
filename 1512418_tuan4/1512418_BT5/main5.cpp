#include "thuvien5.h"

int main(int iThamSo, char* mangThamSo[])

{
	//char* mangThamSo[] = { "1", "employee.txt", "sorted.txt" };
	if (iThamSo != 3)
	{
		cout << "cau lenh khong dung dinh dang!" << endl;
		return 0;
	}
	docFile(mangThamSo[1], mangThamSo[2]);
	return 0;
}