#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

double avg(vector<int> &list) {
	double result = 0;
	for (int i = 0; i < list.size(); i++)	result += list[i];

	return floor(result / list.size() + 0.5);
}

int mid(vector<int> &list) {
	sort(list.begin(), list.end());

	return list[list.size() / 2];
}

int maxCnt(vector<int> &list) {
	map<int, int> m;
	int max_cnt = 1, result;
	bool check = false;

	for (int i = 0; i < list.size(); i++) {
		auto it = m.find(list[i]);
		if (it != m.end()) {
			it->second++;
			max_cnt = max(max_cnt, it->second);
		}
		else m.insert({ list[i], 1 });
	}
	
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second == max_cnt) {
			if (check) {
				result = it->first;
				break;
			}
			else {
				check = true;
				result = it->first;
			}
		}
	}

	return result;
}

int diff(vector<int> &list) {
	int maxNum = -4001, minNum = 4001;
	for (int i = 0; i < list.size(); i++) {
		maxNum = max(maxNum, list[i]);
		minNum = min(minNum, list[i]);
	}

	return maxNum - minNum;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> list(N);

	for (int i = 0; i < N; i++)	cin >> list[i];
	
	cout << avg(list) << "\n" << mid(list) << "\n" << maxCnt(list) << "\n" << diff(list) << "\n";	
	return 0;
}