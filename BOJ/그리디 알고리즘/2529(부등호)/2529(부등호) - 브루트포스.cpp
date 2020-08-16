#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int num;
string temp, line;
vector <int> maxNum, minNum;

bool check(vector <int> vec) {
	for (int index = 0; index < line.length(); index++) {
		switch (line[index]) {
		case '<':
			if (vec[index] > vec[index + 1])	return false;
			break;
		case '>':
			if (vec[index] < vec[index + 1])	return false;
			break;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	
	cin >> num;
	cin.ignore();
	getline(cin, temp);
	for (int index = 0; index < temp.length(); index++) {
		if (temp[index] != ' ')	line += temp[index];
	}
	
	maxNum.resize(num + 1);
	minNum.resize(num + 1);

	for (int index = 0; index < num + 1; index++)	maxNum[index] = 9 - index;
	for (int index = 0; index < num + 1; index++)	minNum[index] = 0 + index;

	do {
		if (check(maxNum)) {
			for (int index : maxNum)	cout << index;
			cout << "\n";
			break;
		}
	} while (prev_permutation(maxNum.begin(), maxNum.end()));

	do {
		if (check(minNum)) {
			for (int index : minNum)	cout << index;
			cout << "\n";
			break;
		}
	} while (next_permutation(minNum.begin(), minNum.end()));
	return 0;
}