#include <iostream>
using namespace std;
#define MOD 1000000000
long long cache[10][101];
int main() {
	long long test, sum = 0;
	cin >> test;
	for (int i = 1; i <= 9; i++)	cache[i][1] = 1;
	for (int j = 2; j <= 100; j++) {
		for (int i = 0; i <= 9; i++) {
			if (i == 0)	cache[i][j] = cache[i + 1][j - 1] % MOD;
			else if (i == 9)	cache[i][j] = cache[i - 1][j - 1] % MOD;
			else cache[i][j] = (cache[i - 1][j - 1] + cache[i + 1][j - 1]) % MOD;
		}
	}
	for (int i = 0; i <= 9; i++) {
		sum += (cache[i][test] % MOD);
	}
	cout << sum % MOD << "\n";
	return 0;
}