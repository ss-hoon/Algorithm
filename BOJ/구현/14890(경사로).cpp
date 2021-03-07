#include <iostream>
#include <vector>
using namespace std;
int N, L, result, board[100][100];

bool isPossible(vector<int> &road) {
	vector<bool> check(N, false);
	for (int i = 0; i < N; ++i) {
		if (i == 0)	continue;

		// 바로 전 값이 큰 경우
		if (road[i] < road[i - 1]) {
			if (i + L > N)	return false;
			for (int j = i; j < i + L; ++j) {
				if (road[i - 1] != (road[j] + 1) || check[j])	return false;
				else check[j] = true;
			}
		}

		// 바로 전 값이 작은 경우
		else if (road[i] > road[i - 1]) {
			if (i < L)	return false;
			for (int j = i - 1; j >= i - L; --j) {
				if (road[i] != (road[j] + 1) || check[j])	return false;
				else check[j] = true;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> L;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		vector<int> road(N);
		for (int j = 0; j < N; ++j) {
			road[j] = board[i][j];
		}
		if (isPossible(road))	result++;

		for (int j = 0; j < N; ++j) {
			road[j] = board[j][i];
		}
		if (isPossible(road))	result++;
	}
	cout << result;
	return 0;
}