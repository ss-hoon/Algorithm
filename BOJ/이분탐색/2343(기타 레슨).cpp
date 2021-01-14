#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> bluelay;
int N, M, result = 0;

bool isTrue(int size) {
	int cnt = 0, sum = 0;
	for (int i = 0; i < N; i++) {
		if (size < bluelay[i])	return false;
		if (sum + bluelay[i] > size) {
			cnt++;
			sum = 0;
		}
		sum += bluelay[i];
	}
	return cnt + 1 <= M;
}

void binary_search(int start, int end) {
	if (start > end)	return;

	int mid = (start + end) / 2;
	if (isTrue(mid)) {
		result = mid;
		binary_search(start, mid - 1);
	}
	else binary_search(mid + 1, end);
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int sum = 0;
	cin >> N >> M;
	bluelay.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> bluelay[i];
		sum += bluelay[i];
	}

	binary_search(1, sum);
	cout << result << "\n";
	return 0;
}