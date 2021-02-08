#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int cache[1001], list[1001], N, result = 0;

int LIS(int n) {
	if (cache[n] != -1)	return cache[n];

	int sum = 0;
	// 현 위치보다 뒤에 있는 위치를 순회하면서
	// 현재 수보다 큰 수를 찾아 재귀문을 실행하여 LIS를 구한다
	// 그리고 그 수에 자기 자신을 포함하기 위해 + 1하고 return
	for (int i = n + 1; i < N; i++) {
		if (list[n] < list[i])	sum = max(sum, LIS(i));
	}
	return cache[n] = sum + 1;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> list[i];
	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < N; i++)	result = max(result, LIS(i));
	cout << result << "\n";
	return 0;
}