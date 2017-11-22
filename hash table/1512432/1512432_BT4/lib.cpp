#include "lib.h"


int hashfunc(string key,int khong_gian) {
	int n = key.length();
	int sum(0);
	for (int i = 0; i < n; i++)
		sum += key[i];
	return sum%khong_gian;
}


void CreatTableDict(string dict, vector<list<string>> &table,int khong_gian) {
	ifstream f_dict(dict);
	if (f_dict.fail()) {
		cerr << "khong mo duoc file tu dien." << endl;
		return;
	}

	string temp;
	while (!f_dict.eof()) {
		f_dict >> temp;
		if (f_dict.eof())
			break;
		int index = hashfunc(temp, khong_gian);
		table[index].push_back(temp);
	}

	f_dict.close();
}
bool FindInList(list<string> a,string key) {
	list<string>::iterator first = a.begin();
	while ( *first != key && first != a.end() ) {
		first++;
	}

	return (*first == key);
}

void FindErrorWord(ifstream &fpi, ofstream &fpo, vector<list<string>> table, int khong_gian) {
	string temp;
	int dem(1);

	while (!fpi.eof()){
		fpi >> temp;
		if (fpi.eof())
			break;
		int index = hashfunc(temp, khong_gian);
		bool kq = FindInList(table[index], temp);
		if (kq == false) {
			fpo << temp << " " << dem << endl;
		}
		dem++;
	}
}