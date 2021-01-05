#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
vector<string> cache(13);

string blank(int N) {
	string temp;
	for (int i = 0; i < (int)pow(3, N); i++)	temp += " ";
	return temp;
}

string cantor(int N, int start) {
	if (!cache[N].empty())	return cache[N];
	if (N == 0)	return "-";

	return cache[N] = cantor(N - 1, start) + blank(N - 1) + cantor(N - 1, start + 2 * N / 3);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;

	while (cin >> n && n != EOF) {
		cout << cantor(n, 0) << "\n";
	}

	return 0;
}