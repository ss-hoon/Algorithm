#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int row, col, rec; // 행, 열, 직사각형 개수
int dx[4] = { -1,0,0,1 }; // 행 좌표
int dy[4] = { 0,-1,1,0 }; // 열 좌표
int field[101][101] = {}; // 모눈종이
int DFS(int x, int y) {
	if (x < 0 || y < 0 || x > row - 1 || y > col - 1 || field[x][y] == 1) return 0; // 기저 사례
	int cnt = 1; // 방문한 위치의 count 올려줌
	field[x][y] = 1; // 방문 체크
	for (int i = 0; i < 4; i++) cnt += DFS(x + dx[i], y + dy[i]); // 상하좌우 방향으로 DFS
	return cnt; // count 값 반환
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> row >> col >> rec;
	vector <int> range;
	while (rec--) { // 직사각형 체크
		int row_under, col_under, row_up, col_up;
		cin >> col_under >> row_under >> col_up >> row_up;
		for (int i = row_under; i < row_up; i++) {
			for (int j = col_under; j < col_up; j++)	field[i][j] = true;
		}
	}
	for (int i = 0; i < row; i++) { // (0,0)부터 체크 안된 부분 찾고 DFS
		for (int j = 0; j < col; j++) {
			if (field[i][j] == 0) {
				int cnt = DFS(i, j);
				range.push_back(cnt);
			}
		}
	}
	sort(range.begin(), range.end()); // count값이 담긴 range 벡터를 오름차순으로 정렬
	cout << range.size() << "\n"; // range 벡터의 크기 출력
	for (int i = 0; i < range.size(); i++)	cout << range[i] << " "; // 정렬된 range 배열을 차례대로 출력
	return 0;
}