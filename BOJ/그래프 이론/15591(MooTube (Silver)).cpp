#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector< pair<int, int> > adj[5001];
vector<bool> check;
queue<int> q;
int N, Q, K, V, cnt;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> Q;
	for (int i = 0; i < N - 1; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		adj[p].push_back({ q, r });
		adj[q].push_back({ p, r });
	}

	while(Q--) {
		cin >> K >> V;
		check.resize(N + 1, false);
		cnt = 0;
		q.push(V);

		while (!q.empty() && cnt < N - 1) {
			int idx = q.front();

			if (check[idx])	q.pop();
			else {
				check[idx] = true;

				for (int j = 0; j < adj[idx].size(); j++) {
					// K 가중치보다 작은 가중치는 더 뻗어나갈 필요 없음
					if (check[adj[idx][j].first] || adj[idx][j].second < K)	continue;

					q.push(adj[idx][j].first);
					cnt++;
				}
				q.pop();
			}
		}
		cout << cnt << "\n";
		check.clear();
		while (!q.empty())	q.pop();
	}
	return 0;
}