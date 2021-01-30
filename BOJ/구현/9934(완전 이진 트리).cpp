#include <iostream>
#define LEFT 0
using namespace std;
int tree[1 << 10], temp[1 << 10];

void divide(int start, int end, int parent, int dir) {
	if (start == end) {
		if (dir == LEFT)	tree[parent * 2] = temp[start]; // LEFT
		else tree[parent * 2 + 1] = temp[start]; // RIGHT
		return;
	}

	int mid = (start + end) / 2;

	if (dir == LEFT) { // LEFT
		tree[parent * 2] = temp[mid];
		divide(start, mid - 1, parent * 2, 0);
		divide(mid + 1, end, parent * 2, 1);
	}
	else { //RIGHT
		tree[parent * 2 + 1] = temp[mid];
		divide(start, mid - 1, parent * 2 + 1, 0);
		divide(mid + 1, end, parent * 2 + 1, 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int K, n = 1;
	cin >> K;
	for (int i = 1; i < (1 << K); i++)	cin >> temp[i]; // INPUT

	int mid = (1 << K) / 2;
	tree[1] = temp[mid]; // ROOT

	divide(1, mid - 1, 1, 0); // LEFT
	divide(mid + 1, (1 << K) - 1, 1, 1); // RIGHT

	for (int i = 1; i < (1 << K); i++) { // PRINT
		if (i == ((1 << n) - 1)) {
			cout << tree[i] << "\n";
			n++;
		}
		else cout << tree[i] << " ";
	}
	return 0;
}