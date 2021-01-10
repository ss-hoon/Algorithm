#include <iostream>
#include <cmath>
#include <vector>
#define MAX 10000
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	vector<bool> check(MAX + 1, false);
	int T, N;
	
	for (int i = 2; i <= sqrt(MAX); i++) {
		for (int j = i * 2; j <= MAX; j += i)
			check[j] = true;
	}

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = N / 2; i >= 2; i--) {
			if (!check[i] && !check[N - i]) {
				cout << i << " " << N - i << "\n";
				break;
			}
		}
	}	
	return 0;
}