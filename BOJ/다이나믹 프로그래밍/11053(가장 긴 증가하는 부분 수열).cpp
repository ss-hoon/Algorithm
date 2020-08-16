#include <iostream>
#include <algorithm>
using namespace std;
int cache[1000], score[1000], test;
int lis(int index) {
	if (cache[index] != 0)	return cache[index];
	int max_num = 1;
	for (int i = index + 1; i < test; i++) {
		if (score[index] < score[i])	max_num = max(max_num, lis(i) + 1);
	}
	return cache[index] = max_num;
}
int main() {
	int max_num = 0;
	cin >> test;
	for (int i = 0; i < test; i++)	cin >> score[i];
	for (int i = 0; i < test; i++)	max_num = max(max_num, lis(i));
	cout << max_num << "\n";
	return 0;
}