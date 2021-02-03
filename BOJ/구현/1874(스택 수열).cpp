#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int N, num, ptr = 1;
stack<int> st;
vector<char> result;

bool isPossible(int num) {

	// push될 값(ptr)보다 입력된 num 값이 큰 경우에는 stack push
	while (num >= ptr) {
		st.push(ptr++);
		result.push_back('+');
	}

	// 반복문이 끝난 후, stack의 top 값은 num 값과 동일해야함
	if (st.top() != num)	return false;
	else {
		st.pop();
		result.push_back('-');
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (!isPossible(num)) {
			result.clear();
			break;
		}
	}

	if (result.empty())	cout << "NO\n";
	else {
		for (int i = 0; i < result.size(); i++)	cout << result[i] << "\n";
	}
	return 0;
}