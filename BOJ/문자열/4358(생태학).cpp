#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, double> treeMaps;
int totalCnt = 0;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	string tree;

	// EOF일 때까지 반복해서 입력받기
	while (getline(cin, tree)) {
		treeMaps[tree]++;
		totalCnt++;
	}

	// map은 자동정렬이므로 앞에서부터 출력
	for (auto it : treeMaps) {
		cout << fixed;
		cout.precision(4);
		cout << it.first << " " << it.second / totalCnt * 100 << "\n";
	}
	return 0;
}