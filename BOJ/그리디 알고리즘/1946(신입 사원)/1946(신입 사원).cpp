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
		vector <int> score(people + 1); // 사람 수만큼 벡터 생성(0번 인덱스는 사용하지 않으므로 +1 해줌)
		for (int i = 0; i < people; i++) {
			int document, interview;
			cin >> document >> interview;
			score[document] = interview; // document번째 인덱스에 interview값을 넣으므로 자동으로 document 기준 정렬
		}

		int tmp = score[1];
		int cnt = 1;
		for (int i = 2; i <= people; i++) { // 반복문을 실행하면서 tmp값보다 낮은 값이 있으면 갱신해주고 cnt 값을 증가
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