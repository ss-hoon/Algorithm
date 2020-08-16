#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	string a, b;	int start = 0;	int min_dif = 51; // a,b는 문자열	start는 시작점	min_dif는 최소 차이
	cin >> a >> b;
	for (int i = start; i <= b.length() - a.length(); i++) {
		int cnt = 0;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] != b[i + j])	cnt++; // 하나씩 옮겨가며 비교하여 최소값을 찾는다
		}
		min_dif = min(min_dif, cnt); // 가장 최소값 저장
	}
	cout << min_dif;
	return 0;
}