#include <iostream>
#include <cmath>
using namespace std;

bool check(int A, int B, int C) {
	if (A > B && A > C && pow(A, 2) == pow(B, 2) + pow(C, 2))	return true;
	if (B > A && B > C && pow(B, 2) == pow(A, 2) + pow(C, 2))	return true;
	if (C > A && C > B && pow(C, 2) == pow(A, 2) + pow(B, 2))	return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int A, B, C;
	while (cin >> A >> B >> C && !(A == 0 && B == 0 && C == 0)) {
		if (check(A, B, C))	cout << "right\n";
		else cout << "wrong\n";
	}
	return 0;
}