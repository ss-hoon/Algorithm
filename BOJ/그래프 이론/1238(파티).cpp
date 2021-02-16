#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 10000001
using namespace std;

int N, M, startPoint, result;
vector< pair<int, int> > adjGo[1001], adjBack[1001];
vector<int> distGo(1001), distBack(1001);
priority_queue< pair<int, int> > PQ;

void minPath(vector< pair<int,int> > *adj, vector<int> &dist) {
	while (!PQ.empty()) {
		int start = -PQ.top().second;
		
		for (int i = 0; i < adj[start].size(); i++) {
			pair<int, int> temp = adj[start][i];
			if (dist[start] + temp.second < dist[temp.first]) {
				dist[temp.first] = dist[start] + temp.second;
				PQ.push({ -dist[temp.first], -temp.first });
			}
		}
		PQ.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M >> startPoint;

	for (int i = 0; i < M; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		adjGo[start].push_back({ end, weight });
		adjBack[end].push_back({ start, weight });
	}

	for (int i = 1; i <= N; i++) {
		if (i != startPoint) {
			distGo[i] = distBack[i] = INF;
		}
	}

	// 정방향 다익스트라
	PQ.push({ 0, -startPoint});
	minPath(adjGo, distGo);

	// 역방향 다익스트라
	PQ.push({ 0, -startPoint });
	minPath(adjBack, distBack);

	for (int i = 1; i <= N; i++) {
		result = max(result, distGo[i] + distBack[i]);
	}
	cout << result << "\n";
	return 0;
}