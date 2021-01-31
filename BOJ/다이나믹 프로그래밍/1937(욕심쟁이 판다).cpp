#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int map[501][501], cache[501][501], N, result = 0;

// 상 하 좌 우 x, y 좌표
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };

int live(int y, int x) {
	if (cache[y][x] != -1)	return cache[y][x];
	bool ok = false;

	for (int i = 0; i < 4; i++) {
		int Y = y + dy[i];
		int X = x + dx[i];

		if (Y < 0 || Y >= N || X < 0 || X >= N)	continue; // 배열 범위 벗어나면 continue
		if (map[Y][X] <= map[y][x])	continue; // 다음 위치 대나무 개수가 현재보다 같거나 적을 경우 continue

		cache[y][x] = max(cache[y][x], live(Y, X) + 1);
		ok = true;
	}
	if (!ok)	return cache[y][x] = 1; // 상 하 좌 우 모두 현재 대나무 개수보다 같거나 적을 경우
	else return cache[y][x];
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)	cin >> map[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)	result = max(result, live(i, j));
	}
	cout << result << "\n";
	return 0;
}