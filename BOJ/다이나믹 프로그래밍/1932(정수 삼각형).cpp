#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int test;
int cache[500][500], triangle[500][500];
int answer(int x, int y) {
	if (x == test - 1)	return cache[x][y] = triangle[x][y];
	if (cache[x][y] != -1)	return cache[x][y];
	return cache[x][y] = max(answer(x + 1, y), answer(x + 1, y + 1)) + triangle[x][y];
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> test;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < test; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}
	cout << answer(0, 0) << "\n";
	return 0;
}