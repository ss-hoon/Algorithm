#include <iostream>
#include <cstring>
#include <string>
#define MOD 1000000
using namespace std;
int cache[5001];
string str;

int search(int n) {
	if (n == str.size())	return 1;
	if (cache[n] != -1)	return cache[n];

	int sum = 0;

	// 현재 위치 하나만 보는 경우
	// 1 ~ 26 범위가 아니라면 return 0
	// ex) 0, 011 등
	if(str[n] - 48 > 0 && str[n] - 48 <= 26)	sum = (sum + search(n + 1)) % MOD;
	else return 0;

	int num = (str[n] - 48) * 10 + (str[n + 1] - 48);
	// 현재 위치와 그 다음 위치를 보는 경우
	if (num > 0 && n + 1 < str.size() && num >= 1 && num <= 26)	sum = (sum + search(n + 2)) % MOD;
	
	return cache[n] = sum;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	memset(cache, -1, sizeof(cache));

	cin >> str;
	cout << search(0) << "\n";
	return 0;
}