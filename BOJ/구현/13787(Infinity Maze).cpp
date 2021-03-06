#include <iostream>
#include <vector>
#include <cstring>
#define ll long long
using namespace std;
ll H, W, L;
ll cache[101][101][4];
char board[101][101];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
pair<int, pair<int, int> > robot;

bool outOfRange(int y, int x) {
	if (y < 1 || y > H || x < 1 || x > W)	return true;
	return false;
}

void move() {
	ll time = 0;
	while (1) {
		if (time == L)	break;

		time++;
		int y = robot.second.first;
		int x = robot.second.second;
		int dir = robot.first;
		
		while (outOfRange(y + dy[dir], x + dx[dir]) || board[y + dy[dir]][x + dx[dir]] == '#') {
			robot.first = ++dir %= 4;
		}

		robot.second.first = y += dy[dir];
		robot.second.second = x += dx[dir];

		// 전에 방문했던 위치이고 방향도 같은 경우
		if (cache[y][x][dir] != -1) {
			time += (time - cache[y][x][dir]) * ((L - time) / (time - cache[y][x][dir]));			
		}
		else cache[y][x][dir] = time;
	}
	
	cout << robot.second.first << " " << robot.second.second << " ";

	switch (robot.first) {
	case 0:
		cout << "N\n";
		break;
	case 1:
		cout << "E\n";
		break;
	case 2:
		cout << "S\n";
		break;
	case 3:
		cout << "W\n";
		break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	
	while (cin >> H >> W >> L && H != 0 && W != 0 && L != 0) {
		memset(cache, -1, sizeof(cache));
		for (int i = 1; i <= H; ++i) {
			for (int j = 1; j <= W; ++j) {
				cin >> board[i][j];
				if (board[i][j] != '.' && board[i][j] != '#') {
					if (board[i][j] == 'N')	robot.first = 0;
					else if (board[i][j] == 'E')	robot.first = 1;
					else if (board[i][j] == 'S')	robot.first = 2;
					else robot.first = 3;
					robot.second.first = i;
					robot.second.second = j;
				}
			}
		}
		move();
	}
	return 0;
}