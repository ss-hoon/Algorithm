#include <iostream>
#include <cstring>
using namespace std;
int cache[2001][2001], list[2001];

int palindrome(int start, int end) {
	int &ret = cache[start][end];
	if (ret != -1)	return ret;

	// 부분수열이 짝수인 경우에는 (3,3), (4,4)와 같이 start와 end가 겹치는 일이 발생하지 않으므로 예외처리
	if (end - start == 1) { 
		if (list[start] == list[end])	return ret = 1;
		else return ret = 0;
	}

	// 팰린드롬인지 알기위한 조건
	// 1. start + 1 요소부터 end - 1요소까지 팰린드롬인지 확인
	// 2. start 요소와 end 요소가 같은지 확인
	// 두 조건이 만족하지 않는 경우 팰린드롬 X
	if (palindrome(start + 1, end - 1) && list[start] == list[end])	return ret = 1; 
	else return ret = 0;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	memset(cache, -1, sizeof(cache));
	int N, T;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		cache[i][i] = 1; // start와 end가 같은 경우는 무조건 팰린드롬
	}

	cin >> T;
	while (T--) {
		int start, end;
		cin >> start >> end;
		if (palindrome(start, end))	cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}