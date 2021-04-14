#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> adj[10001], rev_adj[10001];
vector< vector<int> > scc;
stack<int> st;
int V, E, idx, visit[10001];

bool cmp(vector<int> &a, vector<int> &b) {
	return a[0] < b[0];
}

// 순방향 DFS
void dfs(int n) {
	visit[n] = 1;

	for (int next : adj[n]) {
		if (visit[next])	continue;

		dfs(next);
	}
	// DFS가 끝나면 스택에 해당 정점 추가
	st.push(n);
}

// 역방향 DFS
void rev_dfs(int n) {
	visit[n] = 1;
	scc[idx - 1].push_back(n);

	for (int next : rev_adj[n]) {
		if (visit[next])	continue;

		rev_dfs(next);
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> V >> E;

	// 순방향, 역방향 그래프 입력
	for (int i = 0; i < E; i++) {
		int start, end;
		cin >> start >> end;
		adj[start].push_back(end);
		rev_adj[end].push_back(start);
	}

	// 모든 정점에 대해 순방향 DFS
	for (int i = 1; i <= V; i++) {
		if (visit[i])	continue;
		dfs(i);
	}
	
	memset(visit, 0, sizeof(visit));
	// 스택이 빌 때까지 반복하며 역방향 DFS
	while (!st.empty()) {
		int top = st.top();
		st.pop();

		if (visit[top])	continue;
		scc.resize(++idx);
		rev_dfs(top);
	}
	
	// 정렬
	for (auto &list : scc) {
		sort(list.begin(), list.end());
	}
	sort(scc.begin(), scc.end(), cmp);

	// 출력
	cout << scc.size() << "\n";
	for (auto list : scc) {
		for (int element : list) {
			cout << element << " ";
		}
		cout << "-1\n";
	}
	return 0;
}