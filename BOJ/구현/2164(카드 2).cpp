#include <iostream>
#include <queue>
using namespace std;
queue <int> QUE;
int N;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)	QUE.push(i);

	if (N == 1)	cout << "1\n";
	else {
		while (1) {
			QUE.pop();
			if (QUE.size() == 1) {
				cout << QUE.front() << "\n";
				break;
			}

			QUE.push(QUE.front());
			QUE.pop();
		}
	}
	return 0;
}