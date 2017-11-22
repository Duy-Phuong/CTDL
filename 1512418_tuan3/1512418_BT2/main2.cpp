#include "thuvien2.h"

int main(int iSoThSo, char* mangThSo[])

{
	cout << "--------BAI 2--------\n";
	//char* mangThSo[] = { "1512345_BT1.exe", "2", "1000000", "output1000000.txt" };
	if (iSoThSo != 4) {
		cerr << "Cau lenh khong dung dinh dang" << endl;

	}
	int dem = atoi(mangThSo[1]);
	int x = atoi(mangThSo[2]);

	int x1;
	cout << "nhap phan tu can tim: ";
	cin >> x1;
	char* s1 = "input.txt";
	ghiFile(dem, x1,mangThSo[3], x);


	return 0;
}
