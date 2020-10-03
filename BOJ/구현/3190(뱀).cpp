#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N, K, L, sec = 0;
	cin >> N >> K;
	vector<vector<int> > board(N + 1, vector<int>(N + 1, 0));
	queue<pair<int, int> > snake;
	snake.emplace(1, 1);

	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> y >> x;
		board[y][x] = 2;
	}

	cin >> L;
	queue<pair<int, char> > info;
	for (int i = 0; i < L; i++) {
		int X;	char C;
		cin >> X >> C;
		info.emplace(X, C);
	}

	board[1][1] = 1;
	char direction = 'R';
	int x = 1, y = 1;
	while (1) {
		sec++;
		if (direction == 'R') {
			if (x + 1 > N || board[y][x + 1] == 1)	break;

			if (board[y][x + 1] == 2) {
				board[y][x + 1] = 1;
				snake.emplace(y, x + 1);
			}
			else {
				board[y][x + 1] = 1;
				board[snake.front().first][snake.front().second] = 0;
				snake.pop();
				snake.emplace(y, x + 1);
			}
			x++;
		}
		else if (direction == 'D') {
			if (y + 1 > N || board[y + 1][x] == 1)	break;

			if (board[y + 1][x] == 2) {
				board[y + 1][x] = 1;
				snake.emplace(y + 1, x);
			}
			else {
				board[y + 1][x] = 1;
				board[snake.front().first][snake.front().second] = 0;
				snake.pop();
				snake.emplace(y + 1, x);
			}
			y++;
		}
		else if (direction == 'L') {
			if (x - 1 <= 0 || board[y][x - 1] == 1)	break;

			if (board[y][x - 1] == 2) {
				board[y][x - 1] = 1;
				snake.emplace(y, x - 1);
			}
			else {
				board[y][x - 1] = 1;
				board[snake.front().first][snake.front().second] = 0;
				snake.pop();
				snake.emplace(y, x - 1);
			}
			x--;
		}
		else {
			if (y - 1 <= 0 || board[y - 1][x] == 1)	break;

			if (board[y - 1][x] == 2) {
				board[y - 1][x] = 1;
				snake.emplace(y - 1, x);
			}
			else {
				board[y - 1][x] = 1;
				board[snake.front().first][snake.front().second] = 0;
				snake.pop();
				snake.emplace(y - 1, x);
			}
			y--;
		}

		if (!info.empty() && info.front().first == sec) {
			if (direction == 'R' && info.front().second == 'D')	direction = 'D';
			else if (direction == 'R' && info.front().second == 'L')	direction = 'U';
			else if (direction == 'D' && info.front().second == 'D')	direction = 'L';
			else if (direction == 'D' && info.front().second == 'L')	direction = 'R';
			else if (direction == 'L' && info.front().second == 'D')	direction = 'U';
			else if (direction == 'L' && info.front().second == 'L')	direction = 'D';
			else if (direction == 'U' && info.front().second == 'D')	direction = 'R';
			else if (direction == 'U' && info.front().second == 'L')	direction = 'L';
			info.pop();
		}
	}
	cout << sec << "\n";
	return 0;
}