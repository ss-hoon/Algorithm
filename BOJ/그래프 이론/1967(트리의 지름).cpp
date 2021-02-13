#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector< pair<int, int> > adj[100001];
int N, longDist, result = 0;

void dfs(int x, vector<bool> &visited, int sum) {
	bool ok = false;
	visited[x] = true;
	for (int i = 0; i < adj[x].size(); i++) {
		if (visited[adj[x][i].first] == true)	continue;

		dfs(adj[x][i].first, visited, sum + adj[x][i].second);
		ok = true;
	}

	if (!ok) {
		if (result < sum) {
			result = sum;
			longDist = x;
		}
	}
	visited[x] = false;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int parent, child, weight;
		cin >> parent >> child >> weight;

		adj[parent].push_back({ child, weight });
		adj[child].push_back({ parent, weight });
	}

	vector<bool> visited(N + 1, false);
	// 임의의 정점에서 가장 먼 정점을 찾는다
	// 그 정점에서 가장 먼 정점까지의 거리가 트리의 지름
	dfs(1, visited, 0);
	dfs(longDist, visited, 0);
	cout << result << "\n";
	return 0;
}