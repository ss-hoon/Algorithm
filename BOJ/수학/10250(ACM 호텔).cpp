#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int H, W, N, T;
	cin >> T;
	while (T--) {
		cin >> H >> W >> N;
		cout << (N % H == 0 ? (H * 100 + N / H) : ((N % H) * 100 + N / H + 1)) << "\n";
	}
	return 0;
}