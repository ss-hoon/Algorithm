#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long init(vector <int> &num, vector <long long> &tree, int node, int start, int end) {
	if (start == end)	return tree[node] = num[start];
	else return tree[node] = init(num, tree, node * 2, start, (start + end) / 2) + init(num, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
void update(vector <long long> &tree, int start, int end, int node, int index,  int dif) {
	if (start > index || end < index)	return;
	tree[node] += dif;
	if (start != end) {
		update(tree, start, (start + end) / 2, node * 2, index, dif);
		update(tree, (start + end) / 2 + 1, end, node * 2 + 1, index, dif);
	}
}
long long sum(vector <long long> &tree, int start, int end, int node, int range_start, int range_end) {
	if (range_start > end || range_end < start)	return 0;
	if (range_start <= start && range_end >= end)	return tree[node];
	return sum(tree, start, (start + end) / 2, node * 2, range_start, range_end) + sum(tree, (start + end) / 2 + 1, end, node * 2 + 1, range_start, range_end);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M, K, type, a, b;
	cin >> N >> M >> K;
	vector <int> num(N + 1);
	vector <long long> tree(1 << ((int)ceil(log2(N)) + 1));
	for (int i = 1; i <= N; i++)	cin >> num[i];
	init(num, tree, 1, 1, N);
	for (int i = 0; i < M + K; i++) {
		cin >> type >> a >> b;
		if (type == 1) {
			update(tree, 1, N, 1, a, b - num[a]);
			num[a] = b;
		}
		else cout << sum(tree, 1, N, 1, a, b) << "\n";
	}
	return 0;
}