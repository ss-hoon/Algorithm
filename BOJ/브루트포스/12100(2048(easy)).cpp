#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define UP 0
#define LEFT 1
#define RIGHT 2
#define DOWN 3
using namespace std;
int N, result = 0;

vector< vector<int> > turn(vector< vector<int> > &a, int type) {
	vector< vector<int> > temp(N, vector<int>(N, 0));
	if (type == UP)	temp = a;
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				switch (type) {
				case LEFT: // 왼쪽으로 돌리기
					temp[i][j] = a[j][N - i - 1];
					break;
				case RIGHT: // 오른쪽으로 돌리기
					temp[i][j] = a[N - j - 1][i];
					break;
				case DOWN: // 180도 돌리기
					temp[i][j] = a[N - i - 1][N - j - 1];
					break;
				}
			}
		}
	}
	return temp;
}

void game(int cnt, int type, vector< vector<int> > block) {
	if (cnt == 5)	return;

	// 위쪽을 보도록 돌리기
	if(type == LEFT)	block = turn(block, RIGHT);
	else if (type == RIGHT)	block = turn(block, LEFT);
	else block = turn(block, type);

	for (int j = 0; j < N; j++) {
		queue<int> que;
		for (int i = 0; i < N; i++) {
			if (block[i][j] != 0) {
				que.push(block[i][j]);
				block[i][j] = 0;
			}
		}

		int idx = 0;
		while (!que.empty()) {
			block[idx][j] = que.front();
			que.pop();

			if (!que.empty() && block[idx][j] == que.front()) {
				block[idx][j] *= 2;
				que.pop();
				result = max(result, block[idx][j]);
			}

			idx++;
		}
	}

	block = turn(block, type); // 다시 돌리기

	for (int i = 0; i < 4; i++) {
		game(cnt + 1, i, block);
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	vector< vector<int> > block(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> block[i][j];
			result = max(result, block[i][j]);
		}
	}

	for (int i = 0; i < 4; i++)
		game(0, i, block);
	cout << result << "\n";
	return 0;
}