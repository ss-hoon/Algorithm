#include <iostream>
#include <algorithm>
#define MAX 16000001
using namespace std;
int N, map[16][16];

// 시작점, 방문 정점
int cache[16][(1 << 16)];

int TSP(int visit, int start) {

	// 모두 순회했을 경우
	if (visit == ((1 << N) - 1)) {
		if (map[start][0] == 0)	return MAX;
		return map[start][0];
	}

	// 방문 체크
	visit |= (1 << start);

	int &ret = cache[start][visit];
	if (ret != 0)	return ret;

	ret = MAX;
	for (int i = 0; i < N; i++) {
		if (visit & (1 << i) || map[start][i] == 0)	continue;

		ret = min(ret, TSP(visit | (1 << i), i) + map[start][i]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)	cin >> map[i][j];
	}

	cout << TSP(0, 0) << "\n";
	return 0;
}