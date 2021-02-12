#include <iostream>
#include <vector>
using namespace std;
int N, M;
int parent[1000001];

// parent 요소를 찾아주는 함수
int find(int x) {
	if (parent[x] == x)	return x;

	// path compression
	return parent[x] = find(parent[x]);
}

// 같은 부모를 가리키도록 합치는 함수
void unionfind(int x, int y) {
	int X = find(x);
	int Y = find(y);

	if (X != Y) {
		if (X < Y)	parent[Y] = X;
		else parent[X] = y;
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N + 1; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int type, x, y;
		cin >> type >> x >> y;
		if (type == 0) {
			unionfind(x, y);
		}
		else {
			if (find(x) == find(y))	cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}