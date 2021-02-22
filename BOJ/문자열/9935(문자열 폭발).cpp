#include <iostream>
#include <string>
using namespace std;
string str, bomb, result;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> str >> bomb;
	int strSize = str.length(), bombSize = bomb.length();

	for (int i = 0; i < strSize; i++) {
		result += str[i];
		
		// 폭발 문자열의 끝자리 문자가 들어온 경우
		if (str[i] == bomb[bombSize - 1]) {
			int start = result.length() - bombSize;
			if (start < 0 || result.empty())	continue;

			// 뒤에서 폭발 문자열 길이만큼 잘라서 폭발 문자열과 비교
			// 같으면 결과 문자열에서 폭발 문자열 길이만큼 뒤에서 삭제
			if (bomb == result.substr(start, bombSize)) {
				for (int j = 0; j < bombSize; j++)	result.pop_back();
			}
		}
	}
	if (result.empty())	cout << "FRULA\n";
	else cout << result << "\n";
	return 0;
}