/*Họ tên sinh viên: Nguyễn Đăng Quang
MSSV: 1512432
Thực hành tuần 3: lập trình bằng dòng lệnh Command line
MÔ TẢ BÀI TẬP:
Bài Tập 1: Viết các thuật toán tìm kiếm và xuất vị trí tìm được ra file output.
*/


#pragma once
#include "lib.h"

void main(int iSoThamSo, char* cMangThamSo[]) {
	//nếu câu lệnh đưa vào command line không phải là dạng yêu cầu của BT1
	if (iSoThamSo !=5) {
		cout << "Nhap sai quy dinh. " << endl;
		return; //thoát
	}

	int ithuattoan = atoi(cMangThamSo[1]); // lấy thuật toán số mấy theo yêu cầu
	if (ithuattoan < 1 || ithuattoan > 3) { // nếu ngoài 3 thuật toán đã viết
		cout << "khong co thuat toan tuong ung." << endl;
		return;
	}

	int x = atoi(cMangThamSo[2]); // dữ liệu cần tìm

	if (!x) { // không đọc được định dạng của dữ liệu, dữ liệu sai.
		cout << "Nhap sai dinh dang cua x." << endl;
		return;
	}

	string input = cMangThamSo[3]; //tên file input
	string output = cMangThamSo[4]; // tên file output

	ifstream fpi(input); // mở file input để đọc dữ liệu
	if (fpi.fail()) {
		cerr << "khong mo duoc file." << endl;
		return;
	}

	ofstream fpo(output); //mở file output để ghi kết quả tìm được
	if (fpo.fail()) {
		cout << "Khong mo duoc file. Xin kiem tra lai." << endl;
		return;
	}

	switch (ithuattoan) {
	case 1: {
		TimKiemTuanTu(fpi, fpo, x); //gọi thuật toán tìm kiếm tuần tự
		break;
	}
	case 2: {
		TKTTCoLinhCanh(fpi, fpo, x); //gọi thuật toán tìm kiếm tuần tự có lính canh
		break;
	}
	case 3: {
		TimKiemNhiPhan(fpi, fpo, x); // gọi thuật toán tìm kiếm nhị phân
		break;

	}
	default:
		break;
	}

}