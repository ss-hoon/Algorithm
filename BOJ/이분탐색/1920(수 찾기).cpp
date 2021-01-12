#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;

int binary_search(int start, int end, int num) {
	if (start == end) {
		if (arr[start] == num)	return 1;
		else return 0;
	}

	int mid = (start + end) / 2;
	if (num <= arr[mid])	return binary_search(start, mid, num);
	else return binary_search(mid + 1, end, num);
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int n, m;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr.begin(), arr.end());

	cin >> m;
	while (m--) {
		int query;
		cin >> query;
		cout << binary_search(0, n - 1, query) << "\n";
	}
	return 0;
}