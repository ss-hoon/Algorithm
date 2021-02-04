#include <iostream>
#include <algorithm>
using namespace std;
int N, check, map[10][10], minCost = 10e8;

void traversal(int idx, int cost, int start, int cnt) {
	// 순회 도중 cost가 minCost보다 커진 경우에는 백트래킹
	if (minCost < cost)	return;
	
	// 시작점을 제외한 모든 도시를 방문한 경우
	// 현재 위치에서 시작점으로 갈 수 있는지 확인
	// minCost와 비교하여 둘 중 최소값으로 갱신
	if (cnt == N - 1) {
		if(map[idx][start] != 0)	minCost = min(minCost, cost + map[idx][start]);
		return;
	}

	// 도시 순회
	for (int i = 0; i < N; i++) {
		if (idx != i && start != i && (check | (1 << i)) != check && map[idx][i] != 0) {
			check |= (1 << i);
			traversal(i, cost + map[idx][i], start, cnt + 1);
			check &= ~(1 << i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)	cin >> map[i][j];
	}

	for (int i = 0; i < N; i++)	traversal(i, 0, i, 0);
	cout << minCost << "\n";
	return 0;
}