#include <iostream>
using namespace std;
long long A, B, C;

long long pow(int n) {
	if (n == 0)	return 1;

	long long result = pow(n / 2);
	result = (result * result) % C;

	if (n % 2 == 0)	return result;
	else return (result * A) % C;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> A >> B >> C;

	cout << pow(B) << "\n";
	return 0;
}