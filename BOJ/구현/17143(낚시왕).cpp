#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;
struct shark {
	int id, y, x, speed, dir, size;
	bool state;
};

int R, C, M, fisherX, sum;
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, 1, -1 };
vector<int> board[MAX][MAX];
vector<shark> sharkList;

bool compare(int a, int b) {
	return sharkList[a].size > sharkList[b].size;
}

// 범위 밖이면 true, 범위 안이면 false
bool outOfRange(int y, int x) {
	if (y < 1 || y > R || x < 1 || x > C)	return true;
	return false;
}

// 낚시
void fishing() {
	for (int i = 1; i <= R; i++) {
		if (board[i][fisherX].empty())	continue;

		sum += sharkList[board[i][fisherX][0]].size;
		sharkList[board[i][fisherX][0]].state = false;
		board[i][fisherX].clear();
		break;
	}
}

// 상어 이동
void moveShark() {
	for (int i = 0; i < sharkList.size(); i++) {
		if (sharkList[i].state == false)	continue;
		int y = sharkList[i].y;
		int x = sharkList[i].x;

		board[y][x].clear();
	}

	for (int i = 0; i < sharkList.size(); i++) {
		if (sharkList[i].state == false)	continue;

		int id = sharkList[i].id;
		int dir = sharkList[i].dir;
		int speed = sharkList[i].speed;
		int y = sharkList[i].y + dy[dir] * speed;
		int x = sharkList[i].x + dx[dir] * speed;

		while (outOfRange(y, x)) {
			if (y < 1) {
				dir = 2;
				y = 2 - y;
			}
			else if (y > R) {
				dir = 1;
				y = 2 * R - y;
			}
			else if (x < 1) {
				dir = 3;
				x = 2 - x;
			}
			else {
				dir = 4;
				x = 2 * C - x;
			}
		}

		board[y][x].push_back(id);
		sharkList[id].y = y;
		sharkList[id].x = x;
		sharkList[id].dir = dir;
	}
}

// 같은 위치에 있는 상어 처리
void killShark() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (board[i][j].empty())	continue;

			sort(board[i][j].begin(), board[i][j].end(), compare);
			int surviveShark = sharkList[board[i][j][0]].id;

			for (int k = 1; k < board[i][j].size(); k++)
				sharkList[board[i][j][k]].state = false;

			board[i][j].clear();
			board[i][j].push_back(surviveShark);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> R >> C >> M;

	for (int i = 0; i < M; i++) {
		int y, x, speed, dir, size;
		cin >> y >> x >> speed >> dir >> size;

		// 모듈러 연산
		if (dir <= 2)	speed %= (2 * (R - 1));
		else speed %= (2 * (C - 1));

		sharkList.push_back({ i, y, x, speed, dir, size, true });
		board[y][x].push_back(i);
	}

	// 시뮬레이션
	while (++fisherX <= C) {
		fishing();
		moveShark();
		killShark();
	}
	cout << sum << "\n";
	return 0;
}