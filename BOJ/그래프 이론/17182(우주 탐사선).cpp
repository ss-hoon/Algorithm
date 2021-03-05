#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100001
using namespace std;
int N, K, map[10][10], cache[10][(1 << 10)];

// TSP Problem - Dynamic Programming + Bitmask
int TSP(int visit, int start) {
	if (visit == ((1 << N) - 1))	return 0;

	visit |= (1 << start);

	int &ret = cache[start][visit];
	if (ret != -1)	return ret;

	ret = MAX;
	for (int i = 0; i < N; i++) {
		if (visit & (1 << i))	continue;

		ret = min(ret, TSP(visit | (1 << i), i) + map[start][i]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)	cin >> map[i][j];
	}

	// Floyd-Warshall Algorithm
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == k)	continue;

				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	memset(cache, -1, sizeof(cache));
	cout << TSP(0, K) << "\n";
	return 0;
}