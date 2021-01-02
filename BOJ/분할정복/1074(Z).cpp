#include <iostream>
using namespace std;

int num = 0;
int r, c;

void draw(int x, int y, int N) {
	if (N == 1)	cout << num << "\n";
	else if (r < y + (N / 2) && c < x + (N / 2)) { // 0번
		draw(x, y, N / 2);
	}
	else if (r < y + (N / 2) && c < x + N) { // 1번
		num += ((N / 2) * (N / 2));
		draw(x + (N / 2), y, N / 2);
	}
	else if (r < y + N && c < x + (N / 2)) { // 2번
		num += (2 * (N / 2) * (N / 2));
		draw(x, y + (N / 2), N / 2);
	}
	else { // 3번
		num += (3 * (N / 2) * (N / 2));
		draw(x + (N / 2), y + (N / 2), N / 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N;

	cin >> N >> r >> c;

	N = 1 << N;

	draw(0, 0, N);
	return 0;
}