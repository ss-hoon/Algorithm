#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int n;	int mx = -1; // n�� ������ ����, mx�� �ִ밪
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i]; // ������ �Է� �ޱ�
	sort(v.begin(), v.end(),greater<int>()); // ������������ ����
	for (int i = 0; i < n; i++) {
		mx = max(mx, v[i] * (i + 1)); // �ִ��� ��ƿ �� �ִ� ������ �ִ밪�� ã�´�
	}
	cout << mx;
	return 0;
}