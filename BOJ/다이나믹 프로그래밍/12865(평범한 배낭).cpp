#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N, K, weight, value;
	cin >> N >> K;
	vector<int> cache(K + 1, 0);

	for (int i = 0; i < N; i++) {
		cin >> weight >> value;
		for (int j = K; j >= weight; j--)	cache[j] = max(cache[j], cache[j - weight] + value);
	}

	cout << cache[K] << "\n";
	return 0;
}