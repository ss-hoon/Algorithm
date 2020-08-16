#include <iostream>
#include <algorithm>
using namespace std;
int cache[1001][1001], cash[1001];
int main() {
	int test;
	cin >> test;
	for (int i = 1; i <= test; i++)	cin >> cash[i];
	for (int i = 1; i <= test; i++) {
		for (int j = 1; j <= test; j++) {
			if (i > j)	cache[i][j] = cache[i - 1][j];
			else cache[i][j] = max(cache[i - 1][j], cache[i][j - i] + cash[i]);
		}
	}
	cout << cache[test][test] << "\n";
	return 0;
}