#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, cacheMax[3], cacheMin[3], mx[3], mn[3];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		// 0번 인덱스의 최대값은 지금까지 계산한 최대값의 0번과 1번 중 max값을 더하고
		// 1번 인덱스의 최대값은 지금까지 계산한 최대값의 0번과 1번과 2번 중 max값을 더하고
		// 2번 인덱스의 최대값은 지금까지 계산한 최대값의 1번과 2번 중 max값을 더한다

		// 0번 인덱스의 최소값은 지금까지 계산한 최소값의 0번과 1번 중 min값을 더하고
		// 1번 인덱스의 최소값은 지금까지 계산한 최소값의 0번과 1번과 2번 중 min값을 더하고
		// 2번 인덱스의 최소값은 지금까지 계산한 최소값의 1번과 2번 중 min값을 더한다
		for (int j = 0; j < 3; j++) {
			cin >> cacheMin[j];
			cacheMax[j] = cacheMin[j];
			cacheMax[j] += max(mx[1], (j == 1 ? max(mx[0], mx[2]) : mx[j]));
			cacheMin[j] += min(mn[1], (j == 1 ? min(mn[0], mn[2]) : mn[j]));
		}
		memcpy(mx, cacheMax, sizeof(int) * 3);
		memcpy(mn, cacheMin, sizeof(int) * 3);
	}

	cout << *max_element(mx, mx + 3) << " " << *min_element(mn, mn + 3) << "\n";
	return 0;
}