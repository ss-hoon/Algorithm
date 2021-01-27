#include <iostream>
#include <vector>
using namespace std;
vector<int> row(10, 0);
vector<int> col(10, 0);
vector<int> sq(10, 0);
vector< vector<int> > map(9, vector<int>(9, 0));
vector< pair<int, int> > blank;

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
	int y = blank[idx].first;
	int x = blank[idx].second;
	for (int j = 1; j <= 9; j++) {
		int box = (y / 3) * 3 + (x / 3);
		if (row[y] & (1 << j))	continue; // 현재 위치의 행에 j 값이 있는지 확인
		if (col[x] & (1 << j))	continue; // 현재 위치의 열에 j 값이 있는지 확인
		if(sq[box] & (1 << j))	continue; // 현재 위치의 사각형에 j 값이 있는지 확인

		// 위에서 걸러지지 않으면 들어가도 되는 수이므로 빈칸에 j 값을 넣음
		row[y] |= (1 << j);
		col[x] |= (1 << j);
		sq[box] |= (1 << j);
		map[y][x] = j;

		if (sudoku(idx + 1))	return true; // 다음 빈칸에서 true가 반환돼왔다면 true 반환해서 반복문을 종료

		map[y][x] = 0;
		row[y] &= ~(1 << j);
		col[x] &= ~(1 << j);
		sq[box] &= ~(1 << j);
	}
	return false; // 1부터 9까지 모두 넣었지만 false가 반환돼왔다면 false 반환해서 앞의 빈칸의 값이 적절하지 않음을 알림
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)	blank.push_back({ i, j });
			else {
				row[i] |= (1 << map[i][j]);
				col[j] |= (1 << map[i][j]);
				sq[(i / 3) * 3 + (j / 3)] |= (1 << map[i][j]);
			}
		}
	}

	sudoku(0);
	return 0;
}