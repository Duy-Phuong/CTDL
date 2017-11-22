#include "thuvien3.h"

int main(int iSoThSo, char* mangthamso[])

{
	//1512345_BT1.exe 1 7 test1.txt out1.txt
	cout << "--------BAI 3--------\n";
	//char* mangthamso[] = { "1512345_BT1", "1", "7", "testBT3_02.txt", "output2_BT3.txt" };
	if (iSoThSo != 5) {
		cerr << "Cau lenh khong dung dinh dang" << endl;
	
	}

	int thuat_toan = atoi(mangthamso[1]);
	int key = atoi(mangthamso[2]);

	string input = mangthamso[3]; 
	string output = mangthamso[4];

	switch (thuat_toan)
	{
	case 1: {
				ChainingMethod(input, output, key);
				break;
	}
	case 2: {
				LinearProbe(input, output, key);
				break;
	}
	default:
		break;
	}

	return 0;
}