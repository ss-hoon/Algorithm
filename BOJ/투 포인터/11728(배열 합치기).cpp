#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N, M, ptrA = 0, ptrB = 0;
	cin >> N >> M;
	vector<int> listA(N), listB(M), result;

	for (int i = 0; i < N; i++)	cin >> listA[i];
	for (int i = 0; i < M; i++)	cin >> listB[i];

	// 두 포인터가 가리키는 숫자 중 작은 값을 result에 넣는다
	while (ptrA < listA.size() && ptrB < listB.size()) {
		if (listA[ptrA] < listB[ptrB])	result.push_back(listA[ptrA++]);
		else result.push_back(listB[ptrB++]);
	}

	// 위 반복문이 끝나고 A 포인터가 listA를 다 읽지 않은 경우에는 남은 listA 값을 차례대로 넣는다
	if (ptrA != listA.size()) {
		for (int i = ptrA; i < listA.size(); i++)	result.push_back(listA[i]);
	}

	// 위 반복문이 끝나고 B 포인터가 listB를 다 읽지 않은 경우에는 남은 listB 값을 차례대로 넣는다
	if (ptrB != listB.size()) {
		for (int i = ptrB; i < listB.size(); i++)	result.push_back(listB[i]);
	}

	for (int i = 0; i < result.size(); i++)	cout << result[i] << " ";
	return 0;
}