#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int n, cnt = 0, num = 1;
	cin >> n;

	do {
		cnt++;
		num = 3 * cnt * cnt - 3 * cnt + 1;
		if (n <= num)	break;
	} while (1);
	cout << cnt << "\n";
	return 0;
}