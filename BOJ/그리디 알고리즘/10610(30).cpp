#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	string num_str;	int cnt = 0;
	cin >> num_str;
	sort(num_str.begin(), num_str.end(), greater<char>()); // 내림차순으로 정렬
	for (int i = 0; i < num_str.length(); i++)	cnt += num_str[i] - 48; // 각자리수의 합을 구한다
	if (cnt % 3 != 0 || num_str[num_str.length() - 1] - 48 != 0)	cout << "-1"; // 3의 배수이거나 마지막 숫자가 0이 아니면 -1을 출력
	else {
		for (int i = 0; i < num_str.length(); i++)	cout << num_str[i]; // 정렬 되어 있는 상태이므로 첫번째 인덱스부터 그대로 출력
	}
	return 0;
}