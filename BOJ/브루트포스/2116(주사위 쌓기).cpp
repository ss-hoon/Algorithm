#include <iostream>
#include <algorithm>
using namespace std;
int N, cube[10000][7], idx[7] = { 0, 6, 4, 5, 2, 3, 1 };

int maxItem(int floor, int n) {
	// 아랫면과 윗면을 제외한 나머지 값 중 최대값 return
	int result = 0;
	for (int i = 1; i <= 6; i++) {
		if (i == n || i == cube[floor][n])	continue;
		result = max(result, cube[floor][i]);
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;

	// cube[i][j]
	// i : 주사위 개수(층)
	// j : 아랫면이 j일 때, 윗면 값
	for (int i = 0; i < N; i++) {
		int temp[7];
		for (int j = 1; j <= 6; j++)	cin >> temp[j];
		for (int j = 1; j <= 6; j++)	cube[i][temp[j]] = temp[idx[j]];
	}

	// 모든 경로 탐색(브루트포스 알고리즘)
	int result = 0;
	for (int j = 1; j <= 6; j++) {
		int top = j;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += maxItem(i, top);
			top = cube[i][top];
		}
		result = max(result, sum);
	}

	// 최대값 출력
	cout << result << "\n";
	return 0;
}