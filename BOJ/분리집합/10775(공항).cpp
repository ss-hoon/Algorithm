#include <iostream>
using namespace std;
int gate, airplane, result, parent[100001];

// parent를 찾는 함수
int find(int vertex) {
	if (vertex == parent[vertex])	return vertex;
	return parent[vertex] = find(parent[vertex]);
}

// parent를 합치는 함수
void merge(int vertexA, int vertexB) {
	vertexA = find(vertexA);
	vertexB = find(vertexB);

	if (vertexA == vertexB)	return;

	if (vertexA < vertexB)	parent[vertexB] = vertexA;
	else parent[vertexA] = vertexB;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> gate >> airplane;
	result = airplane;

	// union-find init
	for (int gateIndex = 1; gateIndex <= gate; gateIndex++)	parent[gateIndex] = gateIndex;

	for (int arriveIndex = 0; arriveIndex < airplane; arriveIndex++) {
		int arrive;
		cin >> arrive;
		int openGate = find(arrive);

		// parent가 1 미만이면 더 이상 도킹할 수 없음
		if (openGate < 1) {
			result = arriveIndex;
			break;
		}
		else merge(openGate, openGate - 1);
	}
	
	cout << result << "\n";
	return 0;
}