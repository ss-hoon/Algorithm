#include <iostream>
using namespace std;
int N, prime[1000001];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);

	// 에라토스테네스의 체 (소수 판별 전처리)
	for (int i = 2; i <= 1000; ++i) {
		for (int j = i * 2; j <= 1000000; j += i) {
			prime[j] = 1;
		}
	}

	// 소수 판별
	// N = i + (N - i) 이용
	while (cin >> N && N != 0) {
		for (int i = 2; i <= N / 2; ++i) {
			if (!prime[i] && !prime[N - i]) {
				cout << N << " = " << i << " + " << N - i << "\n";
				break;
			}
			if (i == N / 2)	cout << "Goldbach's conjecture is wrong.\n";
		}
	}
	return 0;
}