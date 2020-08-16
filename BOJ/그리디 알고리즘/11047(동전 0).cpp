#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector <int> coin;
	int n, num, sum = 0, cnt = 0;
	cin >> n >> sum;
	while(n--) {
		cin >> num;
		coin.push_back(num);
	}
	for (int i = coin.size() - 1; i >= 0; i--) {
		if (sum / coin[i] > 0) {
			cnt += sum / coin[i];
			sum %= coin[i];
		}
	}
	cout << cnt << endl;
	return 0;
}