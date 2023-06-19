#include<iostream>

using namespace std;

const int C = 53, N = 8, Max = 32;
extern int table[100][1000] = { 0 };
int Larger(int a, int b){
	if (a > b)	return a;
	else return b;
}

int check(int a, int b) {
	int c = a - b;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= Max; j++) {
			if (c == table[i][j])return 1;
		}
	}
	return 0;
}

int main() {

	int W[10] = {};


	for (int i = 1; i <= N; i++) {
		cin >> W[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <=C; j++) {
			if (j < W[i])table[i][j] = table[i - 1][j];
			else table[i][j] = Larger(table[i - 1][j - W[i]] + W[i], table[i - 1][j]);
		}
	}

	cout << endl << endl;
	int times = 0;
	for (int i = 0; i <= N; i++) {
		if (table[i][C] == C) {
			times++;
		}
	}

	for (int i = 0; i < times; i++) {
		int count[N + 1] = {}; int temp = C;
		for (int j = 1; j <= N; j++) {
			if (check(temp, W[j]==1)){
				count[j] = 1;
				temp = temp - W[j];
			}
		}
		for (int j = 1; j <= N; j++)cout << count[j] << ' ';
		cout << endl;
	}
	return 0;
}
