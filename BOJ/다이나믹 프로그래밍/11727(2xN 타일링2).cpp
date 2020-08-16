#include <iostream>
using namespace std;
int cache[1001] = { 0,1,3 };
int main() {
	int test;
	cin >> test;
	for (int i = 3; i <= test; i++)	cache[i] = (cache[i - 1] + cache[i - 2] * 2) % 10007;
	cout << cache[test] << "\n";
	return 0;
}