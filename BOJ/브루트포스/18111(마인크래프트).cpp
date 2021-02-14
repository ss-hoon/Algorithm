#include <iostream>
#include <algorithm>
#define MAX 2147483647
using namespace std;
int N, M, B, minBound = 257, maxBound = -1, map[501][501];

int minecraft(int h) {
	int box = B;
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// h 높이만큼 채우기 위한 차이
			int diff = map[i][j] - h;

			// 음수인 경우(땅을 쌓아야하는 경우)에는 box를 소모하고
			// 1 차이당 1초 증가
			if (diff <= 0) {
				box -= -diff;
				result += -diff;
			}

			// 양수인 경우(땅을 부수는 경우)에는 box를 획득하고
			// 1 차이당 2초 증가
			else {
				box += diff;
				result += 2 * diff;
			}
		}
	}
	if (box < 0)	return MAX;
	else return result;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			minBound = min(minBound, map[i][j]);
			maxBound = max(maxBound, map[i][j]);
		}
	}

	int result[2] = { MAX, MAX };
	// 주어진 값들 중 최소값부터 최대값까지 반복해 최소시간과 그 때의 높이를 구함
	for (int i = minBound; i <= maxBound; i++) {
		int time = minecraft(i);
		if (time <= result[0]) {
			result[0] = time;
			result[1] = i;
		}
	}
	cout << result[0] << " " << result[1] << "\n";
	return 0;
}