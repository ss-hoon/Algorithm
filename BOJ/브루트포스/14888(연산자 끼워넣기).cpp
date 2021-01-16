#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> num;
int N, max_result = -1000000001, min_result = 1000000001, oper[4];

void solve(int sum, int idx) {
	if (idx == N) {
		max_result = max(max_result, sum);
		min_result = min(min_result, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i] != 0) {
			oper[i]--;
			switch (i) {
			case 0:
				solve(sum + num[idx], idx + 1);
				break;
			case 1:
				solve(sum - num[idx], idx + 1);
				break;
			case 2:
				solve(sum * num[idx], idx + 1);
				break;
			case 3:
				solve(sum / num[idx], idx + 1);
				break;
			}
			oper[i]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	num.resize(N);
	for (int i = 0; i < N; i++)	cin >> num[i];
	for (int i = 0; i < 4; i++)	cin >> oper[i];
	
	solve(num[0], 1);
	cout << max_result << "\n" << min_result << "\n";
	return 0;
}