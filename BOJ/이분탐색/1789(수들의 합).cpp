#include <iostream>
#define ll long long
using namespace std;
ll S;

ll binary_search(ll start, ll end) {
	if (start == end)	return start;

	ll mid = (start + end) / 2;
	if (S < (mid * mid + mid) / 2) 	return binary_search(start, mid);
	else return binary_search(mid + 1, end);
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> S;

	cout << (S != 1 ? binary_search(1, S) - 1 : 1) << "\n";
	return 0;
}