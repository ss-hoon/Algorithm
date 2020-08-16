#include <iostream>
#include <cstring>
using namespace std;

int people, bestFriend, areFriends[10][10];
int picnic(bool check[10]) {
	int first = -1;
	int sum = 0;
	for (int i = 0; i < people; i++) {
		if (check[i] == false) {
			first = i;
			break;
		}
	}
	if (first == -1)	return 1;

	for (int pairWith = first + 1; pairWith < people; pairWith++) {
		if (!check[pairWith] && areFriends[first][pairWith]) {
			check[pairWith] = check[first] = true;
			sum += picnic(check);
			check[pairWith] = check[first] = false;
		}
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int test;
	cin >> test;
	while (test--) {
		cin >> people >> bestFriend;
		for (int i = 0; i < bestFriend; i++) {
			int x, y;
			cin >> x >> y;
			areFriends[x][y] = areFriends[y][x] = 1;
		}
		bool check[10] = { false, };
		cout << picnic(check) << "\n";
		memset(areFriends, 0, sizeof(areFriends));
	}
	return 0;
}