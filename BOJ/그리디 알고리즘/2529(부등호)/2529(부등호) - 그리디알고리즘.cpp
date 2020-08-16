#include <iostream>
#include <vector>
using namespace std;
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void print(vector <int> a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}
	cout << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int num;
	cin >> num;
	vector <char> line(num);
	vector <int> maxNum(num + 1);
	vector <int> minNum(num + 1);

	for (int i = 0; i < num; i++)	cin >> line[i];

	for (int i = 0; i < maxNum.size(); i++)	maxNum[i] = 9 - i; // 최대값이므로 가장 큰수부터 차례대로 넣는다
	for (int i = 0; i < minNum.size(); i++)	minNum[i] = i; // 최소값이므로 가장 작은수부터 차례대로 넣는다

	for (int i = 0; i < num; i++) {
		switch (line[i]) {
		case '<':
			if (maxNum[i] > maxNum[i + 1]) {
				swap(maxNum[i], maxNum[i + 1]);
				i = -1; // 처음부터 다시 반복
				continue;
			}
			if (minNum[i] > minNum[i + 1]) {
				swap(minNum[i], minNum[i + 1]);
				i = -1; // 처음부터 다시 반복
			}
			break;
		case '>':
			if (maxNum[i] < maxNum[i + 1]) {
				swap(maxNum[i], maxNum[i + 1]);
				i = -1; // 처음부터 다시 반복
				continue;
			}
			if (minNum[i] < minNum[i + 1]) {
				swap(minNum[i], minNum[i + 1]);
				i = -1; // 처음부터 다시 반복
			}
			break;
		}
	}

	print(maxNum);
	print(minNum);
	return 0;
}