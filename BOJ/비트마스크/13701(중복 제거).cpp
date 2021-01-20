#include <iostream>
#include <bitset>
using namespace std;
bitset< (1 << 25) > bits;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int num;
	while (cin >> num && num != EOF) {
		if (bits[num] == 0) {
			bits[num] = 1;
			cout << num << " ";
		}
	}
	return 0;
}