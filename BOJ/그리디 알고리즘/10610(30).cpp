#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	string num_str;	int cnt = 0;
	cin >> num_str;
	sort(num_str.begin(), num_str.end(), greater<char>()); // ������������ ����
	for (int i = 0; i < num_str.length(); i++)	cnt += num_str[i] - 48; // ���ڸ����� ���� ���Ѵ�
	if (cnt % 3 != 0 || num_str[num_str.length() - 1] - 48 != 0)	cout << "-1"; // 3�� ����̰ų� ������ ���ڰ� 0�� �ƴϸ� -1�� ���
	else {
		for (int i = 0; i < num_str.length(); i++)	cout << num_str[i]; // ���� �Ǿ� �ִ� �����̹Ƿ� ù��° �ε������� �״�� ���
	}
	return 0;
}