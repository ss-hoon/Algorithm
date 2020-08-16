#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int cache[1000001];
int main() {
	int n;
	cin >> n;
	memset(cache, 123, sizeof(cache));
	cache[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (i % 3 == 0)	cache[i] = cache[i / 3] + 1;
		if (i % 2 == 0)	cache[i] = min(cache[i], cache[i / 2] + 1);
		cache[i] = min(cache[i], cache[i - 1] + 1);
	}
	cout << cache[n] << "\n";
	return 0;
}