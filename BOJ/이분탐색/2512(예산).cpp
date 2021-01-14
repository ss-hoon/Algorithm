#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> budget;
int N, max_budget, result = 0;

void binary_search(int start, int end) {
	if (start > end)	return;

	int mid = (start + end) / 2;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += (budget[i] < mid ? budget[i] : mid);
	}

	if (max_budget < sum)	binary_search(start, mid - 1);
	else {
		result = mid;
		binary_search(mid + 1, end);
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	budget.resize(N);

	for (int i = 0; i < N; i++)	cin >> budget[i];
	sort(budget.begin(), budget.end(), [](int &a, int &b) {
		return a > b;
	});

	cin >> max_budget;

	binary_search(1, budget[0]);
	cout << result << "\n";
	return 0;
}