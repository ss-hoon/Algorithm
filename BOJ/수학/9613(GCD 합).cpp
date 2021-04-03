#include <iostream>
using namespace std;

// 최대공약수 함수
int gcd(int a, int b) {
	if (b == 0)	return a;
	return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int T, N, list[100];
	cin >> T;
	while (T--) {
		long long sum = 0;
		cin >> N;
		for (int i = 0; i < N; i++)	cin >> list[i];

		// 반복문을 사용하여 쌍을 만들어준다
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				sum += gcd(list[i], list[j]);
			}
		}
		cout << sum << "\n";
	}
	return 0;
}