#include <iostream>
#include <vector>
using namespace std;

int N, M, R, result[301][301];

void rotate() {
	int stage = (N > M ? M / 2 : N / 2);
	int num = 0;

	while (stage > 0) {
		int y = stage;	int x = stage;
		int temp = result[y][x];

		while (x + 1 <= M - stage + 1) {
			result[y][x] = result[y][x + 1];
			x++;
		}

		while (y + 1 <= N - stage + 1) {
			result[y][x] = result[y + 1][x];
			y++;
		}

		while (x - 1 >= stage) {
			result[y][x] = result[y][x - 1];
			x--;
		}

		while (y - 1 >= stage) {
			result[y][x] = result[y - 1][x];
			y--;
		}

		result[y + 1][x] = temp;
		stage--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M >> R;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)	cin >> result[i][j];
	}

	while (R--) {
		rotate();
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)	cout << result[i][j] << " ";
		cout << "\n";
	}
	return 0;
}