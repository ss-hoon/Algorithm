#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N, K, R, result, p[10300];
bool isRoad[101][101][4];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
vector< pair<int, int> > cow;

int find(int x) {
	if (x == p[x])	return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y)	return;
	p[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> K >> R;

	while (R--) {
		int r1, r2, c1, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		for (int i = 0; i < 4; i++) {
			if (r1 + dy[i] == r2 && c1 + dx[i] == c2) {
				isRoad[r1][c1][i] = true;

				if (i < 2)	isRoad[r2][c2][i + 2] = true;
				else isRoad[r2][c2][i - 2] = true;
				break;
			}
		}
	}

	// init
	for (int i = 1; i <= (N + 1) * (N + 1); i++)	p[i] = i;

	// union-find
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < 4; k++) {
				int y = i + dy[k];
				int x = j + dx[k];
				if (y < 1 || y > N || x < 1 || x > N || isRoad[i][j][k])	continue;

				merge(find(i * N + j), find(y * N + x));
			}
		}
	}

	// 각각의 소가 있는 땅이 같은 부모인지 확인
	// 다르면 길을 통해서 지나가야하므로 result++
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		cow.push_back({ r, c });
		for (int j = 0; j < i; j++) {
			if (find(cow[i].first * N + cow[i].second) != find(cow[j].first * N + cow[j].second))	result++;
		}
	}

	cout << result << "\n";
	return 0;
}