#pragma once
#include "lib.h"

void main(int i_so_tham_so, char* c_mang_tham_so[]) {
	if (i_so_tham_so != 3) {
		cout << "Dong lenh khong dung dinh dang. " << endl;
		return;
	}

	string dictionary = "Dictionary.txt"; 
	string input = c_mang_tham_so[1];
	string output = c_mang_tham_so[2];

	ifstream fpi(input);
	if (fpi.fail()) {
		cerr << "khong mo duoc file chua du lieu." << endl;
		return;
	}

	ofstream fpo(output);
	if (fpo.fail()) {
		cerr << "khong mo duoc file de ghi ket qua." << endl;
		return;
	}

	vector<list<string>> table(SPACE_COLLECTION);
	CreatTableDict(dictionary, table, SPACE_COLLECTION);

	FindErrorWord(fpi, fpo, table, SPACE_COLLECTION);

	fpi.close();
	fpo.close();
}