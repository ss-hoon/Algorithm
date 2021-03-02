#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N, K, R, dstY, dstX, result;
bool visit[101][101], isRoad[101][101][4];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
vector< pair<int, int> > cow;

bool dfs(int y, int x) {
	if (y == dstY && x == dstX)	return true;
	visit[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int Y = y + dy[i];
		int X = x + dx[i];

		if (Y < 1 || Y > N || X < 1 || X > N)	continue;
		if (visit[Y][X])	continue;
		if (isRoad[y][x][i])	continue;

		if (dfs(Y, X))	return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> K >> R;

	while (R--) {
		int r1, r2, c1, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		// 길의 시작점에서 끝점의 방향 체크
		for (int i = 0; i < 4; i++) {
			if (r1 + dy[i] == r2 && c1 + dx[i] == c2) {
				isRoad[r1][c1][i] = true;

				if (i < 2)	isRoad[r2][c2][i + 2] = true;
				else isRoad[r2][c2][i - 2] = true;
				break;
			}
		}
	}

	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		cow.push_back({ r, c });
	}

	for (int i = 0; i < K - 1; i++) {
		for (int j = i + 1; j < K; j++) {
			memset(visit, 0, sizeof(visit));
			dstY = cow[j].first;	dstX = cow[j].second;

			// dfs 결과 false로 반환된 것을 카운팅
			if (!dfs(cow[i].first, cow[i].second))	result++;
		}
	}
	cout << result << "\n";
	return 0;
}