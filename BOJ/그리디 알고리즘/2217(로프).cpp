#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int n;	int mx = -1; // n은 데이터 개수, mx는 최대값
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i]; // 데이터 입력 받기
	sort(v.begin(), v.end(),greater<int>()); // 내림차순으로 정렬
	for (int i = 0; i < n; i++) {
		mx = max(mx, v[i] * (i + 1)); // 최대한 버틸 수 있는 무게의 최대값을 찾는다
	}
	cout << mx;
	return 0;
}