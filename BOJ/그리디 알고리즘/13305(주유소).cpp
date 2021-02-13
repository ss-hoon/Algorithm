#include <iostream>
#include <algorithm>
using namespace std;
long long N, road[100001], oil[100001], minOil = 2000000000, sum = 0;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N - 1; i++)	cin >> road[i];
	for (int i = 0; i < N; i++)	cin >> oil[i];

	// 현재 지나온 도시들 중 기름 가격이 가장 싼 도시에서 
	// 그리디 방식으로 기름을 구입
	for (int i = 0; i < N - 1; i++) {
		minOil = min(minOil, oil[i]);
		sum += minOil * road[i];
	}
	cout << sum << "\n";
	return 0;
}