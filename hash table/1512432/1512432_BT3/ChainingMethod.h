#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include <list>
#include <vector>
#include <math.h>

using namespace std;
// hàm băm
int HashFunc(const int k, const int M); 
// tìm kiếm trong DSLK,mỗi DSLK là một ô nhớ trong bảng băm
bool SearchInList(list<int> k, int key); 
// duyệt DSLK
void TravelList(ofstream& fpo, list<int> l);
// phương pháp nối kết
void ChainingMethod(string input, string output, int key); 