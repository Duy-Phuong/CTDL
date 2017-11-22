#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#define SPACE_COLLECTION 1000

using namespace std;


int hashfunc(string key, int khong_gian);
void CreatTableDict(string dict, vector<list<string>> &table, int khong_gian);

bool FindInList(list<string> a, string key);
void FindErrorWord(ifstream &fpi, ofstream &fpo, vector<list<string>> table, int khong_gian);