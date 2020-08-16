#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	vector <int> num;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)	num.push_back(i);
	do {
		for (int i = 0; i < n; i++)	printf("%d ", num[i]);
		printf("\n");
	} while (next_permutation(num.begin(), num.end()));
	return 0;
}