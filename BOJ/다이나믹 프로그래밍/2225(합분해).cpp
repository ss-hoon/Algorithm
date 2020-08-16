#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector <vector<int> > cache(N + 1, vector<int>(K + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (i == 1)	cache[i][j] = j;
			else {
				if (j == 1)	cache[i][j] = 1;
				else cache[i][j] = (cache[i - 1][j] + cache[i][j - 1]) % 1000000000;
				// 점화식 : (i,j) = (i-1,j) + (i,j-1)
				// ex) (4,3)인 경우 (0,2) + (1,2) + (2,2) + (3,2) + (4,2)이다
				// 하지만 (0,2) + (1,2) + (2,2) + (3,2)는 (3,3)과 동일하므로
				// (4,3)은 (4,2)와 (3,3)을 더한 값과 같다
			}
		}
	}
	cout << cache[N][K] << "\n";
	return 0;
}