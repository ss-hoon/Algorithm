#include <iostream>
using namespace std;
int map[100][100];

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)	cin >> map[i][j];
	}

	// Floyd-Warshall 알고리즘
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == k || map[i][j])	continue;

				if (map[i][k] && map[k][j])	map[i][j] = 1;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)	cout << map[i][j] << " ";
		cout << "\n";
	}
	return 0;
}