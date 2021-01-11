#include <iostream>
using namespace std;
int field[50][50] = {};
int dx[4] = { 0,-1,1,0 };	int dy[4] = { -1,0,0,1 }; // �����¿� x��ǥ, y��ǥ
int row, col, seed, row_seed, col_seed, cnt; // ������� ����, ����, ���߰� �ɾ��� ����, ���߰� �ɾ��� ��ġ(����), ���߰� �ɾ��� ��ġ(����), ����� �����������̰� �ʿ����� count
void dfs(int width, int height) {
	if (field[height][width] == 0 || height < 0 || height > row - 1 || width < 0 || width > col - 1)	return; // ���� ���
	else field[height][width] = 0; // �����������̰� �� �� �ִ� ���� 0���� �ٲ�
	for (int i = 0; i < 4; i++) dfs(dx[i] + width, dy[i] + height); // �����¿� �̵�
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int test;
	cin >> test;
	while (test--) {
		cin >> col >> row >> seed;
		cnt = 0;
		while (seed--) {
			cin >> col_seed >> row_seed;
			field[row_seed][col_seed] = 1; // ���߰� �ɾ��� ��ġ�� 1�� �ִ´�
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (field[i][j] != 0) { // �ش� ��ġ�� 0�� �ƴѰ��
					cnt++;
					dfs(j, i);
				}
			}
		}
		cout << cnt << "\n"; // count ���
	}
	return 0;
}