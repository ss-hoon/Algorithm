#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
char map[6][6];
vector< pair<int, int> > teacher;

bool check() {
	for (auto t : teacher) {

		// 네 방향에 학생들이 있는지 확인
		for (int i = 0; i < 4; i++) {
			int ny = t.first + dy[i];
			int nx = t.second + dx[i];

			while (1) {
				if (ny < 0 || ny >= N || nx < 0 || nx >= N)	break;
				if (map[ny][nx] == 'T' || map[ny][nx] == 'O')	break;
				if (map[ny][nx] == 'S')	return false;

				ny += dy[i];
				nx += dx[i];
			}
		}
	}
	return true;
}

// 장애물 설치
bool obstacle(int cnt) {
	if (cnt == 3) {
		if (check())	return true;
		else return false;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'X') {
				map[i][j] = 'O';
				if (obstacle(cnt + 1))	return true;
				map[i][j] = 'X';
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'T')	teacher.push_back({ i, j });
		}
	}

	cout << (obstacle(0) ? "YES\n" : "NO\n");
	return 0;
}