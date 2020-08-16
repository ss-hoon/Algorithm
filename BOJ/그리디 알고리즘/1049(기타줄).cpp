#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int line, brand, set, min_money;
	int pac1 = 1001, pac2 = 1001;
	cin >> line >> brand;
	for (int i = 0; i < brand; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		pac1 = min(num1, pac1); // 6�� ��Ű�� ���� �� �ּ� ���ݸ��� �ִ´�
		pac2 = min(num2, pac2); // ���� ���� �� �ּ� ���ݸ��� �ִ´�
	}

	// -- 6�� ��Ű�� �������� �������� ��� ��� set�� ����ϴ���
	if (line % 6 == 0)	set = line / 6; 
	else set = (line / 6) + 1;
	// --------------------------------------------------------

	min_money = min(pac1 * set, pac2 * line); // 6�� ��Ű���� �������� ���, ������ �������� ��� �� �ּ� ������ min_money�� �ִ´�
	min_money = min(min_money, pac1 * (line / 6) + pac2 * (line % 6)); // 6�� ��Ű���� ������ ���� �������� ���� ���� min_money �� �ּ� ������ min_money�� �ִ´�
	cout << min_money << "\n";
	return 0;
}