#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, M, floyd[101][101];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;

	// init
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)	floyd[i][j] = INF;
	}

	// 입력 받은 edge 중 가장 최소값을 floyd 배열에 input
	for (int i = 0; i < M; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		floyd[start][end] = min(floyd[start][end], weight);
	}

	// Floyd Algorithm
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j || i == k)	continue;
				// (2 -> 3) == (2 -> 1) + (1 -> 3)
				floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)	cout << (floyd[i][j] == 1e9 ? 0 : floyd[i][j]) << " ";
		cout << "\n";
	}
	return 0;
}