#include <iostream>
#include <limits>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int arr[1000000] = {};
int cnt = 0;
long long MIN = numeric_limits<long long>::min(); // long long�� �ּڰ�

typedef struct Node { // ��� ����ü
	int start; // ������
	int end; // ����
	long long data; // ���� ��
	struct Node * left; // ���� ��ũ
	struct Node * right; // ������ ��ũ
}Node;
Node * createNode(int start, int end) {
	Node * p = (Node*)malloc(sizeof(Node));
	p->start = start; // ������ �ʱ�ȭ
	p->end = end; // ���� �ʱ�ȭ
	p->data = MIN; // ���� ���� long long�� �ּڰ����� �ʱ�ȭ
	p->left = NULL; // ���� ��ũ�� NULL�� �ʱ�ȭ
	p->right = NULL; // ������ ��ũ�� NULL�� �ʱ�ȭ
	return p;
}
void create_part_Node(Node * p, int start, int end) { // ���� ���� ���� ��� �ʱ�ȭ
	Node * newNode1 = (Node*)malloc(sizeof(Node));
	Node * newNode2 = (Node*)malloc(sizeof(Node));

	if (start != end) { // ��͸� ����Ͽ� ���� ���� ���� ��� ����
		newNode1->start = start; // ������ �ʱ�ȭ
		newNode1->end = (start + end) / 2; // ���� �ʱ�ȭ
		newNode1->data = MIN; // ���� ���� long long�� �ּڰ����� �ʱ�ȭ
		newNode1->left = NULL; // ���� ��ũ�� NULL�� �ʱ�ȭ
		newNode1->right = NULL; // ������ ��ũ�� NULL�� �ʱ�ȭ

		newNode2->start = (start + end) / 2 + 1; // ������ �ʱ�ȭ
		newNode2->end = end; // ���� �ʱ�ȭ
		newNode2->data = MIN; // ���� ���� long long�� �ּڰ����� �ʱ�ȭ
		newNode2->left = NULL; // ���� ��ũ�� NULL�� �ʱ�ȭ
		newNode2->right = NULL; // ������ ��ũ�� NULL�� �ʱ�ȭ
		p->left = newNode1; // ���ʿ� newNode1�� link
		p->right = newNode2; // �����ʿ� newNode2�� link
		create_part_Node(p->left, start, (start + end) / 2); // ���� �κ�
		create_part_Node(p->right, (start + end) / 2 + 1, end); // ������ �κ�
	}
	else {
		p->data = arr[cnt++];
	}
}
long long search_sum(Node * p) { // �⺻ ���� �� ���ϱ�
	if (p->data == MIN)	return p->data = search_sum(p->left) + search_sum(p->right); // p->data�� long long�� �ּڰ��� �ƴϸ� ��͸� ���� ���� �˾Ƴ�
	else return p->data;
}
long long insert_data(Node * p, int location, int data) { // ������ �� �ֱ�
	if (p->start == p->end) {
		p->data = data;
		return p->data;
	}
	if ((p->start + p->end) / 2 >= location) return p->data = p->right->data + insert_data(p->left, location, data);
	else return p->data = p->left->data + insert_data(p->right, location, data);
}
long long solve(Node * p, int start, int end) { // ���� ���� �� �� ���ϱ�
	if (p->end < start || p->start > end)	return 0;
	if (p->start >= start && p->end <= end)	return p->data;
	return solve(p->left, start, end) + solve(p->right, start, end);
}
int main() {
	int N, M, K; // N : ������ ����, M : �� ���� Ƚ��, K : ���� �� ��� Ƚ��
	int type, a, b; // type : Ÿ��, a : 1�̸� ���°���� 2�̸� ������, b : 1�̸� �ٲ� �� 2�̸� ����
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)	cin >> arr[i]; // �迭�� �ӽ� ����
	Node * head = createNode(1, N); // head ��� ����
	create_part_Node(head, 1, N); // ���� �� ��� ����� ��ũ�帮��Ʈ�� �ӽ� �����ߴ� ���� ����
	search_sum(head);
	for (int i = 0; i < M + K; i++) {
		cin >> type >> a >> b;
		if (type == 1)	insert_data(head, a, b); // Ÿ���� 1�� ��� �� ��ġ ���� �ٲٱ�
		else cout << solve(head, a, b) << "\n"; // Ÿ���� 2�� ��� ���� �� ���ϱ�
	}
	return 0;
}