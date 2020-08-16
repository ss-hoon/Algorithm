#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cache[201];	int child = 0;
int solve(vector <int> &seq, int m) {
	if (cache[m] != 0)	return cache[m]; // cache�� �޸������̼ǵ� ���� �ٷ� return
	for (int i = m + 1; i < child; i++) {
		if(m == -1 || seq[i] > seq[m])	// �� ù��°�� �Լ��� ���԰ų�, ���� ���� ���� ������ Ŭ ��� 
			cache[m] = max(cache[m], solve(seq, i) + 1);
	}
	return cache[m];
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> child; // �� ���� ���̰� �ִ��� �Է� �ޱ�
	vector <int> seq(child); // ���̵� ����ŭ ���ͻ���
	for (int i = 0; i < child; i++)	cin >> seq[i];
	cout << child - solve(seq,-1) << "\n"; // ��ü ���� ������ ���ĵ� ���� ���� ���� �ȴ�.
	return 0;
}