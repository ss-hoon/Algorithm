#include <iostream>
using namespace std;
long long cache[101] = { 0,1,1,1,2 };
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int test;
	cin >> test;
	for (int i = 5; i <= 100; i++)	cache[i] = cache[i - 1] + cache[i - 5];
	while (test--) {
		int num;
		cin >> num;
		cout << cache[num] << "\n";
	}
	return 0;
}