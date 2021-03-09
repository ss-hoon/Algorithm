#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, enter[32001];
vector<int> adj[32001];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int start, end;
		cin >> start >> end;
		adj[start].push_back(end);
		++enter[end];
	}

	// 진입 정점이 없는 정점을 큐에 삽입
	for (int i = 1; i <= N; ++i) {
		if (enter[i] == 0)	q.push(i);
	}

	// 위상정렬 실행
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		// 해당 정점이 선행 정점인 경우 진입 차수를 1개씩 낮춰줌
		for (int i = 0; i < adj[x].size(); ++i)	--enter[adj[x][i]];

		// 진입 차수가 0인 정점을 큐에 삽입
		for (int i = 0; i < adj[x].size(); ++i) {
			int y = adj[x][i];
			if (enter[y] != 0)	continue;

			q.push(y);
		}
		cout << x << " ";
	}
	return 0;
}