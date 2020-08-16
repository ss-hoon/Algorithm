#include <iostream>
using namespace std;
long long cache[91] = { 0,1 };
int main() {
	int test;
	cin >> test;
	for (int i = 2; i <= test; i++)	cache[i] = cache[i - 1] + cache[i - 2];
	cout << cache[test] << "\n";
	return 0;
}