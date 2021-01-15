#include <iostream>
#include <algorithm>
using namespace std;
int N, K;

int binary_search(int start, int end) {
	if (start > end)	return start;

	int mid = (start + end) / 2;
	int cnt = 0;
	for (int i = 1; i <= min(mid, N); i++)
		cnt += min(N, mid / i);

	if (K <= cnt)	return binary_search(start, mid - 1);
	else return binary_search(mid + 1, end);
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> K;

	cout << binary_search(1, K) << "\n";
	return 0;
}