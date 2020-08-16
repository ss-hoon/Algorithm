#include <iostream>
using namespace std;
int cache[1000000] = { 0,1,2,4 };
int main() {
	for (int i = 4; i < 12; i++)	cache[i] = cache[i - 3] + cache[i - 2] + cache[i - 1];
	int test, num;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> num;
		cout << cache[num] << "\n";
	}
	return 0;
}