#include <iostream>
#include <queue>
using namespace std;
int N, W, L, time, cnt, idx, weight;
int truck[1000];
queue< pair<int, int> > bridge; // 시간, 무게

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> W >> L;
	for (int i = 0; i < N; i++) {
		cin >> truck[i];
	}

	while (1) {
		// 모든 트럭이 반대쪽으로 이동한 경우
		if (cnt == N)	break;

		time++;

		// 다리에 있던 트럭이 반대쪽으로 이동한 경우
		if (!bridge.empty() && bridge.front().first == time) {
			weight -= bridge.front().second;
			bridge.pop();
			cnt++;
		}

		// 다리에 트럭이 들어갈 수 없는 경우
		if (bridge.size() == W)	continue;

		// 다리 하중보다 트럭들의 무게가 더 무거운 경우
		if (L < weight + truck[idx])	continue;

		bridge.push({ time + W, truck[idx] });
		weight += truck[idx++];
	}
	cout << time << "\n";
	return 0;
}