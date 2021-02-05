#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector< pair<int, int> > wire;
vector<int> cache;
int N, result;
int searchMinWire(int prev, int idx) {
	int ret = 0;

	// 현재 인덱스가 전깃줄 개수를 넘어가는 경우
	if (N < idx)	return 0;

	// 이미 한번 계산한 경우(중복 X)
	if (cache[idx] != -1)	return cache[idx];

	// 현재 인덱스의 전깃줄을 놓고 그 다음에 놓일 수 있는 전깃줄 개수를 계산
	// 그 다음에 놓일 수 있는 전깃줄은 현재 인덱스의 전깃줄보다 더 높은 숫자에 놓여야 겹치지 않음
	for (int i = idx + 1; i <= N; i++) {
		if (prev < wire[i].second)	ret = max(ret, searchMinWire(wire[i].second, i));
	}
	return cache[idx] = ret + 1;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	wire.resize(N + 1);
	cache.resize(N + 1, -1);

	for (int i = 1; i <= N; i++)	cin >> wire[i].first >> wire[i].second;
	sort(wire.begin(), wire.end());

	for (int i = 1; i <= N; i++)	result = max(result, searchMinWire(wire[i].second, i));

	cout << N - result << "\n";
	return 0;
}