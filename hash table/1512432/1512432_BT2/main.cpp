#pragma once
#include "lib.h"

void main(int isothamso, char* cmangthamso[]) {
	srand(time(NULL));

	if (isothamso != 4) { // số tham số đầu vào không đúng với yểu cầu 
		cout << "Nhap khong dung dinh dang. " << endl;
		return;
	}

	int ithuattoan = atoi(cmangthamso[1]); // lấy thuật toán số mấy theo yêu cầu
	if (ithuattoan < 1 || ithuattoan > 3) { // nếu ngoài 3 thuật toán đã viết
		cout << "khong co thuat toan tuong ung." << endl;
		return;
	}

	long i_kich_thuoc_mang = atoi(cmangthamso[2]); // kích thước mảng mới

	if (!i_kich_thuoc_mang) { //nhập sai dữ liệu
		cout << "Nhap sai dinh dang kich thuoc mang." << endl;
		return;
	}

	string output = cmangthamso[3]; // tên file output

	ofstream fpo(output); //mở file output để ghi kết quả tìm được
	if (fpo.fail()) {
		cout << "Khong mo duoc file. Xin kiem tra lai." << endl;
		return;
	}

	int *a = new int[i_kich_thuoc_mang + 1]; //tạo mảng với kích thước đưa vào

	int i = 0;
	for (; i < i_kich_thuoc_mang; i++)
		a[i] = rand(); // tạo random các phần tử của mảng

	int x = rand(); //random phần tử cẩn tìm

	cout << setiosflags(ios::showpoint) << setprecision(3); // hàm định giá trị làm tròn trong thư viện iomanip

	switch (ithuattoan) {
	case 1: {
		clock_t start = clock();
		TimKiemTuanTu(a, i_kich_thuoc_mang, x); //gọi thuật toán tìm kiếm tuần tự
		clock_t end = clock();
		fpo << " thoi gian chay thuat toan tim kiem tuan tu voi mang " << i_kich_thuoc_mang
			<< " phan tu la: " << (float)end - (float)start << "mili giay." << endl;
		break;
	}
	case 2: {
		clock_t start = clock();
		TKTTCoLinhCanh(a, i_kich_thuoc_mang, x); //gọi thuật toán tìm kiếm tuần tự có lính canh
		clock_t end = clock();
		fpo << " thoi gian chay thuat toan tim kiem tuan tu co linh canh voi mang " << i_kich_thuoc_mang
			<< " phan tu la: " << (float)end - (float)start << "mili giay." << endl;
		break;
	}
	case 3: {
		a[0] = rand();
		i = 1;
		for (; i < i_kich_thuoc_mang; i++) {
			a[i] = a[i - 1] + (rand() % 100);
		}
		x = rand();
		clock_t start = clock();
		TimKiemNhiPhan(a, i_kich_thuoc_mang, x); // gọi thuật toán tìm kiếm nhị phân
		clock_t end = clock();
		fpo << " thoi gian chay thuat toan tim kiem nhi phan voi mang " << i_kich_thuoc_mang
			<< " phan tu la: " << (float)end - start << "mili giay." << endl;
		break;

	}
	default:
		break;
	}

	delete[]a;
}



