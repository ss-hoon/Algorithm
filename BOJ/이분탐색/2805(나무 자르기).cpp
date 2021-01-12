#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> tree;
int N, M;
long long result = 0;

void binary_search(int start, int end) {
	if (start == end) return;

	int mid = (start + end) / 2;
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		sum += (tree[i] > mid ? (tree[i] - mid) : 0);
		if (sum >= M)	break;
	}
	if (sum < M)	binary_search(start, mid);
	else {
		result = mid;
		binary_search(mid + 1, end);
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	tree.resize(N);

	for (int i = 0; i < N; i++)	cin >> tree[i];
	sort(tree.begin(), tree.end(), [](int &a, int &b){
		return a > b;
	});

	binary_search(1, tree[0]);
	cout << result << "\n";
	return 0;
}