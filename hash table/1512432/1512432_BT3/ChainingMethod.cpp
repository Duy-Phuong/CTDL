#include "ChainingMethod.h"

//hàm băm, xử lý khóa K thành địa chỉ
int HashFunc(const int k, const int M) {
	return abs(k%M); //băm lấy phần dư
}

//Tìm địa chỉ của khóa key trong DSLK của ô địa chỉ tương ứng
bool SearchInList(list<int> k, int key) {
	if (k.empty()) { // nếu DSLk rỗng
		return false;
	}
	list<int>::iterator first_element = k.begin(); // địa chỉ phần tử đầu tiên trong danh sách
	while (first_element != k.end() && *first_element != key) //chưa hết DSLK và chưa tìm được khóa key
		first_element++; //đi tới địa chỉ kế tiếp trong DSLK
	if (*first_element == key) //nếu tìm thấy
		return true; //trả về true
	return false;
}

//duyệt cả danh sách tại ô nhớ cụ thể và xuất các giá trị ra file mà fpo dẫn đến
void TravelList(ofstream& fpo, list<int> l) {
	list<int>::iterator first = l.begin(); // vị trí đầu tiên của DS
	while (first != l.end()) { //chưa đến cuối DS
		fpo << *first << " "; // xuất ra file output theo yêu cầu
		first++; //đi đến địa chỉ kế tiếp trong DSLK
	}
}

void ChainingMethod(string input,string output,int key) {
	
	ifstream fpi(input);
	if (fpi.fail()) {
		cerr << "can not open input file ( test name, file tail...)" << endl;
		return;
	}

	int temp;
	fpi >> temp;
	if (!temp) {
		cerr << "File error. " << endl;
		return;
	}
	int space_collection = temp; // kích thước không gian
	int i;

	vector< list<int> > table(space_collection); // bảng băm lưu các khóa key từ file dữ liệu
											// mỗi ô trên bảng là một danh sách liên kết

	int number_ele;		// số phần tử của mảng
	fpi >> number_ele;
	if (!number_ele) {
		cerr << "error input data." << endl;
		return;
	}

	//đổ dữ liệu vào bảng
	int index;
	for (i = 0; i < number_ele; i++) {
		fpi >> temp; // đọc một dữ liệu vào biến tạm
		index = HashFunc(temp, space_collection); // chuyển đổi khóa k
		table[index].push_back(temp); // thêm vào ô tại địa chỉ vừa biến đổi
	}

	ofstream fpo(output); // mở file để xuất dữ liệu 
	if (fpo.fail()) {
		cerr << "can not open output file ( test name, file tail...)" << endl;
		return;
	}

	index = HashFunc(key, space_collection); // lấy địa chỉ của khóa cần tìm
	for (i = 0; i < space_collection; i++) {
		if (table[i].empty()) { // nếu DSLK tại ô nhớ i rỗng
			fpo << endl;
			continue;
		}
		list<int>::iterator first = table[i].begin(); // vị trí đầu tiên của DS
		while (first != table[i].end()) {
			fpo << *first << " ";
			first++;
		}
		fpo << endl;
	}
	bool kq = SearchInList(table[index], key);
	if (kq)
		fpo << index;
	else
		fpo << -1 << endl;

	fpi.close();
	fpo.close();

	table.clear();
}
