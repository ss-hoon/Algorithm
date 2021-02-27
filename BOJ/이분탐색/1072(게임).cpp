#include <iostream>
#define MAX 1000000000
#define ll long long
using namespace std;

ll X, Y, Z;

ll divide(int start, int end) {
	if (start > end) {
		if (start > MAX)	return -1;
		return start;
	}

	ll mid = (start + end) / 2;

	// mid 값에서 승률이 변한다면 범위를 낮춤
	if (((Y + mid) * 100 / (X + mid)) > Z)	return divide(start, mid - 1);

	// mid 값에서 승률이 변하지 않는다면 범위를 높임
	else return divide(mid + 1, end);
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> X >> Y;
	Z = Y * 100 / X;

	cout << divide(1, MAX) << "\n";
	return 0;
}