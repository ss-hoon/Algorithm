#include <iostream>
#include <stdlib.h>
using namespace std;
int n, result = 0;
int col[16] = {};
bool check(int x) {
	for (int i = 1; i < x; i++) {
		if (col[x] == col[i] || abs(col[x] - col[i]) == x - i)	return false;
	}
	return true;
}
void Queen(int x) {
	if (x == n + 1)	result++;
	else {
		for (int i = 1; i <= n; i++) {
			col[x] = i;
			if (check(x))	Queen(x + 1);
		}
	}
}
int main() {
	cin >> n;
	Queen(1);
	printf("%d\n", result);
}