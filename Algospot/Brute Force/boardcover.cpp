#include <iostream>
#include <cstring>
using namespace std;

int block[4][3][2] = { // ���� ������ �� �ִ� ����� ��
	{{0,0}, {0,1}, {1,0}}, 
	{{0,0}, {0,1}, {1,1}},
	{{0,0}, {1,0}, {1,1}},
	{{0,0}, {1,-1}, {1,0}}
};
int row, col; // ��� �� ����
int board[20][20] = { 0, };

bool isOK(int y, int x, int type, int delta) { // �ش� ���� �� �� �ִ��� �Ǻ�
	bool check = true;
	for (int i = 0; i < 3; i++) {
		int dy = y + block[type][i][0];
		int dx = x + block[type][i][1];
		if (dy < 0 || dx < 0 || dy >= row || dx >= col)	return false;
		else if ((board[dy][dx] += delta) > 1)	check = false;
	}
	return check;
}

int cover() { // �������� ��� ���� �� �ִ� ����� ��
	int y = -1, x = -1;
	for (int row_index = 0; row_index < row; row_index++) {
		for (int col_index = 0; col_index < col; col_index++) {
			if (!board[row_index][col_index]) {
				y = row_index;
				x = col_index;
				break;
			}
		}
		if (y != -1 && x != -1)	break;
	}

	if (y == -1 && x == -1)	return 1; // �� ä���� ����̹Ƿ� 1 ��ȯ
	int sum = 0;
	for (int type = 0; type < 4; type++) {
		if (isOK(y, x, type, 1))	sum += cover();
		isOK(y, x, type, -1);
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int test;
	cin >> test;
	while (test--) {
		cin >> row >> col;
		memset(board, 0, sizeof(board));
		for (int row_index = 0; row_index < row; row_index++) {
			for (int col_index = 0; col_index < col; col_index++) {
				char temp;
				cin >> temp;
				if (temp == '#')	board[row_index][col_index] = 1;
				else board[row_index][col_index] = 0;
			}
		}
		cout << cover() << "\n";
	}
}