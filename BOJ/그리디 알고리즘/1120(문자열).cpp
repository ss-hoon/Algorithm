#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	string a, b;	int start = 0;	int min_dif = 51; // a,b�� ���ڿ�	start�� ������	min_dif�� �ּ� ����
	cin >> a >> b;
	for (int i = start; i <= b.length() - a.length(); i++) {
		int cnt = 0;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] != b[i + j])	cnt++; // �ϳ��� �Űܰ��� ���Ͽ� �ּҰ��� ã�´�
		}
		min_dif = min(min_dif, cnt); // ���� �ּҰ� ����
	}
	cout << min_dif;
	return 0;
}