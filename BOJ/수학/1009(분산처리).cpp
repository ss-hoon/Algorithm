#include <iostream>
#include <cmath>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int test; // 테스트 수
	cin >> test;
	while (test--) {
		int a, b; // a는 밑, b는 지수
		cin >> a >> b;
		if (a % 10 == 0)	cout << "10\n"; // 10의 배수일 경우 10 출력
		else { // 10의 배수가 아닌 경우
			a %= 10; // a를 10으로 나눈 나머지의 값으로 대체
			if (b % 4 != 0)	b %= 4; // b가 4의 배수가 아닌 경우 b를 4로 나눈 나머지의 값으로 대체
			else b = 4; // b가 4의 배수인 경우 b를 4로 대체
			cout << (int)(pow(a, b)) % 10 << "\n"; // a의 b승 값을 10으로 나눈 나머지의 값을 출력
		}
	}
	return 0;
}