#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
char board[5][5];
int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };
set<string> numSet;

void jump(int y, int x, string num) {
	if (num.length() == 6) {
		numSet.insert(num);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int Y = y + dy[i];
		int X = x + dx[i];

		if (Y < 0 || Y >= 5 || X < 0 || X >= 5)	continue;

		jump(Y, X, num + board[y][x]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)	cin >> board[i][j];
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)	jump(i, j, "");
	}
	cout << numSet.size() << "\n";
	return 0;
}