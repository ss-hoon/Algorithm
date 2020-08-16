#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int map[8][8] = {};
int map_temp[8][8] = {};
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int row, col, temp_virus = 0, min_virus = 65;
vector <pair<int,int> > virus_first;
queue <pair<int, int> > virus;
void set_map() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)	map_temp[i][j] = map[i][j];
	}
}
void infest_virus() {
	while (!virus.empty()) {
		for (int i = 0; i < 4; i++) {
			if (virus.front().first + dx[i] < 0 || virus.front().first + dx[i] > row - 1 || virus.front().second + dy[i] < 0 || virus.front().second + dy[i] > col - 1)	continue;
			if (map_temp[virus.front().first + dx[i]][virus.front().second + dy[i]] != 0)	continue;
			map_temp[virus.front().first + dx[i]][virus.front().second + dy[i]] = 2;
			virus.push(make_pair(virus.front().first + dx[i], virus.front().second + dy[i]));
			temp_virus++;
		}
		virus.pop();
	}
}
void protect(int x, int y, int cnt) {
	if (cnt == 3) {
		set_map();
		for (int i = 0; i < virus_first.size(); i++)	virus.push(make_pair(virus_first[i].first, virus_first[i].second));
		infest_virus();
		min_virus = min(min_virus, temp_virus);
		temp_virus = 0;
		return;
	}
	for (int i = x; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i == x && j == 0)	j = y;
			if (map[i][j] != 0)	continue;
			map[i][j] = 1;
			protect(i, j+1,cnt + 1);
			map[i][j] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int wall = 0;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)	wall++;
			else if (map[i][j] == 2)	virus_first.push_back(make_pair(i, j));
		}
	}
	protect(0,0,0);
	cout << row * col - wall - 3 - virus_first.size() - min_virus << "\n";
	return 0;
}