#include <iostream>
#include <algorithm>
using namespace std;
int N, a, b, c, test, result = 999, parent[101], num1[101], num2[101];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> a >> b >> test;
	
	while (test--) {
		int x, y;
		cin >> x >> y;
		parent[y] = x;
	}

	while (a) {
		num1[a] = ++c;
		a = parent[a];
	}
	c = 0;
	while (b) {
		num2[b] = ++c;
		b = parent[b];
	}

	for (int i = 0; i < N; i++) {
		if (num1[i] && num2[i])	result = min(result, num1[i] + num2[i] - 2);
	}
	result != 999 ? cout << result << "\n" : cout << "-1\n";
	return 0;
}