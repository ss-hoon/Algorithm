#include <iostream>
#include <cstring>
#include <algorithm>
#define INF -2147483647
#define ll long long
using namespace std;
int N, M, map[1000][1000], check[1000][1000];
ll cache[1000][1000][3];
int dy[3] = { 0,0,1 };
int dx[3] = { -1,1,0 };

ll search(int y, int x, int dir) {
	ll &ret = cache[y][x][dir];
	if (y == N - 1 && x == M - 1)	return ret = map[y][x];

	if (ret != INF)	return ret;

	check[y][x] = 1;
	ll temp = INF;

	// 왼쪽 오른쪽 아래 순으로 탐색
	// 기존의 2차원 cache는 재방문을 인지할 수 없음
	// -> 기존의 2차원 cache에 방향을 추가한 3차원 cache 사용
	for (int i = 0; i < 3; i++) {
		int Y = y + dy[i];
		int X = x + dx[i];

		if (check[Y][X] == 1 || Y < 0 || Y >= N || X < 0 || X >= M)	continue;
		temp = max(temp, search(Y, X, i));
	}

	check[y][x] = 0;
	return ret = temp + map[y][x];
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			cache[i][j][0] = cache[i][j][1] = cache[i][j][2] = INF;
		}
	}

	cout << search(0, 0, 0) << "\n";
	return 0;
}