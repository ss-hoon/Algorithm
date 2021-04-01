#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	string min, max, line;
	int cnt = 0;
	cin >> line;

	for (char c : line) {
		if (c == 'M') {
			if (cnt == 0)    min += "1";
			else min += "0";
			cnt++;
		}
		else {
			min += "5";
			max += "5";
			if (cnt != 0) {
				for (int i = 0; i < cnt; i++)  max += "0";
			}
			cnt = 0;
		}
	}
	if (cnt != 0) {
		for (int i = 0; i < cnt; i++)  max += "1";
	}
	cout << max << "\n" << min;
	return 0;
}