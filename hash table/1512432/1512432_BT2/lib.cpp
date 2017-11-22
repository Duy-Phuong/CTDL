#include "lib.h"


/*Thuật toán tìm kiếm tuần tự, duyệt hết file và xuất vị trí tìm được (tính từ 0) ra màn hình
đầu vào: mảng chứa dữ liệu, số phần tử mảng, phần tử cần tìm
đầu ra: vị trí biến cần tìm, nếu không tìm được trả về -1*/
void TimKiemTuanTu(int *a, int n, int x) {

	int dem(-1);
	int i = 0;
	for (; i < n; i++) {
		if (a[i] == x) {
			cout << i << " ";
			dem++;
		}
	}
	if (dem == -1)
		cout << dem << endl;
}

/*Thuật toán tìm kiếm tuần tự có lính canh,cho vị trí = n, nếu tìm được thì gán vị trí bằng vị trí tìm được
đầu vào: 2 con trỏ đến file input và output, biến dữ liệu cần tìm
đầu ra: vị trí biến cần tìm, nếu không tìm được trả về -1
*/
void TKTTCoLinhCanh(int *a, int n, int x) {

	a[n] = x;
	int dem = 0;
	int i = 0;
	for (; ; i++) {
		if (a[i] == x) {
			if (i == n)
				break;
			cout << i << " ";
			dem++;
		}
	}
	if (dem == 0) //vị trí vẫn như lúc khởi tạo tức là không tìm thấy
		cout << -1 << endl;
}

/* Thuật toán tìm kiếm nhị phân.
YÊU CẦU: mảng phải được sắp xếp tăng dần.
Đầu vào + Đầu ra: như 2 thuật toán trên*/
void TimKiemNhiPhan(int *a, int n, int x) {
	
	int left = 0;
	int right = n - 1;
	int mid(0);
	int temp = -1;

	while (left <= right) {
		mid = (left + right) / 2;

		if (a[mid] < x) {
			left = mid +1;
		}
		else if (a[mid] > x) {
			right = mid - 1;
		}
		else {
			if (mid != temp)
				cout << mid << " ";
			left++;
			temp = mid;
		}
	}

	if (temp == -1)
		cout << -1;
}