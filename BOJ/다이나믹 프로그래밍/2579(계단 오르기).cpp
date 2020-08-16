#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cache[3][300];
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	vector <int> stair;
	int test, num;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> num;
		stair.push_back(num);
	}
	cache[0][0] = cache[2][0] = stair[0];
	cache[1][0] = 0;
	for (int j = 1; j < test; j++) {
		for (int i = 0; i < 3; i++) {
			if (i == 0)	cache[0][j] = cache[2][j - 1] + stair[j];
			else if (i == 1)	cache[1][j] = max(cache[0][j - 1], cache[2][j - 1]);
			else cache[2][j] = cache[1][j - 1] + stair[j];
		}
	}
	cout << max(cache[0][test - 1], cache[2][test - 1]) << "\n";
	return 0;
}