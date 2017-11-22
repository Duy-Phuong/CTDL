#pragma once
#include "LinearProbe.h"

//tìm kiếm trên bảng bằng pp dò bậc 2
int FindTableQuadratic(int* table, int M, int key); 
//chèn vào bảng bằng pp dò bậc 2
void InsertHashTableQuadratic(int* &table, int M, int key); 
// pp xử lý đụng độ bằng dò bậc 2
void QuadraticPropingMethod(string input, string output, int key); 