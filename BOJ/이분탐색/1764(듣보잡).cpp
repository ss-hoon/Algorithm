#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> nonListen;
vector<string> nonSee;
vector<string> nonList;

void binary_search(int start, int end, string name) {
	if (start == end) {
		if (nonListen[start] == name) nonList.push_back(name);
		return;
	}

	int mid = (start + end) / 2;
	if (name <= nonListen[mid])	binary_search(start, mid, name);
	else binary_search(mid + 1, end, name);
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N, M;
	string name;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> name;
		nonListen.push_back(name);
	}

	for (int i = 0; i < M; i++) {
		cin >> name;
		nonSee.push_back(name);
	}

	sort(nonListen.begin(), nonListen.end());
	sort(nonSee.begin(), nonSee.end());

	for (int i = 0; i < M; i++)	binary_search(0, N - 1, nonSee[i]);

	cout << nonList.size() << "\n";
	for (int i = 0; i < nonList.size(); i++)	cout << nonList[i] << "\n";
	return 0;
}