#include <iostream>
#include <vector>
using namespace std;
vector< vector<bool> > check;
vector< vector<int> > board;
int W, H;
int dx[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
int dy[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
void dfs(int y, int x) {
	check[y][x] = true;
	for (int i = 0; i < 9; i++) {
		int Y = y + dy[i];
		int X = x + dx[i];
		if (Y < 0 || Y >= H || X < 0 || X >= W || check[Y][X] || board[Y][X] == 0)	continue;
		else dfs(Y, X);
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	while (1) {
		int cnt = 0;
		cin >> W >> H;
		if (W == 0 && H == 0)	break;
		check.resize(H, vector<bool>(W, false));
		board.resize(H, vector<int>(W, 0));
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)	cin >> board[i][j];
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (board[i][j] == 1 && check[i][j] == false) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		check.clear();
		board.clear();
	}
	return 0;
}