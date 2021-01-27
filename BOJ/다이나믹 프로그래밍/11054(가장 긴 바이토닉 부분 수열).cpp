#include <iostream>
using namespace std;
int list[1000], incr[1000], decr[1000];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int result = 0, N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		int max_inc = 0;
		for (int j = 0; j < i; j++) {
			if (list[j] < list[i] && max_inc < incr[j])	max_inc = incr[j];
		}
		incr[i] = max_inc + 1;
	}

	for (int i = N - 1; i >= 0; i--) {
		int max_inc = 0;
		for (int j = N - 1; j > i; j--) {
			if (list[j] < list[i] && max_inc < decr[j])	max_inc = decr[j];
		}
		decr[i] = max_inc + 1;
	}

	for (int i = 0; i < N; i++) {
		if (result < incr[i] + decr[i])	result = incr[i] + decr[i];
	}
	cout << result - 1 << "\n";
	return 0;
}