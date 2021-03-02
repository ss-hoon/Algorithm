#include <iostream>
using namespace std;
bool check[1001] = { false };

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N, K, i = 1, j;
	cin >> N >> K;

	while (K) {
		// 소수 찾기
		while (check[++i]);
		for (j = i; j <= N; j += i) {

			// 한번도 방문하지 않은 부분만 체크
			if (!check[j]) {
				check[j] = true;
				K--;
			}

			// K가 0이면 반복종료
			if (!K)	break;
		}
	}
	cout << j << "\n";
	return 0;
}