#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
int cache[1000001];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	ll mn, mx, result = 0;
	cin >> mn >> mx;

	// 수의 범위가 매우 크기 때문에 처음부터 구하면 시간초과 이므로,
	// stamp를 통해 초기값을 O(1)로 구한 뒤
	// stamp에 해당 제곱수를 더하며 나누어 떨어지는 값을 제외한다.
	for (ll i = 2; i <= sqrt(mx); i++) {
		ll num = i * i;
		ll stamp = ceil((double)mn / num) * num;

		for (ll j = stamp; j <= mx; j += num) {
			if (cache[j - mn] == 0) {
				cache[j - mn] = 1;
				result++;
			}
		}
	}

	cout << mx - mn + 1 - result << "\n";
	return 0;
}