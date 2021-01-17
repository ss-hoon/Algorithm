#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> list;

bool check(int num, int query, int strike, int ball) {
	int tmpStrike = 0, tmpBall = 0;
	string NUM = to_string(num);
	string QUERY = to_string(query);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j && NUM[i] == QUERY[j])	tmpStrike++;
			if (i != j && NUM[i] == QUERY[j])	tmpBall++;
		}
	}

	if (strike != tmpStrike || ball != tmpBall)	return false;
	else return true;
}


int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N;
	for (int i = 123; i <= 987; i++) {
		string tmp = to_string(i);
		if(!(tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2] || tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0'))	list.push_back(i);
	}
	cin >> N;
	while (N--) {
		int query, strike, ball;
		cin >> query >> strike >> ball;
		for (auto it = list.begin(); it != list.end();) {
			if (!check((*it), query, strike, ball))	it = list.erase(it);
			else it++;
		}
	}

	cout << list.size() << "\n";
	return 0;
}