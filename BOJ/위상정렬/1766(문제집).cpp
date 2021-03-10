#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[32001];
priority_queue<int> firstWork;
int work, info, enter[32001];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> work >> info;
	for (int infoIndex = 0; infoIndex < info; infoIndex++) {
		int before, after;
		cin >> before >> after;
		adj[before].push_back(after);
		enter[after]++;
	}

	// 진입 정점이 없으면 우선순위 큐에 삽입
	for (int enterIndex = 1; enterIndex <= work; enterIndex++) {
		if (enter[enterIndex] == 0) {
			firstWork.push(-enterIndex);
		}
	}

	// 위상정렬 알고리즘
	while (!firstWork.empty()) {
		int vertex = -firstWork.top();
		firstWork.pop();

		for (int nextVertex : adj[vertex]) {
			enter[nextVertex]--;

			// 진입 정점이 없으면 우선순위 큐에 삽입
			if (enter[nextVertex] == 0) {
				firstWork.push(-nextVertex);
			}
		}
		cout << vertex << " ";
	}
	return 0;
}