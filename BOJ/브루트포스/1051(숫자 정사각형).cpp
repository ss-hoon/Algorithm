#include <iostream>
#include <algorithm>
using namespace std;
char square[50][50];
int N, M, max_result = 1;

int search(int y, int x) {
	int result = 0;
	for (int i = y + 1; i < N; i++) {
		if (square[i][x] != square[y][x])	continue;
		else {
			int tmp = i - y;
			if (x + tmp < M && square[i][x + tmp] == square[y][x] && square[y][x + tmp] == square[y][x])	result = max(result, (tmp + 1) * (tmp + 1));
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> square[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)	max_result = max(max_result, search(i, j));
	}

	cout << max_result << "\n";
	return 0;
}