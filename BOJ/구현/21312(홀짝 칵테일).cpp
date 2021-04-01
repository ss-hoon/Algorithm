#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > list;

void insert(int num) {
	if (num % 2 == 0) list.push_back({ 0, num });
	else list.push_back({ 1, num });
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;

	insert(a);
	insert(b);
	insert(c);
	insert(a * b);
	insert(a * c);
	insert(b * c);
	insert(a * b * c);

	// sort를 오름차순으로 하면 홀수이고 가장 큰수가 마지막으로 감
	sort(list.begin(), list.end());
	cout << list.back().second << "\n";
	return 0;
}