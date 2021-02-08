#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int cache[501][501];
int pSum[501];
int T, K;

int combine(int start, int end) {
	if (start == end)	return 0;

	int &ret = cache[start][end];
	if (ret != -1)	return ret;

	// (1 - 4)의 파일을 합칠 때
	// (1 - 1), (2 - 4) || (1 - 2), (3 - 4) || (1 - 3), (4 - 4)
	// 경우를 구해서 최소값을 cache에 메모이제이션하고
	// 마지막으로 (1 - 4)의 파일 총 비용을 더해야함
	for (int i = start; i < end; i++) {
		int result = combine(start, i) + combine(i + 1, end);
		if (ret == -1 || ret > result)	ret = result;
	}

	ret += pSum[end] - pSum[start - 1];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> K;
		memset(cache, -1, sizeof(cache));
		memset(pSum, 0, sizeof(pSum));
		for (int i = 1; i <= K; i++) {
			int temp;
			cin >> temp;
			pSum[i] = pSum[i - 1] + temp;
		}

		cout << combine(1, K) << "\n";
	}
	return 0;
}