#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000001
using namespace std;
int N, M, start, finish, cost, check[1001], dist[1001];
priority_queue< pair<int, int> > pq;
vector< pair<int, int> > adj[1001];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)	dist[i] = INF;

	while (M--) {
		cin >> start >> finish >> cost;

		adj[start].push_back({ finish, cost });
	}

	cin >> start >> finish;
	dist[start] = 0;
	pq.push({ 0, start });

	// dijkstra Algorithm
	while (!pq.empty()) {
		int pos = pq.top().second;
		pq.pop();

		if (check[pos]) continue;
		check[pos] = 1;

		for (auto i : adj[pos]) {
			int e = i.first;
			int w = i.second;

			if (dist[pos] + w < dist[e]) {
				dist[e] = dist[pos] + w;
				pq.push({ -dist[e], e });
			}
		}
	}
	cout << dist[finish] << "\n";
	return 0;
}