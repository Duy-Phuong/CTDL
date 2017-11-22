#pragma once
#include "LinearProbe.h"

// hàm băm 2 trong phép băm kép
int HashFunc2(int key, int M); 
// tìm kiếm bằng phương pháp băm kép
int FindDoubleTable(int* table, int M, int key); 
//chèn phần tử bằng phương pháp băm kép
void InsertHashDouble(int* &table, int M, int key);
// Phương pháp xử lý đụng độ bằng băm kép
void DoubleHashingMethod(string input, string output, int key); 