#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 200001
using namespace std;

struct info {
	int start, weight;
};

struct cmp {
	bool operator()(info &a, info &b) {
		if (a.weight == b.weight)	return a.start > b.start;
		return a.weight > b.weight;
	}
};

int V, E, startPoint;
vector< pair<int, int> > adj[20001];
vector<int> path(20001, 0);
priority_queue<info, vector<info>, cmp> PQ;

void minPath() {
	while (!PQ.empty()) {
		int start = PQ.top().start;

		// 우선순위 큐를 통해 최소 가중치를 가져오고
		// path를 그때마다 갱신
		// 큐가 빌 때까지 반복한다
		for (int i = 0; i < adj[start].size(); i++) {
			pair<int, int> temp = adj[start][i];
			if (path[start] + temp.second < path[temp.first]) {
				path[temp.first] = path[start] + temp.second;
				PQ.push({ temp.first, path[temp.first] });
			}
		}

		PQ.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> V >> E >> startPoint;

	while (E--) {
		int start, end, weight;
		cin >> start >> end >> weight;
		adj[start].push_back({ end, weight });
	}

	for (int i = 1; i <= V; i++) {
		if(i != startPoint)	path[i] = INF;
		else PQ.push({i, path[i]});
	}

	minPath();
	for (int i = 1; i <= V; i++) {
		if (path[i] == INF)	cout << "INF\n";
		else cout << path[i] << "\n";
	}
	return 0;
}