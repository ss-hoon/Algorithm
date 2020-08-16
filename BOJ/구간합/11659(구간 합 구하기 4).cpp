#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int len, test;
	cin >> len >> test;
	vector <int> v(len + 1);
	v[0] = 0; // 첫번째는 0으로 초기화
	for (int i = 1; i <= len; i++) { // 이전에 나왔던 수의 합과 이번 숫자의 합을 더해서 벡터에 넣는다
		int num;
		cin >> num;
		v[i] = v[i - 1] + num;
	}
	for (int i = 0; i < test; i++) { // 마지막 숫자의 합 - 시작 숫자 이전의 합
		int start, end;
		cin >> start >> end;
		cout << v[end] - v[start - 1] << "\n";
	}
	return 0;
}