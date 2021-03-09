#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, enter[501], finish[501], cache[501];
vector<int> adj[501];
priority_queue< pair<int, int> > pq;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		int next;
		cin >> finish[i];
		while (cin >> next && next != -1) {
			adj[next].push_back(i);
			++enter[i];
		}
	}

	// 진입 정점이 없는 정점을 큐에 삽입
	for (int i = 1; i <= N; ++i) {
		if (enter[i] == 0)	pq.push({ -finish[i], i });
	}

	// 위상정렬 실행
	while (!pq.empty()) {
		int time = -pq.top().first;
		int v = pq.top().second;
		// 해당 건물이 지어지는데 걸린 시간을 메모이제이션
		cache[v] = time;
		pq.pop();

		// 해당 정점이 선행 정점인 경우 진입 차수를 1개씩 낮춰줌
		// 진입 차수가 0인 정점을 큐에 삽입
		for (int it : adj[v]) {
			--enter[it];
			if (enter[it] == 0)	pq.push({ -(time + finish[it]), it });
		}
	}

	for (int i = 1; i <= N; ++i)	cout << cache[i] << "\n";
	return 0;
}