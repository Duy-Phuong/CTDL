#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <ctime>

void selectionSort(int a[], int n);
void insertionSort(int a[], int n);
void taoFileRandom(char* s, int x);
void docFile(char* s, int a[], int &n);

void shift(int a[], int l, int r);
void CreateHeap(int a[], int n);
void HeapSort(int a[], int n);
void quickSort(int a[], int l, int r);

void ghiFile(int dem, char* s, int b1);


void docFile(int x, string s1, string s2);