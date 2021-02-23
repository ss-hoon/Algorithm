#include <iostream>
#include <string>
using namespace std;
int N, K, cnt[21], nameLength[300000];
long long result;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		
		// 현재 윈도우 범위의 문자열 길이 인덱스 값 증가
		result += cnt[(nameLength[i] = name.length())]++;
		if (i < K)	continue;

		// 현재 윈도우 범위 밖의 문자열 길이 인덱스 값 감소
		cnt[nameLength[i - K]]--;
	}

	cout << result << "\n";
	return 0;
}