#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
vector<ll> pay;

ll solve(int left, int right) {
	if (left == right)	return pay[left];

	int mid = (left + right) / 2;
	ll ret = max(solve(left, mid), solve(mid + 1, right));

	int lo = mid;	int hi = mid + 1;
	int cnt = 2;
	ll min_pay = min(pay[lo], pay[hi]);
	ret = max(ret, min_pay * 2);

	while (left < lo || hi < right) {
		if (left <= lo && (hi == right || pay[lo - 1] > pay[hi + 1])) {
			lo--;
			min_pay = min(min_pay, pay[lo]);
		}
		else {
			hi++;
			min_pay = min(min_pay, pay[hi]);
		}
		ret = max(ret, min_pay * ++cnt);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int n;
	cin >> n;
	pay.resize(n);
	for (int i = 0; i < n; i++)	cin >> pay[i];

	cout << solve(0, n - 1) << "\n";
	return 0;
}