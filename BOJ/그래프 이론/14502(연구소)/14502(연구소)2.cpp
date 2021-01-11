#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int map[8][8] = {};
int map_temp[8][8] = {};
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int row, col, temp_virus = 0, min_virus = 65;
void set_map() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)	map_temp[i][j] = map[i][j];
	}
}
void infest_virus(int xx, int yy) {
	for (int i = 0; i < 4; i++) {
		int x = xx + dx[i];	int y = yy + dy[i];
		if (x<0 || y<0 || x>row - 1 || y>col - 1 || map_temp[x][y] != 0)	continue;
		map_temp[x][y] = 2;
		temp_virus++;
		infest_virus(x, y);
	}
}
void protect(int x, int y, int cnt) {
	if (cnt == 3) {
		set_map();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map_temp[i][j] == 2)	infest_virus(i, j);
			}
		}
		min_virus = min(min_virus, temp_virus);
		temp_virus = 0;
		return;
	}
	for (int j = y; j < col; j++) {
		if (map[x][j] == 0) {
			map[x][j] = 1;
			protect(x, j, cnt + 1);
			map[x][j] = 0;
		}
	}
	for (int i = x; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				protect(i, j + 1, cnt + 1);
				map[i][j] = 0;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int ans = 0;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)	ans++;
		}
	}
	protect(0, 0, 0);
	cout << ans - 3 - min_virus << "\n";
	return 0;
}