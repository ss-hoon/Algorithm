#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;

int lower_bound(int start, int end, int num) {
	if (end <= start)	return end;

	int mid = (start + end) / 2;
	if (num <= arr[mid])	return lower_bound(start, mid, num);
	else return lower_bound(mid + 1, end, num);
}

int upper_bound(int start, int end, int num) {
	if (end <= start)	return end;

	int mid = (start + end) / 2;
	if (num < arr[mid])	return upper_bound(start, mid, num);
	else return upper_bound(mid + 1, end, num);
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int n, m, num;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)	cin >> arr[i];
	sort(arr.begin(), arr.end());

	cin >> m;
	while (m--) {
		cin >> num;
		cout << (arr[n - 1] == num ? upper_bound(0, n - 1, num) + 1 : upper_bound(0, n - 1, num)) - lower_bound(0, n - 1, num) << " ";
	}
	return 0;
}