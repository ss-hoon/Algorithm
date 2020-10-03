#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> seq;
vector<int> cache;
int n;
int dp(int num) {
	if (cache[num] != 0)	return cache[num];

	int mx = 0;
	for (int i = num + 1; i < n; i++) {
		if (seq[i] > seq[num])	mx = max(mx, dp(i));
	}
	return cache[num] = mx + 1;
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> n;
	seq.resize(n);
	cache.resize(n);

	int index, mx = 0;
	for (int i = 0; i < n; i++)	cin >> seq[i];
	for (int i = 0; i < n; i++) {
		if (cache[i] == 0) mx = max(mx, dp(i));
	}
	
	cout << mx << "\n";
	for (int i = 0; i < n; i++) {
		if (mx == cache[i]) {
			cout << seq[i] << " ";
			mx--;
		}
		if (mx == -1)	break;
	}
	return 0;
}