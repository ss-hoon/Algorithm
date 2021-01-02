#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int n, cnt = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i % 125 == 0)	cnt += 3;
		else if (i % 25 == 0)	cnt += 2;
		else if(i % 5 == 0)	cnt++;
	}

	cout << cnt << "\n";
	return 0;
}