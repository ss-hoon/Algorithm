#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
void bfs(vector<bool> &check, vector< vector<int> > &graph) {
	while (!q.empty()) {
		for (int i = 0; i < graph[q.front()].size(); i++) {
			if (check[graph[q.front()][i]] == false) {
				check[graph[q.front()][i]] = true;
				q.push(graph[q.front()][i]);
			}
		}
		q.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N, M, cnt = 0;
	cin >> N >> M;
	vector<bool> check(N + 1, false);
	vector< vector<int> > graph(N + 1);

	for (int i = 0; i < M; i++) {
		int edge1, edge2;
		cin >> edge1 >> edge2;
		graph[edge1].push_back(edge2);
		graph[edge2].push_back(edge1);
	}

	for (int i = 1; i <= N; i++) {
		if (check[i] == false) {
			q.push(i);
			bfs(check, graph);
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}