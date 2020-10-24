#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<bool> &check, vector< vector<int> > &graph, int num) {
	check[num] = true;
	for (int i = 0; i < graph[num].size(); i++) {
		if (check[graph[num][i]] == false) {
			dfs(check, graph, graph[num][i]);
		}
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
			dfs(check, graph, i);
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}