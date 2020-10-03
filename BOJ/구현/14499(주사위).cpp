#include <iostream>
#include <vector>
using namespace std;
int dice_row[4] = { 0,0,0,0 }; // 북 -> 남
int dice_col[4] = { 0,0,0,0 };  // 서 -> 동
int dx[5] = { 0, 1, -1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };
int M, N, X, Y, K;

void play(int command, vector<vector<int> > &board) {
	if (X + dx[command] < 0 || Y + dy[command] < 0 || X + dx[command] >= N || Y + dy[command] >= M)	return;

	X += dx[command];
	Y += dy[command];

	switch (command) {
		int temp;
	case 1: // 동
		temp = dice_col[3];
		for (int i = 3; i >= 1; i--)	dice_col[i] = dice_col[i - 1];
		dice_col[0] = temp;
		dice_row[0] = dice_col[0];
		dice_row[2] = dice_col[2];
		break;
	case 2: // 서
		temp = dice_col[0];
		for (int i = 0; i < 3; i++)	dice_col[i] = dice_col[i + 1];
		dice_col[3] = temp;
		dice_row[0] = dice_col[0];
		dice_row[2] = dice_col[2];
		break;
	case 3: // 북
		temp = dice_row[0];
		for (int i = 0; i < 3; i++)	dice_row[i] = dice_row[i + 1];
		dice_row[3] = temp;
		dice_col[0] = dice_row[0];
		dice_col[2] = dice_row[2];
		break;
	case 4: // 남
		temp = dice_row[3];
		for (int i = 3; i >= 1; i--)	dice_row[i] = dice_row[i - 1];
		dice_row[0] = temp;
		dice_col[0] = dice_row[0];
		dice_col[2] = dice_row[2];
		break;
	}
	
	if (board[Y][X] == 0)	board[Y][X] = dice_row[2];
	else {
		dice_row[2] = board[Y][X];
		dice_col[2] = board[Y][X];
		board[Y][X] = 0;
	}
	cout << dice_row[0] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> M >> N >> Y >> X >> K;
	vector<vector<int> > board(M, vector<int>(N, 0));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)	cin >> board[i][j];
	}
	while (K--) {
		int command;
		cin >> command;
		play(command, board);
	}
	return 0;
}