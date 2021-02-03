#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct block { // 벽돌의 정보
	int seq, bottom, height, weight;
};

int N, maxHeight, pathStart;
vector<block> blockList; // 벽돌 리스트
vector< pair<int, int> > cache; // 현재 위치를 최하단으로 두었을 때 최대 높이

pair<int, int> searchMaxHeightBlock(int n) {
	if (cache[n].second != -1)	return cache[n];

	pair<int, int> maxSubBlock = { 0, -1 };
	for (int i = n + 1; i < N; i++) {

		// 현재 벽돌 위에 올릴 수 있는 벽돌을 판단( 밑면과 무게가 기준 벽돌보다 작아야함 ) 
		if (blockList[n].bottom > blockList[i].bottom && blockList[n].weight > blockList[i].weight) {
			pair<int, int> temp = searchMaxHeightBlock(i);

			// 최대 높이로 올릴 수 있는 벽돌을 갱신
			if (maxSubBlock.first < temp.first)
				maxSubBlock = { temp.first, i };
		}
	}

	return cache[n] = { maxSubBlock.first + blockList[n].height, maxSubBlock.second };
}

void print() {
	pair<int, int> tracking = cache[pathStart];
	vector<int> result = {blockList[pathStart].seq};

	// tracking의 second 요소는 다음 벽돌을 의미하고
	// 만약 -1이라면 Link의 끝을 의미한다
	while (tracking.second != -1) {
		result.push_back(blockList[tracking.second].seq);
		tracking = cache[tracking.second];
	}

	cout << result.size() << "\n";
	for (int i = result.size() - 1; i >= 0; i--)	cout << result[i] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	blockList.resize(N);
	cache.resize(N, pair<int, int>({-1, -1}));

	for (int i = 0; i < N; i++) {
		blockList[i].seq = i + 1;
		cin >> blockList[i].bottom >> blockList[i].height >> blockList[i].weight;
	}

	sort(blockList.begin(), blockList.end(), [](block &a, block &b) {
		return a.bottom > b.bottom;
	});

	for (int i = 0; i < N; i++) {
		pair<int, int> temp = searchMaxHeightBlock(i);
		if (maxHeight < temp.first) {
			maxHeight = temp.first;
			pathStart = i;
		}
	}

	print();
	return 0;
}