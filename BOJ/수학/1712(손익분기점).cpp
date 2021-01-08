#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int A, B, C;
	cin >> A >> B >> C;
	if (B >= C)	cout << "-1\n";
	else cout << A / (C - B) + 1 << "\n";
	return 0;
}