#include <iostream>
#define ui unsigned int
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		ui start, end, cnt = 2;
		cin >> start >> end;
		while (cnt * cnt - cnt < end - start)	cnt++;

		ui next = (cnt * cnt - cnt);
		ui pre = (cnt - 1) * (cnt - 1) - (cnt - 1);

		cout << (end - start <= pre + (next - pre) / 2 ? 2 * (cnt - 1) - 1 : 2 * (cnt - 1)) << "\n";
	}
	return 0;
}