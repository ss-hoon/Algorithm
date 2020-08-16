#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N;
	cin >> N;
	vector <int> cache(N + 1);
	cache[1] = 1;	cache[2] = 2;
	for (int i = 3; i <= N; i++) {
		cache[i] = (cache[i - 2] + cache[i - 1]) % 15746;
		// ��ȭ�� : i = (i-2) + (i-1)
		// i��°�� 2�� ������ ������
		// (i-2)��°�� ���� 00�� �߰��� ����
		// (i-1)��°�� ���� 1�� �߰��� ��츸 �ֱ� ����
	}
	cout << cache[N] << "\n";
	return 0;
}