#include <iostream>
#include <vector>
using namespace std;
int map[9][9];
vector< pair<int, int> > blank;

bool check(int y, int x, int num) {
	// 현재 빈칸에서 가로와 세로에 num값이 있는지 확인하고 있을 경우 false 반환
	for (int i = 0; i < 9; i++) {
		if (map[y][i] == num || map[i][x] == num)	return false;
	}

	// 범위 찾기
	int boxY = y / 3 * 3;
	int boxX = x / 3 * 3;

	// 9개짜리 사각형 박스 안에 num값이 있는지 확인하고 있을 경우 false 반환
	for (int i = boxY; i < boxY + 3; i++) {
		for (int j = boxX; j < boxX + 3; j++) {
			if (map[i][j] == num)	return false;
		}
	}

	// 위에서 걸러지지 않았을 경우 true 반환
	return true;
}

bool sudoku(int idx) {
	// 끝까지 빈칸을 채웠다면 전체 출력하고 true 반환
	if (idx == blank.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)	cout << map[i][j] << " ";
			cout << "\n";
		}
		return true;
	}

	// 빈칸을 하나씩 채움
	for (int i = idx; i < blank.size(); i++) {
		int y = blank[idx].first;
		int x = blank[idx].second;
		for (int j = 1; j <= 9; j++) {
			if (check(y, x, j)) {
				map[y][x] = j;
				if(sudoku(idx + 1))	return true; // 다음 빈칸에서 true가 반환돼왔다면 true 반환해서 반복문을 종료
				map[y][x] = 0;
			}
		}
		return false; // 1부터 9까지 모두 넣었지만 false가 반환돼왔다면 false 반환해서 앞의 빈칸의 값이 적절하지 않음을 알림
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)	blank.push_back({ i, j });
		}
	}

	sudoku(0);
	return 0;
}