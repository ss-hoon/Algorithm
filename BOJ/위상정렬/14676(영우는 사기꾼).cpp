#include <iostream>
#include <vector>
using namespace std;
int N, M, K, buildingCnt[100001], enter[100001];
vector<int> adj[100001];

bool game(int type, int building) {

	// 건설
	if (type == 1) {
		// 해당 건물을 짓기 위해
		// 선행적으로 지어져야 할 건물이 지어지지 않은 경우
		if (enter[building] != 0)	return false;
		
		buildingCnt[building]++;
		// 해당 건물이 처음으로 생긴 경우
		// 이 건물이 선행 건물인 건물들의 건설요건 중 하나 감소
		if (buildingCnt[building] == 1) {
			for (int i = 0; i < adj[building].size(); i++)	enter[adj[building][i]]--;
		}
	}
	// 파괴
	else {
		// 현재 해당 건물이 없는 경우
		if (buildingCnt[building] == 0)	return false;

		buildingCnt[building]--;
		// 해당 건물이 현재 없는 경우
		// 이 건물이 선행 건물인 건물들의 건설요건 중 하나 증가
		if (buildingCnt[building] == 0) {
			for (int i = 0; i < adj[building].size(); i++)	enter[adj[building][i]]++;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		adj[start].push_back(end);
		enter[end]++;
	}

	for (int i = 0; i < K; i++) {
		int type, building;
		cin >> type >> building;
		if (!game(type, building)) {
			cout << "Lier!\n";
			break;
		}
		if (i == K - 1)	cout << "King-God-Emperor\n";
	}
	return 0;
}