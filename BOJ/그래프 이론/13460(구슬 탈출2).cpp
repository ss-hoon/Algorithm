#include <iostream>
#include <queue>
using namespace std;
struct location {
	int By, Bx, Ry, Rx, dist;
};

queue<location> que;
int N, M, holeY, holeX, num;
char map[10][10];
bool visit[10][10][10][10] = { false };
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };

int game() {
	while (!que.empty()) {
		int by = que.front().By;		int bx = que.front().Bx;
		int ry = que.front().Ry;		int rx = que.front().Rx;
		int dist = que.front().dist;
		que.pop();

		// 이미 방문한 정점은 다시 탐색할 필요 없음
		if (visit[by][bx][ry][rx])	continue;
		visit[by][bx][ry][rx] = true;

		if (dist == 10) break;

		// 상하좌우 방향으로 BFS 탐색
		for (int i = 0; i < 4; i++) {
			int distB = 0;
			int distR = 0;
			int BY = by;	int BX = bx;
			int RY = ry;	int RX = rx;

			// 벽에 닿을 때까지 이동
			while (map[BY + dy[i]][BX + dx[i]] != '#') {
				BY += dy[i];
				BX += dx[i];
				distB++;
				if (map[BY][BX] == 'O')	break;
			}

			// 벽에 닿을 때까지 이동
			while (map[RY + dy[i]][RX + dx[i]] != '#') {
				RY += dy[i];
				RX += dx[i];
				distR++;
				if (map[RY][RX] == 'O')	break;
			}

			// 파란 공이 구멍에 빠지면 백트래킹
			if (map[BY][BX] == 'O')	continue;
			// 빨간 공이 구멍에 빠지면 최소 횟수로 구멍에 빠진 것이므로 return
			// reason) BFS이기 때문
			if (map[RY][RX] == 'O')	return dist + 1;

			if (BY == RY && BX == RX) {
				if (distR < distB) {
					BY -= dy[i];
					BX -= dx[i];
				}
				else {
					RY -= dy[i];
					RX -= dx[i];
				}
			}

			que.push({ BY, BX, RY, RX, dist + 1 });
		}

	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	location init;
	init.dist = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'O') {
				holeY = i;
				holeX = j;
			}
			else if (map[i][j] == 'B') {
				init.By = i;
				init.Bx = j;
			}
			else if (map[i][j] == 'R') {
				init.Ry = i;
				init.Rx = j;
			}
		}
	}

	que.push(init);
	num = game();
	if (num == -1)	cout << "-1\n";
	else cout << num << "\n";
	return 0;
}