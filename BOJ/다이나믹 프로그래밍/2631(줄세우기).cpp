#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cache[201];	int child = 0;
int solve(vector <int> &seq, int m) {
	if (cache[m] != 0)	return cache[m]; // cache에 메모이제이션된 것은 바로 return
	for (int i = m + 1; i < child; i++) {
		if(m == -1 || seq[i] > seq[m])	// 맨 첫번째로 함수에 들어왔거나, 다음 수가 현재 수보다 클 경우 
			cache[m] = max(cache[m], solve(seq, i) + 1);
	}
	return cache[m];
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> child; // 몇 명의 아이가 있는지 입력 받기
	vector <int> seq(child); // 아이들 수만큼 벡터생성
	for (int i = 0; i < child; i++)	cin >> seq[i];
	cout << child - solve(seq,-1) << "\n"; // 전체 아이 수에서 정렬된 아이 수를 빼면 된다.
	return 0;
}