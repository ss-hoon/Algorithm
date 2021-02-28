#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 톱니바퀴 상태 구조체
struct Gear {
	string line;
	int left, right;
}gear[5];

int K, sum;

// 회전
// 톱니바퀴를 회전시키지 않고 left, right 포인터를 이동
// 반시계 방향 -> left, right를 +1
// 시계 방향 -> left, right를 -1
void rotate(int num, int dir) {
	if (dir == -1) {
		gear[num].left = (gear[num].left + 1 > 7 ? 0 : gear[num].left + 1);
		gear[num].right = (gear[num].right + 1 > 7 ? 0 : gear[num].right + 1);
	}
	else {
		gear[num].left = (gear[num].left - 1 < 0 ? 7 : gear[num].left - 1);
		gear[num].right = (gear[num].right - 1 < 0 ? 7 : gear[num].right - 1);
	}
}

// 왼쪽과 오른쪽에 인접해 있는 톱니바퀴가 회전하는지를 재귀로 구현
// 재귀를 다 돌면 회전
void rotate(int num, int dir, int start) {
	if (start >= num && num - 1 > 0 && gear[num - 1].line[gear[num - 1].right] != gear[num].line[gear[num].left])	rotate(num - 1, (dir == -1 ? 1 : -1), start);
	if (start <= num && num + 1 < 5 && gear[num + 1].line[gear[num + 1].left] != gear[num].line[gear[num].right])	rotate(num + 1, (dir == -1 ? 1 : -1), start);

	rotate(num, dir);
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	
	for (int i = 1; i <= 4; i++) {
		string line;
		cin >> line;
		gear[i] = { line, 6, 2 };
	}

	cin >> K;
	while (K--) {
		int num, dir;
		cin >> num >> dir;
		
		// num번 톱니바퀴를 dir 방향으로 회전
		rotate(num, dir, num);

		// 마지막인 경우에 sum을 계산
		if (K == 0) {
			for (int i = 1; i <= 4; i++) {
				char point = gear[i].line[(gear[i].left + 2 > 7 ? gear[i].right - 2 : gear[i].left + 2)];
				if (point != '0')	sum += pow(2, i - 1);
			}
		}
	}
	cout << sum << "\n";
	return 0;
}