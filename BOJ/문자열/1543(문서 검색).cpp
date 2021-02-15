#include <iostream>
#include <string>
using namespace std;
string str, findStr;
int cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	getline(cin, str);
	getline(cin, findStr);

	for (int i = 0; i < str.length(); i++) {
		// 서브 문자열과 찾으려는 문자열을 비교
		// 동일한 경우, cnt를 증가시키고
		// index를 서브 문자열 다음으로 위치시킨다
		if (findStr == str.substr(i, findStr.length())) {
			cnt++;
			i += findStr.length() - 1;
		}
	}
	cout << cnt << "\n";
	return 0;
}