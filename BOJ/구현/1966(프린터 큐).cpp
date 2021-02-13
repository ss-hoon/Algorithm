#include <iostream>
#include <queue>
using namespace std;
queue < pair<int, int> > QUE;
priority_queue<int> PQ;
int T, N, M;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> T;
	while (T--) {
		int print = 1;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			QUE.push({ i, n });
			PQ.push(n);
		}
		
		while (1) {
			// 최대힙의 top 값과 현재 큐 front의 우선순위 값이 다르다면,
			// 큐의 front를 back으로 보낸다
			if (QUE.front().second != PQ.top()) {
				pair<int, int> temp = QUE.front();
				QUE.push(temp);
				QUE.pop();
				continue;
			}

			// 최대힙의 top 값과 현재 큐 front의 우선순위 값이 같고,
			// 찾으려는 인덱스 또한 같다면 몇 번째로 출력됐는지 출력
			if (QUE.front().first == M) {
				cout << print << "\n";
				break;
			}

			// 최대힙의 top 값과 현재 큐 front의 우선순위 값이 같지만,
			// 찾으려는 인덱스가 다르다면 큐와 최대힙을 둘다 pop
			else {
				QUE.pop();
				PQ.pop();
				print++;
			}
		}
		
		while (!QUE.empty())	QUE.pop();
		while (!PQ.empty())	PQ.pop();
	}
	return 0;
}