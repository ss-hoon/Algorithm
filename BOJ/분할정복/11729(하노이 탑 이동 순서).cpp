#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector< pair<int, int> > path;

void hanoi(int start, int tmp, int end, int n) {
	if (n == 1)	cout << start << " " << end << "\n";
	else {
		hanoi(start, end, tmp, n - 1);
		hanoi(start, tmp, end, 1);
		hanoi(tmp, start, end, n - 1);
	}	
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int n;
	cin >> n;
	
	cout << (long long)pow(2, n) - 1 << "\n";
	hanoi(1, 2, 3, n);
	return 0;
}