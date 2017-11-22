#include "lib.h"

/*Thuật toán tìm kiếm tuần tự, duyệt hết file và xuất vị trí tìm được (tính từ 0) ra file ouput
đầu vào: 2 con trỏ đến file input và output, biến dữ liệu cần tìm
đầu ra: vị trí biến cần tìm, nếu không tìm được trả về -1*/
void TimKiemTuanTu(ifstream &fpi, ofstream &fpo, int x) {

	int n; // số phần tử trong trong file input
	fpi >> n; //lấy số phần tử từ file input qua con trỏ fpi
	if (!n) { //sai định dạng
		cout << "Error file.." << endl;
		return;
	}

	int temp;
	int dem(0);

	while (!fpi.eof()) {
		fpi >> temp; //đọc vào biến temp
		if (fpi.fail()) //đọc đến ký tự eof
			break;
		if (temp == x) { //tìm được
			fpo << dem << " "; //xuất vị trí
		}
		dem++;
	}

	if ((int)fpo.tellp() == 0) // nếu file ghi rỗng tức là không tìm được x
		fpo << -1;
}

/*Thuật toán tìm kiếm tuần tự có lính canh,cho vị trí = -1, nếu tìm được thì gán vị trí bằng vị trí tìm được
đầu vào: 2 con trỏ đến file input và output, biến dữ liệu cần tìm
đầu ra: vị trí biến cần tìm, nếu không tìm được trả về -1
*/
void TKTTCoLinhCanh(ifstream &fpi, ofstream &fpo, int x) {

	int n;
	fpi >> n;
	if (!n) {
		cout << "Error file.." << endl;
		return;
	}

	int vitri(-1); // lính

	int temp;
	int dem(0);
	while (!fpi.eof()) {
		fpi >> temp;
		if (fpi.fail())
			break;
		if (temp == x) {
			fpo << dem << " ";
			vitri = dem; //thay đổi vị trí
		}
		dem++;
	}
	if (vitri == -1) //vị trí vẫn = -1 tức là không tìm thấy
		fpo << -1;
}

/* Thuật toán tìm kiếm nhị phân. 
YÊU CẦU: mảng phải được sắp xếp tăng dần.
Đầu vào + Đầu ra: như 2 thuật toán trên*/
void TimKiemNhiPhan(ifstream &fpi, ofstream &fpo, int x) {
	int n; // số phần tử từ file input
	fpi >> n; // đọc vào số phần tử từ file input qua con trỏ fpi
	if (!n) { //
		cout << "Error file.." << endl;
		return;
	}

	int *a = new int[n]; //tạo mảng để đọc dữ liệu vào chương trình
	int i, temp;

	fpi >> a[0];
	temp = a[0];

	for (i = 1; i < n; i++) {
		fpi >> a[i];
		if (a[i] <= temp) { // nếu đây không phải mảng tăng dần
			cout << "Du lieu dua vao khong dung. Mang phai duoc sap xep tang dan. " << endl;
			delete[]a; //xóa vùng nhớ
			return; //thoát
		}
		temp = a[i];
	}

	int left = 0;
	int right = n - 1;
	int mid(0);
	temp = -1;

	while (left <= right) {
		mid = (left + right) / 2;

		if (a[mid] < x) {
			left = mid+1;
		}
		else if (a[mid] > x) {
			right = mid -1;
		}
		else {
			if (mid != temp)
				fpo << mid << " ";
			left++;
			temp = mid;
		}
	}

	if (temp == -1)
		fpo << -1;

	delete[]a;
}