#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector <vector<int> > cache(N + 1, vector<int>(K + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (i == 1)	cache[i][j] = j;
			else {
				if (j == 1)	cache[i][j] = 1;
				else cache[i][j] = (cache[i - 1][j] + cache[i][j - 1]) % 1000000000;
				// ��ȭ�� : (i,j) = (i-1,j) + (i,j-1)
				// ex) (4,3)�� ��� (0,2) + (1,2) + (2,2) + (3,2) + (4,2)�̴�
				// ������ (0,2) + (1,2) + (2,2) + (3,2)�� (3,3)�� �����ϹǷ�
				// (4,3)�� (4,2)�� (3,3)�� ���� ���� ����
			}
		}
	}
	cout << cache[N][K] << "\n";
	return 0;
}