#pragma once
#include "ChainingMethod.h"

static int N;

// khởi tạo bảng băm
void Init(int *&table, int M); 
// kiểm tra bảng đầy
bool Full(int M);
// tìm khóa trên bảng bằng phương pháp dò tuyến tính
int FindTableLinear(int* table, int M, int key); 
// chèn vào bảng bằng pp dò tuyến tính
void InsertTableLinear(int* &table, int M, int key); 
// phương pháp xử lý đụng độ bằng dò tuyến tính
void LinearProbe(string input,string output, int key);