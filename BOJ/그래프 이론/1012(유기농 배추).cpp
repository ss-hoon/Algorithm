#include <iostream>
using namespace std;
int field[50][50] = {};
int dx[4] = { 0,-1,1,0 };	int dy[4] = { -1,0,0,1 }; // 상하좌우 x좌표, y좌표
int row, col, seed, row_seed, col_seed, cnt; // 순서대로 세로, 가로, 배추가 심어진 개수, 배추가 심어진 위치(가로), 배추가 심어진 위치(세로), 몇마리의 배추흰지렁이가 필요한지 count
void dfs(int width, int height) {
	if (field[height][width] == 0 || height < 0 || height > row - 1 || width < 0 || width > col - 1)	return; // 기저 사례
	else field[height][width] = 0; // 배추흰지렁이가 갈 수 있는 곳을 0으로 바꿈
	for (int i = 0; i < 4; i++) dfs(dx[i] + width, dy[i] + height); // 상하좌우 이동
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int test;
	cin >> test;
	while (test--) {
		cin >> col >> row >> seed;
		cnt = 0;
		while (seed--) {
			cin >> col_seed >> row_seed;
			field[row_seed][col_seed] = 1; // 배추가 심어진 위치에 1을 넣는다
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (field[i][j] != 0) { // 해당 위치가 0이 아닌경우
					cnt++;
					dfs(j, i);
				}
			}
		}
		cout << cnt << "\n"; // count 출력
	}
	return 0;
}