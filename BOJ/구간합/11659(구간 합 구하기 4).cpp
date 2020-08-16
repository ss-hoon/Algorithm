#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int len, test;
	cin >> len >> test;
	vector <int> v(len + 1);
	v[0] = 0; // ù��°�� 0���� �ʱ�ȭ
	for (int i = 1; i <= len; i++) { // ������ ���Դ� ���� �հ� �̹� ������ ���� ���ؼ� ���Ϳ� �ִ´�
		int num;
		cin >> num;
		v[i] = v[i - 1] + num;
	}
	for (int i = 0; i < test; i++) { // ������ ������ �� - ���� ���� ������ ��
		int start, end;
		cin >> start >> end;
		cout << v[end] - v[start - 1] << "\n";
	}
	return 0;
}