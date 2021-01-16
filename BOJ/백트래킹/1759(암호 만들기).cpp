#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string alpha;
int L, C, checkAlpha[2] = { 0, 0 };

bool check(string str) {
	int mo = 0; int ja = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')	mo++;
		else ja++;
	}

	if (mo + checkAlpha[0] >= 1 && ja + checkAlpha[1] >= 2)	return true;
	else return false;
}

void search(string word, int idx) {
	if (idx > C)	return;
	if (word.length() == L) {
		if (checkAlpha[0] >= 1 && checkAlpha[1] >= 2) {
			for (char tmp : word)	cout << tmp;
			cout << "\n";
		}
		return;
	}

	if (check(alpha.substr(idx, C - idx))) {
		switch (alpha[idx]) {
		case 'a': case 'e': case 'i': case 'o': case 'u':
			checkAlpha[0]++;
			break;
		default:
			checkAlpha[1]++;
			break;
		}

		search(word + alpha[idx], idx + 1);

		switch (alpha[idx]) {
		case 'a': case 'e': case 'i': case 'o': case 'u':
			checkAlpha[0]--;
			break;
		default:
			checkAlpha[1]--;
			break;
		}

		search(word, idx + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> L >> C;
	alpha.resize(C);
	for (int i = 0; i < C; i++)	cin >> alpha[i];
	sort(alpha.begin(), alpha.end());

	search("", 0);
	return 0;
}