#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct que_info {
	int y, x, day;
};

int M, N, today = 0, cnt = 0, sum = 0;
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
vector< vector<int> > tomato;
vector< vector<bool> > check;
queue<que_info> que;

void bfs() {
	while (!que.empty() && que.front().day == today - 1) {
		int y = que.front().y;	int x = que.front().x;
		cnt++;
		for (int i = 0; i < 4; i++) {
			int Y = y + dy[i];	int X = x + dx[i];
			if ((Y >= 0 && Y < N && X >= 0 && X < M) && !check[Y][X] && tomato[Y][X] != -1) {
				check[Y][X] = true;
				que.push({ Y, X, today });
			}
		}
		que.pop();
		if(!que.empty() && que.front().day == today)	
			today++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> M >> N;
	tomato.resize(N, vector<int>(M, 0));
	check.resize(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				check[i][j] = true;
				que.push({ i, j, -1 });
			}
			
			if(tomato[i][j] != -1)	sum++;
		}
	}

	bfs();

	if(cnt == sum)	cout << today << "\n";
	else cout << "-1\n";
	return 0;
}