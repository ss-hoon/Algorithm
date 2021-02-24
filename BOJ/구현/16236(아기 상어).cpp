#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 20
using namespace std;

struct dir {
	int y, x, size;
};

struct go {
	int y, x, time;
};

struct cmpGo {
	bool operator()(go &a, go &b) {
		if (a.time == b.time) {
			if (a.y == b.y)	return a.x > b.x;
			return a.y > b.y;
		}
		return a.time > b.time;
	}
};

int N, eatFish, map[MAX][MAX], visited[MAX][MAX];
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
dir shark; // 아기 상어의 현재 상태

int BFS() {
	int result = 0;
	while (1) {
		priority_queue<go, vector<go>, cmpGo> fish;
		priority_queue<go, vector<go>, cmpGo> pass;
		memset(visited, 0, sizeof(visited));
		visited[shark.y][shark.x] = 1;

		pass.push({ shark.y, shark.x, 0 });
		// BFS 실행
		while (!pass.empty()) {
			int y = pass.top().y;
			int x = pass.top().x;
			int time = pass.top().time;
			pass.pop();

			// 상하좌우 모든 방향을 탐색하여 
			// 조건에 맞는 경우 pass 우선순위 큐에 input
			for (int i = 0; i < 4; i++) {
				int Y = y + dy[i];
				int X = x + dx[i];
				if (Y < 0 || Y >= N || X < 0 || X >= N || map[y][x] > shark.size || visited[Y][X])	continue;
				
				visited[Y][X] = 1;
				pass.push({ Y, X, time + 1 });
				if (1 <= map[Y][X] && map[Y][X] < shark.size)	fish.push({ Y, X, time + 1 });
			}
		}

		// 후보 물고기가 있는 경우
		// 우선순위 큐에서 나온 물고기를 선택
		if (!fish.empty()) {
			int y = fish.top().y;
			int x = fish.top().x;
			int time = fish.top().time;

			eatFish++;
			map[y][x] = 0;
			if (eatFish == shark.size) {
				eatFish = 0;
				shark.size++;
			}

			shark.y = y;
			shark.x = x;
			result += time;
		}
		// 후보 물고기가 없는 경우
		// 더이상 먹을 물고기가 없다고 판단하여 종료
		else break;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				map[i][j] = 0;
				shark = { i, j, 2 };
			}
		}
	}
	cout << BFS() << "\n";
	return 0;
}