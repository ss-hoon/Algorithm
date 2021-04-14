#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector< vector<int> > adj, scc;
stack<int> st;
int visit[10001], isFinish[10001], V, E, idx, total;

bool cmp(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

int dfs(int n) {
	visit[n] = ++idx;
	int ret = visit[n];
	st.push(n);

	for (int next : adj[n]) {

		// 다음 정점이 방문하지 않은 경우
		// DFS 순회해서 그 중 최소값을 ret에 입력
		if (visit[next] == 0)
			ret = min(ret, dfs(next));

		// 다음 정점이 방문했고, SCC 순회가 끝나지 않은 경우
		// DFS 순회를 멈추고 최소값을 ret에 입력
		else if (isFinish[next] == 0)
			ret = min(ret, visit[next]);
	}

	if (ret == visit[n]) {
		scc.resize(++total);

		// 스택의 top이 현재 정점과 같을 때까지
		// 스택 pop 하여 SCC로 묶어준다
		while (1) {
			int top = st.top();
			st.pop();
			scc[total - 1].push_back(top);
			isFinish[top] = 1;

			if (top == n)	break;
		}
		sort(scc[total - 1].begin(), scc[total - 1].end());
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> V >> E;
	adj.resize(V + 1);

	for (int i = 0; i < E; i++) {
		int start, end;
		cin >> start >> end;
		adj[start].push_back(end);
	}

	for (int i = 1; i <= V; i++) {
		if (visit[i])	continue;

		dfs(i);
	}
	sort(scc.begin(), scc.end(), cmp);

	cout << total << "\n";
	for (auto list : scc) {
		for (int element : list) {
			cout << element << " ";
		}
		cout << "-1\n";
	}
	return 0;
}