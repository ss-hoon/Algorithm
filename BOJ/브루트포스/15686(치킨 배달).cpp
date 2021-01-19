#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 99999999
using namespace std;
vector< pair<int, int> > house, chicken;
int N, M, chickenDistance = MAX;

void search(int idx, int cnt, vector< pair<int,int> > &list) {
	if (cnt == M) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int tmp = MAX;
			for (int j = 0; j < list.size(); j++) {
				tmp = min(tmp, abs(house[i].first - list[j].first) + abs(house[i].second - list[j].second));
			}
			sum += tmp;
		}
		chickenDistance = min(chickenDistance, sum);
		return;
	}
	
	if (idx < chicken.size()) {
		list.push_back({ chicken[idx].first, chicken[idx].second });
		search(idx + 1, cnt + 1, list);
		list.pop_back();

		search(idx + 1, cnt, list);
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	vector< pair<int, int> > list;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int map;
			cin >> map;
			if (map == 1)	house.push_back({ i,j });
			else if (map == 2)	chicken.push_back({ i,j });
		}
	}
	search(0, 0, list);
	cout << chickenDistance << "\n";
	return 0;
}