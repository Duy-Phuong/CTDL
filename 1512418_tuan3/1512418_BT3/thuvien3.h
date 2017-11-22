#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <time.h>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

////xử lí bằng phương pháp nối kết

int hamBam1(const int k, const int M); 
bool timKiem(list<int> k, int key); 
void DuyetDS(ofstream& f, list<int> l);
void ChainingMethod(string input, string output, int key);

//xu li bang phuong phap noi ket
static int N;

void Init(int *&table, int M);
bool Full(int M);
int FindTableLinear(int* table, int M, int key);
void InsertTableLinear(int* &table, int M, int key);
void LinearProbe(string input, string output, int key);
