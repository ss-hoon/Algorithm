#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cache[4][10001]; // i의 0번째는 OO, i의 1번째는 OX, i의 2번째는 XO, i의 3번째는 XX
vector <int> wine;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int test;
	cin >> test;
	wine.resize(test);
	for (int j = 1; j <= test; j++) {
		cin >> wine[j - 1];
		for (int i = 0; i < 4; i++) {
			if (i == 0)	cache[0][j] = cache[2][j - 1] + wine[j - 1];
			else if (i == 1)	cache[1][j] = max(cache[0][j - 1], cache[2][j - 1]);
			else if (i == 2) cache[2][j] = max(cache[1][j - 1], cache[3][j - 1]) + wine[j - 1];
			else cache[3][j] = max(cache[1][j - 1], cache[3][j - 1]);
		}
	}
	cout << max(max(cache[0][test], cache[1][test]), max(cache[2][test], cache[3][test])) << "\n";
	return 0;
}