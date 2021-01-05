#include <iostream>
using namespace std;
#define ull unsigned long long
ull A, B, C;

ull mul(ull a, ull b) {
	ull sum = 0;
	while (a > 0) {
		if (a & 1) sum = (sum + b) % C;
		a >>= 1;	a %= C;
		b <<= 1;	b %= C;
	}
	return sum;
}

ull pow(ull B) {
	if (B == 1)	return A % C;

	ull result = pow(B / 2);
	result = mul(result, result);

	if (B % 2 == 0)	return result;
	else return mul(result, A);
}

int main() {
	cin >> A >> B >> C;

	cout << pow(B) << "\n";
	return 0;
}