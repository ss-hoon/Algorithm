#include <iostream>
using namespace std;
long long cache[101][101] = { 1 };


int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N, tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp == 0)	continue;

			if (i + tmp < N)	cache[i + tmp][j] += cache[i][j];
			if (j + tmp < N)	cache[i][j + tmp] += cache[i][j];
		}
	}
	cout << cache[N - 1][N - 1] << "\n";
	return 0;
}