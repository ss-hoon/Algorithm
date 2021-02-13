#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector< pair<int, int> > adj[100001];
int V, longDist, result = 0;

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
	cin >> V;

	for (int i = 0; i < V; i++) {
		int num, vertex, weight;
		cin >> num;
		while (cin >> vertex && vertex != -1 && cin >> weight) {
			adj[num].push_back({ vertex, weight });
		}
	}

	vector<bool> visited(V + 1, false);
	// 임의의 정점에서 가장 먼 정점을 찾는다
	// 그 정점에서 가장 먼 정점까지의 거리가 트리의 지름
	dfs(1, visited, 0);
	dfs(longDist, visited, 0);
	cout << result << "\n";
	return 0;
}