#include <iostream>
#include <cstring>
using namespace std;
int cache[31] = {};

int dp(int n) {
	if (n == 0)	return 1;
	if (n == 2)	return 3;
	if (n % 2 != 0)	return 0;
	if (cache[n] != -1)	return cache[n];

	int result = dp(n - 2) * 3; // 2번째 전 타일의 경우 * (3 * 2) 타일의 경우(3개)
	for (int i = 4; i < n; i += 2)	result += 2 * dp(n - i); // ex) 4번째 전 고유 타일(2개) * (N - 4)번째 전 경우
	result += 2; // 현재 고유타일(2개)
	return cache[n] = result;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N;
	cin >> N;
	memset(cache, -1, sizeof(cache));
	cout << dp(N) << "\n";
	return 0;
}