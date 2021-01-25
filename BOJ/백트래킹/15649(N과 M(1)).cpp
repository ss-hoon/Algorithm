#include <cstdio>
char str[16] = "               ";
int check[8] = {};
int N, M;
void search(int n) {
	if (n == M) {
		printf("%s\n", str);
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (check[i] == 0) {
			str[n] = i + '1';
			check[i] = 1;
			search(n + 2);
			check[i] = 0;
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	M *= 2;
	str[M] = 0;
	search(0);
	return 0;
}