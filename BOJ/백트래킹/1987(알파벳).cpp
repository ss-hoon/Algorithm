#include <iostream>
#include <vector>
using namespace std;
vector< vector<char> > map;
vector<bool> checkAlpha;
int R, C, result = 0;
int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };

void dfs(int y, int x, int sum) {
	if (result < sum)	result = sum;

	checkAlpha[map[y][x] - 'A'] = true;
	for (int i = 0; i < 4; i++) {
		int Y = y + dy[i];
		int X = x + dx[i];

		if (Y >= 0 && Y < R && X >= 0 && X < C && checkAlpha[map[Y][X] - 'A'] == false) {
			dfs(Y, X, sum + 1);
		}
	}
	checkAlpha[map[y][x] - 'A'] = false;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> R >> C;
	map.resize(R + 1, vector<char>(C + 1));
	checkAlpha.resize(26, false);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) cin >> map[i][j];
	}

	dfs(0, 0, 1);
	cout << result << "\n";
	return 0;
}