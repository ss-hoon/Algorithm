#include <iostream>
#include <cmath>
#include <vector>
#define MAX 250000
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	vector<bool> check(MAX + 1, false);
	int start;
	
	for (int i = 2; i <= sqrt(MAX); i++) {
		for (int j = i * 2; j <= MAX; j += i)
			check[j] = true;
	}

	while (cin >> start && start != 0) {
		int cnt = 0;
		for (int i = start + 1; i <= 2 * start; i++) {
			if (!check[i])	cnt++;
		}
		cout << cnt << "\n";
	}
	
	return 0;
}