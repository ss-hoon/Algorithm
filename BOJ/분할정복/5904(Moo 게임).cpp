#include <iostream>
#include <vector>
using namespace std;
vector<long long> cache(1, 3);

void search(long long n, long long index) {
	if (index == 0) {
		if (n == 1)	cout << "m\n";
		else cout << "o\n";
	}
	else {
		if (n <= cache[index - 1] + index + 3) {
			if(n == cache[index - 1] + 1)	cout << "m\n";
			else cout << "o\n";
		}
		else {
			int i;
			for (i = 0; i < cache.size(); i++) {
				if (n - cache[index - 1] - index - 3 <= cache[i])	break;
			}
			search(n - cache[index - 1] - index - 3, i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	long long n, num = 1;
	cin >> n;

	while (1) {
		long long temp = cache[num - 1] * 2 + num + 3;
		if (n <= cache[num - 1]) break;
		else {
			cache.push_back(temp);
			num++;
		}
	}
	
	search(n, cache.size() - 1);
	return 0;
}