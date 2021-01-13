#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
vector<ll> LAN;
ll K, N, result = 0;

void binary_search(ll start, ll end) {
	if (start > end) return;

	ll mid = (start + end) / 2;
	ll sum = 0;
	for (int i = 0; i < LAN.size(); i++) {
		sum += (LAN[i] / mid);
	}

	if (sum < N)	binary_search(start, mid - 1);
	else {
		result = mid;
		binary_search(mid + 1, end);
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> K >> N;
	LAN.resize(K);

	for (int i = 0; i < K; i++)	cin >> LAN[i];
	sort(LAN.begin(), LAN.end(), [](ll &a, ll &b) {
		return a > b;
	});

	binary_search(1, LAN[0]);
	cout << result << "\n";
	return 0;
}