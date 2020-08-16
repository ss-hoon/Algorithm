#include <iostream>
#include <algorithm>
using namespace std;
int cache[3][1000], color[3][1000];
int main() {
	int test;
	cin >> test;
	for (int j = 0; j < test; j++) {
		for (int i = 0; i < 3; i++) {
			cin >> color[i][j];
			if (j == 0)	cache[i][j] = color[i][j];
			else {
				if (i == 0)	cache[0][j] = min(cache[1][j - 1], cache[2][j - 1]) + color[i][j];
				else if (i == 1)	cache[1][j] = min(cache[0][j - 1], cache[2][j - 1]) + color[i][j];
				else cache[2][j] = min(cache[0][j - 1], cache[1][j - 1]) + color[i][j];
			}
		}
	}
	cout << min(cache[0][test - 1], min(cache[1][test - 1], cache[2][test - 1])) << "\n";
	return 0;
}