#include <iostream>
#include <cmath>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int test; // �׽�Ʈ ��
	cin >> test;
	while (test--) {
		int a, b; // a�� ��, b�� ����
		cin >> a >> b;
		if (a % 10 == 0)	cout << "10\n"; // 10�� ����� ��� 10 ���
		else { // 10�� ����� �ƴ� ���
			a %= 10; // a�� 10���� ���� �������� ������ ��ü
			if (b % 4 != 0)	b %= 4; // b�� 4�� ����� �ƴ� ��� b�� 4�� ���� �������� ������ ��ü
			else b = 4; // b�� 4�� ����� ��� b�� 4�� ��ü
			cout << (int)(pow(a, b)) % 10 << "\n"; // a�� b�� ���� 10���� ���� �������� ���� ���
		}
	}
	return 0;
}