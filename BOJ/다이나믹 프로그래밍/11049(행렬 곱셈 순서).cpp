#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, matrix[501][2], cache[501][501];

int minOper(int y, int x) {
	if (y == x)	return 0;
	if (cache[y][x] != -1)	return cache[y][x];

	cache[y][x] = 987654321;
	// A * B * C 행렬 곱셈은
	// A * (B * C)와 (A * B) * C의 경우로 나뉘며
	// 둘 중 최소값을 cache에 메모이제이션한다
	for (int i = y; i < x; i++) {
		int sum = minOper(y, i) + minOper(i + 1, x);
		sum += matrix[y][0] * matrix[i][1] * matrix[x][1];
		cache[y][x] = min(cache[y][x], sum);
	}
	return cache[y][x];
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < N; i++) {
		cin >> matrix[i][0] >> matrix[i][1];
	}

	cout << minOper(0, N - 1) << "\n";
	return 0;
}