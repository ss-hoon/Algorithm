#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int n;
	cin >> n;
	cout.precision(20);
	cout << M_PI * pow(n, 2) << "\n" << pow(n, 2) * 2 << "\n";
	return 0;
}