#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int N, M, board[100][100], visit[100][100], cnt, time, beforeCheese;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
queue< pair<int, int> > q;
vector< pair<int, int> > cheese;

// 겉부분의 빈 공간부터 BFS를 해서
// 겉부분에 맞닿아있는 치즈를 녹인다
bool bfs() {
	memset(visit, 0, sizeof(visit));
	q.push({ 0, 0 });
	visit[0][0] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int k = 0; k < 4; ++k) {
			int Y = y + dy[k];
			int X = x + dx[k];

			if (Y < 0 || Y >= N || X < 0 || X >= M)	continue;
			if (visit[Y][X])	continue;

			visit[Y][X] = 1;
			if (board[Y][X] == 1) {
				cheese.push_back({ Y, X });
				cnt++;
			}
			else q.push({ Y, X });
		}
	}

	beforeCheese = cheese.size();
	if (cnt == N * M)	return false;

	for (auto it : cheese) {
		int y = it.first;
		int x = it.second;

		board[y][x] = 0;
	}
	cheese.clear();
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 0)	cnt++;
		}
	}

	// 치즈가 모두 녹을 때까지 진행
	while (1) {
		time++;
		if (!bfs()) {
			cout << time << "\n" << beforeCheese << "\n";
			break;
		}
	}
	return 0;
}