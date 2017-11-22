#include "LinearProbe.h"

void Init(int *&table, int M) {
	for (int i = 0; i < M; i++)
		table[i] = NULL;
	::N = 0; // số phần tử đã sử dụng trong bảng
}

bool Full(int M) {
	return N >= (M - 1); // bảng đầy khi số phần tử bằng M-1. ta giữ lại một ô nhớ trống
}

int FindTableLinear(int* table, int M, int key) {
	int count = M - 1;
	int index = HashFunc(key, M); // biến đổi key
	while (count != 0 && table[index] != key && table[index] != NULL) {
		index++; // băm lại theo hệ thức h(k) = (h(k)+1) % M
		count--;
		if (index >= M)
			index = index - M;
	}
	if (table[index] == key) //tìm thấy khóa
		return index; //trả về địa chỉ khóa
	return -1;
}

void InsertTableLinear(int* &table, int M, int key) {
	if (Full(M)) {
		cout << "Table in full, can not add more element." << endl;
		return;
	}
	if (FindTableLinear(table, M, key) != -1) {
		cout << "element "<<key<<" existed. " << endl;
		return;
	}
	int index = HashFunc(key, M); //biến đổi khóa key 
	while (table[index] != NULL) { // tìm ô trống trong bảng băm
		index++; // băm lại theo hệ thức h(k) = (h(k)+1) % M
		if (index >= M)
			index -= M;
	}
	table[index] = key;
	::N = ::N + 1;
}


void LinearProbe(string input,string output,int key) {
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
	if (space_collection % 2 == 0) // nên lấy giá trị không gian là một số lẻ để tránh tình trạng lặp lại bội số
		space_collection += 1;
	int i;

	int *table = new int[space_collection]; 	//tạo bảng băm có 'khong_gian' ô nhớ

	//số phần tử mảng
	int number_ele;
	fpi >> number_ele; //lấy số phần tử từ file input
	Init(table, space_collection); //khởi tạo bảng NULL

	for (i = 0; i < number_ele; i++) {
		fpi >> temp; //lấy 1 phần tử từ file input
		InsertTableLinear(table, space_collection, temp); //đưa phần tử vào bảng
	}
	
	//duyệt bảng để xuất phần tử ra file output
	for (i = 0; i < space_collection; i++) {
		if (table[i] == NULL) //các ô không có phần tử thì để trống
			fpo << endl;
		else
			fpo << table[i] << endl;
	}
	int index = FindTableLinear(table, space_collection, key); //tìm khóa key
	fpo << index << endl;

	fpi.close();
	fpo.close();
	delete[]table;
}
