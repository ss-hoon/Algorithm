#include <iostream>
#include <vector>
using namespace std;

int N, M, x, y, direction, cnt = 0;
int dx[4] = { 0,1,0,-1 }; // 남-동-북-서
int dy[4] = { 1,0,-1,0 }; // 남-동-북-서

void cleanRobot(int y, int x, int direction, int check, vector<vector<int> > &board) {
	if (x < 0 || y < 0 || y >= N || x >= M)	return;
	if (check == 4) {
		int index = "0321"[direction] - 48;
		if (board[y + dy[index]][x + dx[index]] == 1 || y + dy[index] < 0 || x + dx[index] < 0 || y + dy[index] >= N || x + dx[index] >= M)	return;
		else cleanRobot(y + dy[index], x + dx[index], direction, 0, board);
	}
	else {
		if (board[y][x] == 0) {
			board[y][x] = 2;
			cnt++;
		}

		int index = 3 - direction;
		direction = (direction - 1 == -1 ? 3 : direction - 1);
		if (board[y + dy[index]][x + dx[index]]) { // 1 or 2
			cleanRobot(y, x, direction, check + 1, board);
		}
		else cleanRobot(y + dy[index], x + dx[index], direction, 0, board);
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M >> y >> x >> direction;
	vector<vector<int> > board(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)	cin >> board[i][j];
	}
	cleanRobot(y, x, direction, 0, board);
	cout << cnt << "\n";
	return 0;
}