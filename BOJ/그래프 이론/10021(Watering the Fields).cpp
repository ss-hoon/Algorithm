#include <iostream>
#include <vector>
#include <queue>
#define INF 2000000001
using namespace std;
int N, C, cnt, result, dist[2001], visit[2001];
vector< pair<int, int> > pipe;
priority_queue < pair<int, int> > pq;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int y, x;
		cin >> y >> x;
		pipe.push_back({ y, x });
		dist[i] = INF;
	}

	dist[0] = 0;
	pq.push({ 0, 0 });

	// Dijkstra Algorithm
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		if (dist[pos] < cost || visit[pos])	continue;
		visit[pos] = 1;
		cnt++;
		result += cost;

		for (int i = 0; i < N; i++) {
			if (i == pos)	continue;

			int y = pipe[i].first - pipe[pos].first;	int x = pipe[i].second - pipe[pos].second;
			int tmp = y * y + x * x;

			if (tmp < C || dist[i] <= tmp || visit[i])	continue;
			pq.push({ -tmp, i });
			dist[i] = tmp;
		}
	}
	if (cnt != N)	cout << "-1\n";
	else cout << result << "\n";
	return 0;
}