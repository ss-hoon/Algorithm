#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, cacheMax[3], cacheMin[3], mx[3], mn[3];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		// 0�� �ε����� �ִ밪�� ���ݱ��� ����� �ִ밪�� 0���� 1�� �� max���� ���ϰ�
		// 1�� �ε����� �ִ밪�� ���ݱ��� ����� �ִ밪�� 0���� 1���� 2�� �� max���� ���ϰ�
		// 2�� �ε����� �ִ밪�� ���ݱ��� ����� �ִ밪�� 1���� 2�� �� max���� ���Ѵ�

		// 0�� �ε����� �ּҰ��� ���ݱ��� ����� �ּҰ��� 0���� 1�� �� min���� ���ϰ�
		// 1�� �ε����� �ּҰ��� ���ݱ��� ����� �ּҰ��� 0���� 1���� 2�� �� min���� ���ϰ�
		// 2�� �ε����� �ּҰ��� ���ݱ��� ����� �ּҰ��� 1���� 2�� �� min���� ���Ѵ�
		for (int j = 0; j < 3; j++) {
			cin >> cacheMin[j];
			cacheMax[j] = cacheMin[j];
			cacheMax[j] += max(mx[1], (j == 1 ? max(mx[0], mx[2]) : mx[j]));
			cacheMin[j] += min(mn[1], (j == 1 ? min(mn[0], mn[2]) : mn[j]));
		}
		memcpy(mx, cacheMax, sizeof(int) * 3);
		memcpy(mn, cacheMin, sizeof(int) * 3);
	}

	cout << *max_element(mx, mx + 3) << " " << *min_element(mn, mn + 3) << "\n";
	return 0;
}