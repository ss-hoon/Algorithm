#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cache[30], test;
vector <pair <int, int> > schedule;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> test;
	schedule.resize(test + 1);
	for (int i = 1; i <= test; i++) { // 입력(걸리는 기간, 받을수 있는 금액)
		cin >> schedule[i].first >> schedule[i].second;
	}
	for (int i = test; i > 0; i--) { // 그 위치에서의 최대로 받을 수 있는 금액(dp)
		if (i + schedule[i].first - 1 > test)	cache[i] = cache[i + 1]; // 그 기간에서 걸리는 기간이 최대 기간보다 넘어갈 경우 바로 그 다음날의 최대값을 가져옴
		else cache[i] = max(cache[i + 1], schedule[i].second + cache[i + schedule[i].first]); // 그 다음날의 최대값과 현재 선택하여 받을 수 있는 금액 + 그 일을 끝마친 후(며칠 뒤) 그 기간에서 받을 수 있는 금액을 비교
	}
	cout << cache[1] << "\n";
	return 0;
}