#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	vector <pair<int, int> > cache;
	cache.emplace_back(1, 0);
	cache.emplace_back(0, 1);
	for (int i = 2; i <= 40; i++) {
		cache.emplace_back(cache[i - 1].first + cache[i - 2].first, cache[i - 1].second + cache[i - 2].second);
	}
	int test, num;
	cin >> test;
	while (test--) {
		cin >> num;
		cout << cache[num].first << " " << cache[num].second << "\n";
	}
	return 0;
}