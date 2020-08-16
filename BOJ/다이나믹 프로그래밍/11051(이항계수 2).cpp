#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector <vector<int> > cache(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || i == j)	cache[i][j] = 1;
			else cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j]) % 10007;
			// 점화식 : 이항계수 법칙 ((n)C(k) = (n-1)C(k-1) + (n-1)C(k))
		}
	}
	cout << cache[N][K] << "\n";
	return 0;
}