#include "QuadraticPropingMethod.h"


int FindTableQuadratic(int* table, int M, int key) {
	int index = HashFunc(key, M); // chuyển đổi khóa key
	int dem = 1; // biến nhảy
	while (table[index] != key && table[index] != NULL) {
		index = (index + dem) % M; //băm lại bằng phương thức băm bậc 2 (dem)
		dem += 2;
	}
	if (table[index] == key) //tìm được khóa k
		return index; //trả về địa chỉ ô nhớ
	return -1;
}

void InsertHashTableQuadratic(int* &table, int M, int key) {
	if (Full(M)) { // kiểm tra bảng đầy
		cout << "table in full, can not add more element." << endl;
		return;
	}
	if (FindTableQuadratic(table, M, key) != -1) { //kiểm tra khóa key đã có chưa
		cout << "Element " << key << " existed. ";
		return;
	}

	int index = HashFunc(key, M); //biến đổi khóa key
	int dem = 1;
	while (table[index] != NULL) {
		index = ((index + dem) % M);  // băm lại theo hệ thức h(k) = (h(k) + i^2 % M
		dem += 2;
	}
	table[index] = key;
	::N = ::N + 1; //tăng số ô nhớ đầy trong bảng
}

void QuadraticPropingMethod(string input, string output, int key) {
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
	if (space_collection % 2 == 0) //lấy số ô nhớ của bảng băm là một số lẻ 
		space_collection += 1;
	int i;

	int *table = new int[space_collection]; 	//tạo bảng băm có 'khong_gian' ô nhớ

	//số phần tử mảng											
	int number_ele;
	fpi >> number_ele; //lấy số phần tử từ file input
	Init(table, space_collection); //khởi tạo bảng băm

	for (i = 0; i < number_ele; i++) {
		fpi >> temp; //lấy phần tử từ file input
		InsertHashTableQuadratic(table, space_collection, temp); //chèn vào bảng băm
	}

	//duyệt bảng đ xuất phần tử ra file
	for (i = 0; i < space_collection; i++) {
		if (table[i] == NULL)
			fpo << endl;
		else
			fpo << table[i] << endl;
	}

	int index = FindTableQuadratic(table, space_collection, key);
	fpo << index << endl;

	fpi.close();
	fpo.close();
	delete[]table;

}
