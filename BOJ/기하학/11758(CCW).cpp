#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int ccw = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1); // CCW 공식
	if (ccw < 0)	cout << -1 << "\n";
	else if (ccw == 0)	cout << 0 << "\n";
	else cout << 1 << "\n";
	return 0;
}