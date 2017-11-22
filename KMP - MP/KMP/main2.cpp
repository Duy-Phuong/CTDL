#include <iostream>
using namespace std;
#include <string>

int MP(string source, string T)
{
	int i = 0, j = -1;

	int n = source.length();
	int m = T.length();
	int* next = new int[m];
	next[0] = -1;
	do {
		if (j == -1 || T[i] == T[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	} while (i < m - 1);

	for (int i = 0; i < m; i++)
	{
		cout << next[i] << "  ";
	}

	i = j = 0;
	do {
		if (j == -1 || source[i] == T[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	} while (j < m && i < n);
	if (j >= m)
		return i - m;
	else
		return -1;
}

void preKMPnew(char* x, int m, int mpNext[]) {
	int i, j;
	i = 0;
	j = mpNext[0] = -1;
	do {
		if (j == -1 || x[i] == x[j]) {
			i++;
			j++;
			if (x[i] == x[j]) {
				mpNext[i] = mpNext[j];
			}
			else {
				mpNext[i] = j;
			}
		}
		else {
			j = mpNext[j];
		}
	} while (i < m - 1);
}

void preKmp(char *x, int m, int kmpNext[]) {
	int i, j;

	i = 0;
	j = kmpNext[0] = -1;
	while (i < m) {
		while (j > -1 && x[i] != x[j])
			j = kmpNext[j];
		i++;
		j++;
		if (x[i] == x[j])
			kmpNext[i] = kmpNext[j];
		else
			kmpNext[i] = j;
	}
}

int main()
{

	char* s = "abacab";
	//MP("01010101", s);
	int n = 7;
	int next[100];
	preKMPnew(s, n, next);
	for (int i = 0; i < n; i++)
	{
		cout << next[i] << "  ";
	}


	return 0;
}