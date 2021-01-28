#include <iostream>
#include <vector>
#define ll long long
using namespace std;
vector< vector<int> > board;
vector< vector<ll> > cache;
int N;

ll search(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= N)	return 0;
	if (y == N - 1 && x == N - 1)	return 1;
	if (cache[y][x] != -1)	return cache[y][x];

	if (board[y][x] == 0)	return 0;
	return cache[y][x] = search(y + board[y][x], x) + search(y, x + board[y][x]);
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	board.resize(N, vector<int>(N, 0));
	cache.resize(N, vector<ll>(N, -1));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)	cin >> board[i][j];
	}

	cout << search(0, 0) << "\n";
	return 0;
}