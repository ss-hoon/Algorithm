#include <iostream>
#define ll long long
#define mod 1000000007
using namespace std;
ll A, X;

ll solve(ll n) {
	if (n == 1)	return A;

	ll ret = solve(n / 2);
	ret = ((ret % mod) * (ret % mod)) % mod;

	if (n % 2 == 0)	return ret;
	else return ((ret % mod) * (A % mod)) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> A >> X;
	cout << solve(X) << "\n";
	return 0;
}