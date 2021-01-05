#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int row, int left, int right, vector< vector<int> > &cache) {
	if (left == right)	return cache[row][left];

	int mid = (left + right) / 2;
	int ret = max(solve(row, left, mid, cache), solve(row, mid + 1, right, cache));

	int lo = mid;	int hi = mid + 1;
	int min_num = min(cache[row][lo], cache[row][hi]);
	int cnt = 2;
	ret = max(ret, min_num * 2);

	while (left < lo || hi < right) {
		if (hi < right && (left == lo || cache[row][lo - 1] < cache[row][hi + 1])) {
			hi++;
			min_num = min(min_num, cache[row][hi]);
		}
		else {
			lo--;
			min_num = min(min_num, cache[row][lo]);
		}
		ret = max(ret, min_num * (++cnt));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;
	while (cin >> N >> M && (N != 0 && M != 0)) {
		int result = 0;
		vector< vector<int> > matrix(N, vector<int>(M, 0));
		vector< vector<int> > cache(N, vector<int>(M, 0));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> matrix[i][j];
				if (i != 0) {
					if (matrix[i][j] == 0)	cache[i][j] = 0;
					else cache[i][j] = cache[i - 1][j] + 1;
				}
				else cache[i][j] = matrix[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			result = max(solve(i, 0, M - 1, cache), result);
		}
		cout << result << "\n";
	}
	return 0;
}