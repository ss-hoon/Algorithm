#include <iostream>
using namespace std;
int cache[21][21][21];
int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)	return 1;
	if (a > 20 || b > 20 || c > 20)	return w(20, 20, 20);
	if (cache[a][b][c])	return cache[a][b][c];

	if (a < b && b < c)	return cache[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else return cache[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int a, b, c;
	while (cin >> a >> b >> c && !(a == -1 && b == -1 && c == -1)) {
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
	}
	return 0;
}