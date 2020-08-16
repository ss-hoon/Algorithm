#include <iostream>
#include <vector>
using namespace std;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int M, N;
vector<vector<int> > path;
vector<vector<int> > cache;

int search_path(int x, int y) {
	if (x == M - 1 && y == N - 1)	return 1;
	if (cache[x][y] != -1)	return cache[x][y];

	int sum = 0;
	for (int index = 0; index < 4; index++) {
		int nx = x + dx[index];
		int ny = y + dy[index];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N && path[x][y] > path[nx][ny])	sum += search_path(nx, ny);
	}
	return cache[x][y] = sum;
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> M >> N;
	path.resize(M, vector<int>(N, 0));
	cache.resize(M, vector<int>(N, -1));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)	cin >> path[i][j];
	}

	cout << search_path(0, 0) << "\n";
	return 0;
}