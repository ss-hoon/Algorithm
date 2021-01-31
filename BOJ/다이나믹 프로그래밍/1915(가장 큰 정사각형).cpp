#include <cstdio>
#include <algorithm>
using namespace std;
int cache[1001][1001];

int main() {
	int N, M, result = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &cache[i][j]);
			// (왼쪽 위, 왼쪽, 위) 세 요소 중 최소값을 선택해 +1을 해준다
			if (i != 0 && j != 0 && cache[i][j] != 0) cache[i][j] = min(cache[i - 1][j - 1], min(cache[i - 1][j], cache[i][j - 1])) + 1;
			result = max(result, cache[i][j]);
		}
	}
	printf("%d\n", result * result);
	return 0;
}