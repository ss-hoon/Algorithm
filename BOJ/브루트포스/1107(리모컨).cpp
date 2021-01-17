#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int N, M;
vector<bool> error(10 , false);

bool check(int num) {
	if (num == 0 && error[0])	return false;
	while (num > 0) {
		if (error[num % 10])	return false;
		num /= 10;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	int min_cnt = abs(N - 100);

	for (int i = 0; i < M; i++) {
		int btn;
		cin >> btn;
		error[btn] = true;
	}

	for (int i = 0; i < 1000000; i++) {
		if (!check(i))	continue;
		string tmp = to_string(i);

		min_cnt = min(min_cnt, (int)(abs(N - i) + tmp.length()));
	}
	cout << min_cnt << "\n";
	return 0;
}