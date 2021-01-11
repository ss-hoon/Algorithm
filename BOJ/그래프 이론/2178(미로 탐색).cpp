#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };
int N, M;

struct info {
	int x;
	int y;
	int length;
};

int bfs(vector< vector<char> > &board) {
	queue<info> q;
	q.push({ 0,0,1 });

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;

		if (y == N - 1 && x == M - 1)	return q.front().length;
		for (int i = 0; i < 4; i++) {
			if (x + dx[i] < 0 || x + dx[i] >= M || y + dy[i] < 0 || y + dy[i] >= N || board[y + dy[i]][x + dx[i]] == '0')	continue;
			q.push({ x + dx[i],y + dy[i],q.front().length + 1 });
			board[y + dy[i]][x + dx[i]] = '0';
		}
		q.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	vector< vector<char> > board(N, vector<char>(M, 0));


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	board[0][0] = 0;
	cout << bfs(board) << "\n";
	return 0;
}