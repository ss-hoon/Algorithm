#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int row, col, rec; // ��, ��, ���簢�� ����
int dx[4] = { -1,0,0,1 }; // �� ��ǥ
int dy[4] = { 0,-1,1,0 }; // �� ��ǥ
int field[101][101] = {}; // ������
int DFS(int x, int y) {
	if (x < 0 || y < 0 || x > row - 1 || y > col - 1 || field[x][y] == 1) return 0; // ���� ���
	int cnt = 1; // �湮�� ��ġ�� count �÷���
	field[x][y] = 1; // �湮 üũ
	for (int i = 0; i < 4; i++) cnt += DFS(x + dx[i], y + dy[i]); // �����¿� �������� DFS
	return cnt; // count �� ��ȯ
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> row >> col >> rec;
	vector <int> range;
	while (rec--) { // ���簢�� üũ
		int row_under, col_under, row_up, col_up;
		cin >> col_under >> row_under >> col_up >> row_up;
		for (int i = row_under; i < row_up; i++) {
			for (int j = col_under; j < col_up; j++)	field[i][j] = true;
		}
	}
	for (int i = 0; i < row; i++) { // (0,0)���� üũ �ȵ� �κ� ã�� DFS
		for (int j = 0; j < col; j++) {
			if (field[i][j] == 0) {
				int cnt = DFS(i, j);
				range.push_back(cnt);
			}
		}
	}
	sort(range.begin(), range.end()); // count���� ��� range ���͸� ������������ ����
	cout << range.size() << "\n"; // range ������ ũ�� ���
	for (int i = 0; i < range.size(); i++)	cout << range[i] << " "; // ���ĵ� range �迭�� ���ʴ�� ���
	return 0;
}