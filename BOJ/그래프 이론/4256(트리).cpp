#include <iostream>
#include <algorithm>
using namespace std;
int T, N, idx, pre[1000], in[1000];

void search(int left, int right) {
	if (left > right)	return;

	if (left == right) {
		cout << pre[idx++] << " ";
		return;
	}

	int root = pre[idx++];
	// 중간값 찾기
	int mid = find(in + left, in + right, root) - in;

	// postorder
	search(left, mid - 1);
	search(mid + 1, right);
	cout << root << " ";
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N;
		idx = 0;
		for (int i = 0; i < N; i++)	cin >> pre[i];
		for (int i = 0; i < N; i++)	cin >> in[i];

		search(0, N - 1);
		cout << "\n";
	}
	return 0;
}