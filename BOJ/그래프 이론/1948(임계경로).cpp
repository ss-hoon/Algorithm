#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector< pair<int, int> > fromTo[10001];
int cache[10001], visit[10001];
int city, edge, start, finish, weight, edgeCnt;

// 최장길이 탐색
void searchMaxPath(int start) {
	for (auto fromToIndex : fromTo[start]) {
		int end = fromToIndex.first;
		int weight = fromToIndex.second;

		if (!cache[end])	searchMaxPath(end);
		cache[start] = max(cache[start], cache[end] + weight);
	}
}

// 경로 탐색
void searchPath(int start) {
	if (visit[start])	return;

	visit[start] = 1;
	for (auto fromToIndex : fromTo[start]) {
		int end = fromToIndex.first;
		int weight = fromToIndex.second;

		if (cache[end] + weight == cache[start]) {
			searchPath(end);
			edgeCnt++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> city >> edge;
	for (int edgeIndex = 0; edgeIndex < edge; edgeIndex++) {
		cin >> start >> finish >> weight;
		fromTo[start].push_back({ finish, weight });
	}
	cin >> start >> finish;

	searchMaxPath(start);
	searchPath(start);

	cout << cache[start] << "\n" << edgeCnt << "\n";
	return 0;
}