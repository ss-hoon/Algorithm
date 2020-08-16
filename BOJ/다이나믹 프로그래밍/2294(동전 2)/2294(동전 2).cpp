#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int cnt, goal;
	cin >> cnt >> goal;
	vector <int> coin(cnt);
	vector <vector <int> > cache(cnt, vector<int>(goal + 1, 0));

	for (int index = 0; index < cnt; index++)	cin >> coin[index];

	for (int i = 0; i < cnt; i++) {
		for (int j = 1; j < goal + 1; j++) {
			if (i == 0) { // �� ó���� ��쿡�� ������ �������� ��������, ������ �������� ������ -1�� ĳ�� �迭�� �ۼ��Ѵ�
				if (j % coin[i] == 0)    cache[i][j] = j / coin[i];
				else cache[i][j] = -1;
			}
			else { // �� ó���� �ƴ� ���
				if (j < coin[i]) cache[i][j] = cache[i - 1][j]; // ���� ���ϴ� ���� ��ġ�� ���� ��ǥġ(j��)���� ���� ��쿡�� �Ž����� �� ���� ������ ���� ĳ�� �迭 ���� �״�� �����´�
				else { // ���� ���ϴ� ���� ��ġ�� ���� ��ǥġ(j��)���� ���� ���
					if (cache[i - 1][j] == -1 && cache[i][j - coin[i]] == -1) cache[i][j] = -1; // ���� ���ߴ� �������ε� �Ž����� �� ����, ���� ���ϴ� �������ε� �Ž��� �� �� ���� ��
					else if (cache[i - 1][j] == -1) cache[i][j] = cache[i][j - coin[i]] + 1; // ���� ���ϴ� �������� �Ž����� �� ���� ��
					else if (cache[i][j - coin[i]] == -1) cache[i][j] = cache[i - 1][j]; // ���� ���ߴ� �������θ� �Ž����� �� ���� ��
					else cache[i][j] = min(cache[i - 1][j], cache[i][j - coin[i]] + 1); // �Ѵ� ������ ��
				}
			}
		}
	}
	cout << cache[cnt - 1][goal] << "\n";
	return 0;
}