#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int num;
	int result = 0, tmp = 0;
	bool check = false;
	while (cin.peek() != '\n' && cin >> num) {
		if (check)	tmp -= abs(num);
		else {
			if (num > 0)	result += num;
			else {
				tmp -= abs(num);
				check = true;
			}
		}
	}
	cout << result + tmp << "\n";
	return 0;
}