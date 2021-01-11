#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<vector<int> > conn;
vector<bool> check;
stack<int> st;
int dfs(int num) {
	int sum = 0;
	check[num] = true;
	st.push(num);
	for (int i = 0; i < conn[num].size(); i++) {
		if (check[conn[num][i]] == false)
			sum += dfs(conn[num][i]);
	}
	st.pop();
	return sum + 1;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int com, pair;
	cin >> com >> pair;
	conn.resize(com + 1);
	check.resize(com + 1);
	while (pair--) {
		int x, y;
		cin >> x >> y;
		conn[x].push_back(y);
		conn[y].push_back(x);
	}
	cout << dfs(1) - 1 << "\n";
	return 0;
}