#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
vector<ll> pass;
int N, M;

ll binary_search(ll start, ll end) {
	if (start > end)	return start;

	ll mid = (start + end) / 2;
	ll cnt = 0;
	for (int i = 0; i < N; i++)	cnt += mid / pass[i];

	if (M <= cnt)	return binary_search(start, mid - 1);
	else return binary_search(mid + 1, end);
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	ll max_time = 0;
	cin >> N >> M;
	pass.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> pass[i];
		max_time = max(pass[i], max_time);
	}

	cout << binary_search(1, max_time * M) << "\n";
	return 0;
}