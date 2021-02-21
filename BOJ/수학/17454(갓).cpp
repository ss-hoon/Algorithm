#include <iostream>
using namespace std;
int T, vote[6];

bool isPossible() {
	int n1 = vote[2] - vote[3];
	int n2 = vote[4];
	int m1 = vote[2];
	int m2 = vote[4] - vote[5];

	if (n1 * m2 < n2 * m1)	return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> T;
	while (T--) {
		for (int i = 0; i < 6; i++)	cin >> vote[i];
		if (isPossible())	cout << "GOD\n";
		else cout << "KDH\n";
	}
	return 0;
}