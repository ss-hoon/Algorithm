#include <iostream>
using namespace std;
int eureka[46];
int N, num;

bool check(int sum, int cnt, int idx) {
	if (cnt == 3) {
		if (sum == num)	return true;
		else return false;
	}

	if (check(sum + eureka[idx], cnt + 1, idx))	return true;
	if (idx < 45 && sum + eureka[idx + 1] <= num && check(sum, cnt, idx + 1))	return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i <= 45; i++)	eureka[i] = (i * (i + 1) / 2);
	while (N--) {
		cin >> num;
		if (check(0, 0, 1))	cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}