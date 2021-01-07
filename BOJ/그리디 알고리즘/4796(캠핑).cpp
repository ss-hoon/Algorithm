#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int L, P, V, cnt = 0;
	while (cin >> L >> P >> V && !(L == 0 && P == 0 && V == 0)) {
		int sum = 0;
		sum += (V / P) * L + (V % P > L ? L : (V % P));
		cout << "Case " << ++cnt << ": " << sum << "\n";
	}
	return 0;
}