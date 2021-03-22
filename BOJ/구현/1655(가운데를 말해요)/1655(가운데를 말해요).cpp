#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> leftMaxHeap, rightMinHeap;
int N, num, root;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (i == 0)	root = num;
		else {
			// 오른쪽 서브트리의 개수가 더 많을 경우
			if (leftMaxHeap.size() < rightMinHeap.size()) {
				if (root <= num) {
					leftMaxHeap.push(root);
					// 오른쪽 서브트리의 최소값이 현재 들어온 수보다 큰 경우 swap
					if (!rightMinHeap.empty() && -rightMinHeap.top() < num) {
						root = -rightMinHeap.top();
						rightMinHeap.pop();
						rightMinHeap.push(-num);
					}
					else root = num;
				}
				else
					leftMaxHeap.push(num);
			}
			// 왼쪽 서브트리의 개수가 더 많을 경우 또는 같은 경우
			// 짝수개일 경우 둘 중 최소값을 선택하므로 같은 경우는 왼쪽 서브트리가 더 많은 경우와 같이 본다
			else {
				if (root <= num)
					rightMinHeap.push(-num);
				else {
					rightMinHeap.push(-root);
					// 왼쪽 서브트리의 최대값이 현재 들어온 수보다 작은 경우 swap
					if (!leftMaxHeap.empty() && leftMaxHeap.top() > num) {
						root = leftMaxHeap.top();
						leftMaxHeap.pop();
						leftMaxHeap.push(num);
					}
					else root = num;
				}
			}
		}
		cout << root << "\n";
	}
	return 0;
}