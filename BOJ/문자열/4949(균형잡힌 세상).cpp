#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check(string str) {
	stack<char> st;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' || str[i] == '[')	st.push(str[i]);
		else if (str[i] == ')' || str[i] == ']') {
			if (st.empty())	return false;
			else if (st.top() == '(' && str[i] != ')')	return false;
			else if (st.top() == '[' && str[i] != ']')	return false;
			else st.pop();
		}
	}
	if (!st.empty())	return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	string str;
	while (getline(cin, str) && str[0] != '.') {
		if (check(str))	cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}