#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int test, people;
	cin >> test;
	while (test--) {
		cin >> people;
		vector <int> score(people + 1); // ��� ����ŭ ���� ����(0�� �ε����� ������� �����Ƿ� +1 ����)
		for (int i = 0; i < people; i++) {
			int document, interview;
			cin >> document >> interview;
			score[document] = interview; // document��° �ε����� interview���� �����Ƿ� �ڵ����� document ���� ����
		}

		int tmp = score[1];
		int cnt = 1;
		for (int i = 2; i <= people; i++) { // �ݺ����� �����ϸ鼭 tmp������ ���� ���� ������ �������ְ� cnt ���� ����
			if (tmp > score[i]) {
				tmp = score[i];
				cnt++;
			}
		}
		cout << cnt << "\n";
		score.clear();
	}
	return 0;
}