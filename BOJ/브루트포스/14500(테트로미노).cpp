#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector< vector<int> > board;
int tetromino[19][4][2] = {
	{ {0,0}, {0,1}, {0,2}, {0,3} },
	{ {0,0}, {1,0}, {2,0}, {3,0} },

	{ {0,0}, {0,1}, {1,0}, {1,1} },

	{ {0,0}, {1,0}, {2,0}, {2,1} },
	{ {0,0}, {1,0}, {0,1}, {0,2} },
	{ {0,0}, {0,1}, {1,1}, {2,1} },
	{ {0,0}, {1,0}, {1,-1}, {1,-2} },

	{ {0,0}, {1,0}, {2,0}, {2,-1} },
	{ {0,0}, {1,0}, {1,1}, {1,2} },
	{ {0,0}, {0,1}, {1,0}, {2,0} },
	{ {0,0}, {0,1}, {0,2}, {1,2} },

	{ {0,0}, {1,0}, {1,1}, {2,1} },
	{ {0,0}, {0,1}, {1,0}, {1,-1} },

	{ {0,0}, {1,0}, {1,-1}, {2,-1} },
	{ {0,0}, {0,1}, {1,1}, {1,2} },

	{ {0,0}, {0,1}, {0,2}, {1,1} },
	{ {0,0}, {1,0}, {2,0}, {1,-1} },
	{ {0,0}, {1,-1}, {1,0}, {1,1} },
	{ {0,0}, {1,0}, {2,0}, {1,1} }
};

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N, M, max_result = 0;

	cin >> N >> M;
	board.resize(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)	cin >> board[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int m = 0; m < 19; m++) {
				bool ok = true;
				int sum = 0;
				for (int n = 0; n < 4; n++) {
					int Y = i + tetromino[m][n][0];	int X = j + tetromino[m][n][1];
					if (Y < 0 || Y >= N || X < 0 || X >= M) {
						ok = false;
						break;
					}
					sum += board[Y][X];
				}
				if (ok)	max_result = max(max_result, sum);
			}
		}
	}
	cout << max_result << "\n";
	return 0;
}