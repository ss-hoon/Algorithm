#include <iostream>
#include <algorithm>
using namespace std;
int N, S, start, sum, result = 100001, list[100000];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		sum += list[i];

		// sum이 S를 넘는다면
		// S보다 작을 때까지 반복하면서
		// 최소 개수로 S를 만들 수 있는 값을 찾는다
		while (sum >= S) {
			result = min(result, i - start + 1);
			sum -= list[start];
			start++;
		}
	}

	// 초기값 그대로이면
	// 만족하는 수가 없는 것이므로 0 출력
	cout << (result == 100001 ? 0 : result) << "\n";
	return 0;
}