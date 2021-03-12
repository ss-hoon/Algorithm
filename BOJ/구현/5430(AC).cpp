#include <iostream>
#include <string>
#include <deque>
using namespace std;
int testCase, indexCnt, reverseCnt;
string operLine, line, splitNum;
deque <int> list;

bool D() {
	if (list.empty())	return false;

	if(reverseCnt % 2 == 0)	list.pop_front();
	else list.pop_back();
	return true;
}

void print() {
	cout << "[";

	// reverseCnt가 짝수이면 정방향
	// reverseCnt가 홀수이면 역방향
	while (!list.empty()) {
		if (reverseCnt % 2 == 0) {
			if (list.size() == 1)	cout << list.front();
			else cout << list.front() << ",";
			list.pop_front();
		}
		else {
			if (list.size() == 1)	cout << list.back();
			else cout << list.back() << ",";
			list.pop_back();
		}
	}
	cout << "]\n";
}

bool operCheck() {
	for (char oper : operLine) {
		switch (oper) {
		case 'D':
			if (!D()) return false;
			break;
		case 'R':
			reverseCnt++;
			break;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> testCase;
	while (testCase--) {
		int makeNum = 0;
		reverseCnt = 0;
		cin >> operLine >> indexCnt >> line;

		// 수열을 다듬어서 덱에 하나씩 삽입
		if (indexCnt != 0) {
			for (int token = 1; token < line.length(); token++) {
				if (line[token] == ',' || line[token] == ']') {
					list.push_back(makeNum);
					makeNum = 0;
				}
				else {
					makeNum = makeNum * 10 + (line[token] - '0');
				}
			}
		}

		if (operCheck()) print();
		else cout << "error\n";

		while (!list.empty())	list.pop_back();
	}
	return 0;
}