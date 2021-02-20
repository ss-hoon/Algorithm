#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct infection{
	int y, x, time;
};

int N, M, unit, map[50][50], minTime = 99999;
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };
vector<int> selected;
vector< pair<int, int> > virus;
vector< vector<int> > visit, visited;
queue<infection> que;

void BFS() {
	int cnt = 0;
	int temp = 0;
	bool check = false;
	while (!que.empty()) {
		int y = que.front().y;
		int x = que.front().x;
		int time = que.front().time;

		// 상하좌우 BFS
		for (int i = 0; i < 4; i++) {
			int Y = y + dy[i];
			int X = x + dx[i];
			if (Y < 0 || Y >= N || X < 0 || X >= N || visit[Y][X])	continue;
			visit[Y][X] = 1;
			temp = max(temp, time + 1);
			que.push({ Y, X, time + 1 });
			cnt++;

			// 모두 채웠을 경우 시간을 최종 시간과 비교
			// 둘 중 최소시간을 최종시간에 갱신
			if (cnt == unit) {
				minTime = min(minTime, temp);
				check = true;
				break;
			}
		}
		if (check)	break;
		que.pop();
	}
	while (!que.empty())	que.pop();
}

void selectVirus(int idx, int cnt) {
	if (cnt == M) {
		visit.resize(N, vector<int>(N));
		copy(visited.begin(), visited.end(), visit.begin());
		for (int i = 0; i < selected.size(); i++) {
			que.push({ virus[selected[i]].first, virus[selected[i]].second, 0 });
			visit[virus[selected[i]].first][virus[selected[i]].second] = 1;
		}
		BFS();
		return;
	}

	for (int i = idx; i < virus.size(); i++) {
		selected.push_back(i);
		selectVirus(i + 1, cnt + 1);
		selected.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	visited.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				visited[i][j] = 1;
				unit++;
			}
			if (map[i][j] == 2)	virus.push_back({ i, j });
		}
	}

	unit = N * N - unit - M;

	if (unit == 0)	cout << "0\n";
	else {
		selectVirus(0, 0);
		cout << (minTime == 99999 ? -1 : minTime) << "\n";
	}
	return 0;
}