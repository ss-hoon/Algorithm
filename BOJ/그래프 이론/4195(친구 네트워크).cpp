#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
map<string, int> nameIndex;
vector<int> parent;
vector<int> nodeCnt;

void init(int n) {
	parent.resize(n * 2);
	nodeCnt.resize(n * 2 , 1);
	for (int i = 1; i < n * 2; i++)	parent[i] = i;
}

int find(int n) {
	if (n == parent[n])	return n;

	return parent[n] = find(parent[n]);
}

int unionRoot(int A, int B) {
	if (A != B) {
		parent[B] = A;
		nodeCnt[A] += nodeCnt[B];
		nodeCnt[B] = 1;
	}
	return nodeCnt[A];
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int T, network;
	cin >> T;
	while (T--) {
		int cur = 0;
		cin >> network;
		init(network);

		while (network--) {
			string a, b;
			cin >> a >> b;
			if (nameIndex.find(a) == nameIndex.end())	nameIndex.insert({ a, cur++ });
			if (nameIndex.find(b) == nameIndex.end())	nameIndex.insert({ b, cur++ });

			int A = find(nameIndex.find(a)->second);	
			int B = find(nameIndex.find(b)->second);
			cout << unionRoot(A, B) << "\n";
		}
		nameIndex.clear();
		parent.clear();
		nodeCnt.clear();
	}
	return 0;
}