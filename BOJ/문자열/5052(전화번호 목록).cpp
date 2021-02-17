#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int T, N;

bool isConsist(vector<string> &phone) {
	for (int i = 1; i < N; i++) {
		if (phone[i - 1] == phone[i].substr(0, phone[i - 1].length()))	return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N;
		vector<string> phone(N);
		for (int i = 0; i < N; i++) {
			cin >> phone[i];
		}
		sort(phone.begin(), phone.end());
		if (isConsist(phone))	cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}