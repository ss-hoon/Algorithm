#include <iostream>
#include <cmath>
using namespace std;

bool check(int num) {
	if (num == 1)	return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0)	return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int start, end;
	cin >> start >> end;
	for (int i = start; i <= end; i++) {
		if (check(i))	cout << i << "\n";
	}
	return 0;
}