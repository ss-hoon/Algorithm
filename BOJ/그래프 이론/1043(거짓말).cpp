#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, truth, result = 0;
queue<int> truthList;
vector<bool> check;
vector< vector<int> > adj, party;

int main(){
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M >> truth;
	adj.resize(N + 1);
	check.resize(N + 1, false);
	party.resize(M + 1);

	for (int i = 0; i < truth; i++) {
		int num;
		cin >> num;
		truthList.push(num);
		check[num] = true;
	}

	// 인접 행렬 init
	for (int i = 0; i < M; i++) {
		int partyPeople;
		cin >> partyPeople;

		for (int j = 0; j < partyPeople; j++) {
			int person;
			cin >> person;
			party[i].push_back(person);
		}

		for (int j = 0; j < partyPeople; j++) {
			for (int k = j + 1; k < partyPeople; k++) {
				if (j == k)	continue;

				adj[party[i][j]].push_back(party[i][k]);
				adj[party[i][k]].push_back(party[i][j]);
			}
		}
	}

	// 진실을 알고 있는 사람을 큐에 넣고
	// 한 사람씩 해당 인접행렬에 있는 사람을 큐에 넣고
	// 반복하며 진실을 모르고 있는 사람을 찾는다(check == false)
	while (!truthList.empty()) {
		int front = truthList.front();

		for (int i = 0; i < adj[front].size(); i++) {
			if (check[adj[front][i]] == false) {
				check[adj[front][i]] = true;
				truthList.push(adj[front][i]);
			}
		}
		truthList.pop();
	}

	// 파티에 참가한 사람들 중 모든 사람이 진실을 모르고 있다면
	// result를 증가시킨다
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < party[i].size(); j++) {
			if (check[party[i][j]] == true)	break;
			if (j == party[i].size() - 1)	result++;
		}
	}
	
	cout << result << "\n";
	return 0;
}