/*
CÁC BÀI TOÁN TÌM KIẾM BẰNG HÀM BĂM VÀ CÁC PHƯƠNG THỨC XỬ LÝ ĐỤNG ĐỘ TƯƠNG ỨNG
MSSV 1512432
Họ tên: Nguyễn Đăng Quang
Lớp TH CTDL&GT Chiều Thứ 4*/

#pragma once
#include "ChainingMethod.h"
#include "LinearProbe.h"
#include "DoubleHashingMethod.h"
#include "QuadraticPropingMethod.h"

//int N;

void main(int i_so_tham_so, char *c_mang_tham_so[]) {
	if (i_so_tham_so != 5) {
		cerr << "Cau lenh khong dung dinh dang. Xin kiem tra lai." << endl;
		return;
	}

	int thuat_toan = atoi(c_mang_tham_so[1]);
	if (thuat_toan < 1 || thuat_toan >4) {
		cerr << "khong co thuat toan yeu cau. Xin kiem tra lai." << endl;
		return;
	}
	int key = atoi(c_mang_tham_so[2]);

	if (!key) {
		cerr << "Sai du lieu. Du lieu input la mang so nguyen" << endl;
		return;
	}
	string input = c_mang_tham_so[3]; // tên file input
	string output = c_mang_tham_so[4]; // tên file output

	switch (thuat_toan)
	{
	case 1: { 
		ChainingMethod(input, output, key);
		break;
	}
	case 2: {
		LinearProbe(input,output, key);
		break;
	}
	case 3: {
		QuadraticPropingMethod(input, output, key);
		break;
	}
	case 4: {
		DoubleHashingMethod(input, output, key);
		break;
	}
	default:
		break;
	}

	return;
}