#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> router;
int N, C, result = 0;

bool isPossible(int diff) {
	int cnt = 1;
	int tmp = router[0];
	for (int i = 1; i < N; i++) {
		if (router[i] - tmp < diff)	continue;
		else {
			tmp = router[i];
			cnt++;
		}
	}
	return C <= cnt;
}

void binary_search(int start, int end) {
	if (start > end)	return;

	int mid = (start + end) / 2;
	if (isPossible(mid)) {
		result = mid;
		binary_search(mid + 1, end);
	}
	else binary_search(start, mid - 1);
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> C;
	router.resize(N);

	for (int i = 0; i < N; i++)	cin >> router[i];
	sort(router.begin(), router.end());

	binary_search(1, router[N - 1]);
	cout << result << "\n";
	return 0;
}