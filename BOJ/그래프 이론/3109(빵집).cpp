#include <iostream>
using namespace std;
int R, C;
char map[10000][500];
bool visited[10000][500];

bool isPossible(int y, int x) {
	if (map[y][x] == 'x' || visited[y][x])	return false;
	visited[y][x] = true;

	// 파이프를 최대한 위쪽으로 올린다
	if (x == C - 1 || (y - 1 >= 0 && isPossible(y - 1, x + 1)) || isPossible(y, x + 1) || (y + 1 < R && isPossible(y + 1, x + 1))) 
		return true;

	// 아래 코드를 지운 이유는 이 위치에 와도 어차피 false이기 때문에
	// 메모이제이션으로 백트래킹시킨다
	// visited[y][x] = false
	return false;
}

int search() {
	int sum = 0;
	for (int i = 0; i < R; i++) {
		if (isPossible(i, 0))	sum++;
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)	cin >> map[i][j];
	}

	cout << search() << "\n";
	return 0;
}