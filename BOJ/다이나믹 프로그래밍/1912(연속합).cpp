#include <iostream>
#include <algorithm>
using namespace std;
int sum[100001] = {};
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int n, arr, max_num = -1001;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr;
		if (sum[i - 1] + arr > arr)	sum[i] = sum[i - 1] + arr;
		else sum[i] = arr;
		max_num = max(max_num, sum[i]);
	}
	cout << max_num << "\n";
	return 0;
}