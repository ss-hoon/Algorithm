#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };
int N, M;

struct info {
	int x, y, length, crash;
};

int bfs(vector< vector<char> > &crash_board, vector< vector<char> > &nonCrash_board) {
	queue<info> q;
	q.push({ 0,0,1,0 });
	while (!q.empty()) {
		int x = q.front().x;	int y = q.front().y;
		if (x == M - 1 && y == N - 1)	return q.front().length;
		for (int i = 0; i < 4; i++) {
			if (x + dx[i] < 0 || x + dx[i] >= M || y + dy[i] < 0 || y + dy[i] >= N || (q.front().crash == 1 && (crash_board[y+dy[i]][x+dx[i]] == '1' || crash_board[y + dy[i]][x + dx[i]] == '2')) || (q.front().crash == 0 && nonCrash_board[y + dy[i]][x + dx[i]] == '2'))	continue;
			if (q.front().crash == 0 && nonCrash_board[y + dy[i]][x + dx[i]] == '1') {
				q.push({ x + dx[i], y + dy[i], q.front().length + 1, 1 });
				crash_board[y + dy[i]][x + dx[i]] = '2';
			}
			else {
				if (q.front().crash == 1) {
					q.push({ x + dx[i], y + dy[i], q.front().length + 1, 1 });
					crash_board[y + dy[i]][x + dx[i]] = '2';
				}
				else {
					q.push({ x + dx[i], y + dy[i], q.front().length + 1, 0 });
					nonCrash_board[y + dy[i]][x + dx[i]] = '2';
				}
			}
		}
		q.pop();
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	vector< vector<char> > crash_board(N, vector<char>(M, 0));
	vector< vector<char> > nonCrash_board(N, vector<char>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> crash_board[i][j];
			nonCrash_board[i][j] = crash_board[i][j];
		}
	}
	crash_board[0][0] = nonCrash_board[0][0] = '2';
	cout << bfs(crash_board, nonCrash_board) << "\n";
	return 0;
}