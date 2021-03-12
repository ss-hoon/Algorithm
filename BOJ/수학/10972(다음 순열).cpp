#include <iostream>
#include <algorithm>
using namespace std;
int totalNumCnt, list[10000];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> totalNumCnt;
	for (int numIndex = 0; numIndex < totalNumCnt; numIndex++) {
		cin >> list[numIndex];
	}

	// 다음 순열이 있는 경우
	if (next_permutation(list, list + totalNumCnt)) {
		for(int listIndex = 0; listIndex < totalNumCnt; listIndex++)
			cout << list[listIndex] << " ";
	}
	// 다음 순열이 없는 경우
	else cout << "-1\n";
	return 0;
}