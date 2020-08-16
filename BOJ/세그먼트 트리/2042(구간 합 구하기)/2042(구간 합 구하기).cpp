#include <iostream>
#include <limits>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int arr[1000000] = {};
int cnt = 0;
long long MIN = numeric_limits<long long>::min(); // long long의 최솟값

typedef struct Node { // 노드 구조체
	int start; // 시작점
	int end; // 끝점
	long long data; // 구간 합
	struct Node * left; // 왼쪽 링크
	struct Node * right; // 오른쪽 링크
}Node;
Node * createNode(int start, int end) {
	Node * p = (Node*)malloc(sizeof(Node));
	p->start = start; // 시작점 초기화
	p->end = end; // 끝점 초기화
	p->data = MIN; // 구간 합은 long long의 최솟값으로 초기화
	p->left = NULL; // 왼쪽 링크는 NULL로 초기화
	p->right = NULL; // 오른쪽 링크는 NULL로 초기화
	return p;
}
void create_part_Node(Node * p, int start, int end) { // 구간 합을 위한 노드 초기화
	Node * newNode1 = (Node*)malloc(sizeof(Node));
	Node * newNode2 = (Node*)malloc(sizeof(Node));

	if (start != end) { // 재귀를 사용하여 구간 합을 위한 노드 생성
		newNode1->start = start; // 시작점 초기화
		newNode1->end = (start + end) / 2; // 끝점 초기화
		newNode1->data = MIN; // 구간 합은 long long의 최솟값으로 초기화
		newNode1->left = NULL; // 왼쪽 링크는 NULL로 초기화
		newNode1->right = NULL; // 오른쪽 링크도 NULL로 초기화

		newNode2->start = (start + end) / 2 + 1; // 시작점 초기화
		newNode2->end = end; // 끝점 초기화
		newNode2->data = MIN; // 구간 합은 long long의 최솟값으로 초기화
		newNode2->left = NULL; // 왼쪽 링크는 NULL로 초기화
		newNode2->right = NULL; // 오른쪽 링크도 NULL로 초기화
		p->left = newNode1; // 왼쪽에 newNode1을 link
		p->right = newNode2; // 오른쪽에 newNode2를 link
		create_part_Node(p->left, start, (start + end) / 2); // 왼쪽 부분
		create_part_Node(p->right, (start + end) / 2 + 1, end); // 오른쪽 부분
	}
	else {
		p->data = arr[cnt++];
	}
}
long long search_sum(Node * p) { // 기본 구간 합 구하기
	if (p->data == MIN)	return p->data = search_sum(p->left) + search_sum(p->right); // p->data가 long long의 최솟값이 아니면 재귀를 통해 값을 알아냄
	else return p->data;
}
long long insert_data(Node * p, int location, int data) { // 데이터 값 넣기
	if (p->start == p->end) {
		p->data = data;
		return p->data;
	}
	if ((p->start + p->end) / 2 >= location) return p->data = p->right->data + insert_data(p->left, location, data);
	else return p->data = p->left->data + insert_data(p->right, location, data);
}
long long solve(Node * p, int start, int end) { // 구간 설정 후 합 구하기
	if (p->end < start || p->start > end)	return 0;
	if (p->start >= start && p->end <= end)	return p->data;
	return solve(p->left, start, end) + solve(p->right, start, end);
}
int main() {
	int N, M, K; // N : 숫자의 갯수, M : 수 변경 횟수, K : 구간 합 출력 횟수
	int type, a, b; // type : 타입, a : 1이면 몇번째인지 2이면 시작점, b : 1이면 바꿀 수 2이면 끝점
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)	cin >> arr[i]; // 배열에 임시 저장
	Node * head = createNode(1, N); // head 노드 생성
	create_part_Node(head, 1, N); // 구간 합 노드 만들고 링크드리스트에 임시 저장했던 값을 넣음
	search_sum(head);
	for (int i = 0; i < M + K; i++) {
		cin >> type >> a >> b;
		if (type == 1)	insert_data(head, a, b); // 타입이 1일 경우 그 위치 숫자 바꾸기
		else cout << solve(head, a, b) << "\n"; // 타입이 2일 경우 구간 합 구하기
	}
	return 0;
}