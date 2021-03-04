#include <iostream>
#include <deque>
#define INF 10001
using namespace std;
int N, M, dist[100][100];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
char map[101][101];
deque< pair<int, int> > dq;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			dist[i][j] = INF;
		}
	}

	dist[0][0] = 0;
	dq.push_back({ 0,0 });
	while (!dq.empty()) {
		int y = dq.front().first;
		int x = dq.front().second;
		dq.pop_front();

		if (y == N - 1 && x == M - 1) {
			cout << dist[y][x] << "\n";
			break;
		}

		for (int i = 0; i < 4; i++) {
			int Y = y + dy[i];
			int X = x + dx[i];
			if (Y < 0 || Y >= N || X < 0 || X >= M)	continue;
			if (dist[y][x] + (map[Y][X] - '0') >= dist[Y][X])	continue;

			dist[Y][X] = dist[y][x] + (map[Y][X] - '0');

			// 0이면 deque의 앞부분에 push
			// 1이면 deque의 뒷부분에 push
			// -> 가중치 정렬
			if ((map[Y][X] - '0') == 0)	dq.push_front({ Y, X });
			else dq.push_back({ Y, X });
		}
	}
	return 0;
}