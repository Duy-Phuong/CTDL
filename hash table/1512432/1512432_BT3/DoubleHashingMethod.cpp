#include "DoubleHashingMethod.h"


//hàm băm thứ 2
int HashFunc2(int key, int M) {
	return abs( (M - 2) - key % (M - 2));
}

/*tìm khóa key trong bảng băm theo pp băm kép*/
int FindDoubleTable(int* table, int M, int key) {
	int i = HashFunc(key, M); //băm lần 1
	int j = HashFunc2(key, M); //lấy băm kép

	while (table[i] != key && table[i] != NULL) {
		i = (i + j) % M;
	}
	if (table[i] == key)
		return i;
	return -1;
}

void InsertHashDouble(int* &table, int M, int key) {

	if (Full(M)) {
		//cout << "full "<<endl;
		return;
	}

	int find = FindDoubleTable(table, M, key);
	if (find != -1) {
		return;
	}
	int i = HashFunc(key, M);
	int j = HashFunc2(key, M);
	while (table[i] != NULL)
		i = (i + j) % M;

	table[i] = key;
	::N = ::N + 1;
}

void DoubleHashingMethod(string input, string output, int key) {
	ifstream fpi(input);
	if (fpi.fail()) {
		cerr << "can not open input file ( test name, file tail...)" << endl;
		return;
	}

	ofstream fpo(output);
	if (fpo.fail()) {
		cerr << "can not open input file ( test name, file tail...)" << endl;
		return;
	}

	int temp; //lấy kích thước không gian từ file input
	fpi >> temp;
	int space_collection = temp;
	if (space_collection % 2 == 0)
		space_collection += 1; //tạo không gian bảng băm là một số lẻ
	int i;

	int *table = new int[space_collection]; 	//tạo bảng băm có 'khong_gian' ô nhớ

	int number_ele; 	//số phần tử mảng
	fpi >> number_ele; //lấy số phần tử từ file input
	Init(table, space_collection); // khởi tạo bảng băm

	for (i = 0; i < number_ele; i++) {
		fpi >> temp;
		InsertHashDouble(table, space_collection, temp);
	}

	for (i = 0; i < space_collection; i++) {
		if (table[i] == NULL)
			fpo << endl;
		else
			fpo << table[i] << endl;
	}
	int index = FindDoubleTable(table, space_collection, key);
	fpo << index << endl;

	delete[]table;


	fpi.close();
	fpo.close();

}