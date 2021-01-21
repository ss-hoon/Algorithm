#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N;
double tmp, cache[2], result = 0.0;

int main() {
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%lf", &tmp);
		if (i == 0)	cache[1] = tmp;
		else cache[1] = max(cache[0] * tmp, tmp);

		result = max(result, cache[1]);
		cache[0] = cache[1];
	}
	printf("%.3lf", result);
	return 0;
}