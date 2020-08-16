#include <stdio.h>
int n;
int num[9] = { 0 };
bool check[9] = { false };
void solve(int cnt) {
	if (cnt == n) {
		for (int i = 1; i <= n; i++) {
			if (check[i] == false) {
				num[cnt] = i;
				for (int j = 1; j <= n; j++)	printf("%d ", num[j]);
				num[cnt] = 0;
				printf("\n");
				break;
			}
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			check[i] = true;
			num[cnt] = i;
			solve(cnt + 1);
			check[i] = false;
			num[cnt] = 0;
		}
	}
}
int main() {
	scanf("%d", &n);
	solve(1);
	return 0;
}