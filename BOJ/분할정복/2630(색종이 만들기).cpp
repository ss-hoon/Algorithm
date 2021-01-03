#include <iostream>
#include <vector>
using namespace std;
vector< vector<int> > matrix;
int blue = 0, white = 0;
bool isCorrect(int n, int x, int y) {
	int temp = matrix[y][x];
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (temp != matrix[i][j])	return false;
		}
	}
	return true;
}

void divide(int n, int x, int y) {
	if (isCorrect(n, x, y)) {
		if (matrix[y][x] == 1)	blue++;
		else white++;
	}
	else {
		divide(n / 2, x, y);
		divide(n / 2, x + n / 2, y);
		divide(n / 2, x, y + n / 2);
		divide(n / 2, x + n / 2, y + n / 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int n;
	cin >> n;
	matrix.resize(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	
	divide(n, 0, 0);
	cout << white << "\n" << blue << "\n";
	return 0;
}