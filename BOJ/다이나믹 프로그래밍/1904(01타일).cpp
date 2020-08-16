#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N;
	cin >> N;
	vector <int> cache(N + 1);
	cache[1] = 1;	cache[2] = 2;
	for (int i = 3; i <= N; i++) {
		cache[i] = (cache[i - 2] + cache[i - 1]) % 15746;
		// 점화식 : i = (i-2) + (i-1)
		// i번째의 2진 수열의 개수는
		// (i-2)번째의 수에 00을 추가한 경우와
		// (i-1)번째의 수에 1을 추가한 경우만 있기 때문
	}
	cout << cache[N] << "\n";
	return 0;
}