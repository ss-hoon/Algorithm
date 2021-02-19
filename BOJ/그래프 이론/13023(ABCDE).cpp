#include <iostream>
#include <vector>
using namespace std;
int N, M;
bool visited[2000] = { false };
vector<int> adj[2000];

bool isCorrect(int vertex, int cnt) {
	// 친구 관계가 4개까지 이어진다면
	// 성립하는 것이므로 true 반환
	if (cnt == 4)	return true;

	visited[vertex] = true;
	for (int i = 0; i < adj[vertex].size(); i++) {
		if (visited[adj[vertex][i]])	continue;
		if (isCorrect(adj[vertex][i], cnt + 1))	return true;
	}
	visited[vertex] = false;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int friendA, friendB;
		cin >> friendA >> friendB;
		adj[friendA].push_back(friendB);
		adj[friendB].push_back(friendA);
	}

	for (int i = 0; i < N; i++) {
		if (isCorrect(i, 0)) {
			cout << "1\n";
			break;
		}
		if (i == N - 1)	cout << "0\n";
	}
	return 0;
}