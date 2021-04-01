#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N;
	cin >> N;

	for (int i = 0; i < N / 2; i++)	cout << "1 2 ";
	// N이 홀수인 경우에만 마지막에 3이 온다
	if (N & 1)	cout << "3";
	return 0;
}