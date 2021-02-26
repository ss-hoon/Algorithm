#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, start, finish, minResult = INF, floyd[51][51], relation[51];
vector<int> cnt[51];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		relation[i] = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j)	floyd[i][j] = 0;
			else floyd[i][j] = INF;
		}
	}

	// 양방향 설정
	while(cin >> start >> finish && start != -1 && finish != -1){
		floyd[start][finish] = 1;
		floyd[finish][start] = 1;
	}

	// Floyd Algorithm
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == k)	continue;

				floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			// 친구 관계가 가장 큰 값을 구함
			relation[i] = max(relation[i], floyd[i][j]);
		}
		// 전체 중 최소값을 탐색
		minResult = min(minResult, relation[i]);
		// 친구 관계 수 벡터에 현재 인덱스를 추가
		cnt[relation[i]].push_back(i);
	}

	cout << minResult << " " << cnt[minResult].size() << "\n";
	for (int n : cnt[minResult])	cout << n << " ";

	return 0;
}