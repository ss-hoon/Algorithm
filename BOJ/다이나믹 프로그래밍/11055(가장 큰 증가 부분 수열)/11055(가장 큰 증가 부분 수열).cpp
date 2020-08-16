#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cnt;
vector <int> sequence;
vector <int> cache;

int max_sum(int position) {
	int max_num = -1;
	if (cache[position] != -1)	return cache[position];
	if (position == cnt - 1)	return cache[position] = sequence[position];

	for (int index = position + 1; index < cnt; index++) {
		if(sequence[position] < sequence[index])	max_num = max(max_num, max_sum(index));
	}
	if (max_num == -1)	return cache[position] = sequence[position];
	else return cache[position] = max_num + sequence[position];
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> cnt;
	int max_num = -1;
	sequence.resize(cnt, 0);
	cache.resize(cnt, -1);
	for (int index = 0; index < cnt; index++)	cin >> sequence[index];
	for (int index = 0; index < cnt; index++)	max_num = max(max_sum(index), max_num);
	cout << max_num << "\n";
	return 0;
}