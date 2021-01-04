#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> h;

long long solve(int left, int right) {
	if (left == right)	return (long long)h[left] * h[left];

	int mid = (left + right) / 2;
	long long ret = max(solve(left, mid), solve(mid + 1, right));

	int lo = mid;	int hi = mid + 1;
	int min_num = min(h[lo], h[hi]);

	long long sum = h[lo] + h[hi];
	ret = max(ret, sum * min_num);

	while (left < lo || hi < right) {
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			hi++;
			min_num = min(min_num, h[hi]);
			sum += h[hi];
		}
		else {
			lo--;
			min_num = min(min_num, h[lo]);
			sum += h[lo];
		}
		ret = max(ret, sum * min_num);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int n;
	cin >> n;
	h.resize(n);
	for (int i = 0; i < n; i++)	cin >> h[i];

	cout << solve(0, n - 1) << "\n";
	return 0;
}