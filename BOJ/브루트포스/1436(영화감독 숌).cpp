#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N, cnt = 0, num = 665;

	cin >> N;
	while (num++) {
		string tmp = to_string(num);
		if (tmp.find("666") != -1)	cnt++;
		if (cnt == N)	break;
	}
	
	cout << num << "\n";
	return 0;
}