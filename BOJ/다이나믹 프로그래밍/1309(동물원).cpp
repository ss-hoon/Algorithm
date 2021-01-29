#include <iostream>
using namespace std;
int cache[3][100001] = {};

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N;
	cin >> N;

	cache[0][1] = cache[1][1] = cache[2][1] = 1;
	for (int j = 2; j <= N; j++) {
		for (int i = 0; i < 3; i++) {
			if (i == 0)	cache[i][j] = (cache[0][j - 1] + cache[1][j - 1] + cache[2][j - 1]) % 9901;
			else if (i == 1)	cache[i][j] = (cache[0][j - 1] + cache[2][j - 1]) % 9901;
			else cache[i][j] = (cache[0][j - 1] + cache[1][j - 1]) % 9901;
		}
	}

	cout << (cache[0][N] + cache[1][N] + cache[2][N]) % 9901 << "\n";
	return 0;
}