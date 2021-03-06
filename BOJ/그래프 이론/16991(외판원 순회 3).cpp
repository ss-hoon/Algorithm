#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
vector< vector<double> > cache(16, vector<double>(1 << 16));
vector< pair<int, int> > v;

// Distance Calculation
double dist(int a, int b) {
	return sqrt(pow(v[a].first - v[b].first, 2) + pow(v[a].second - v[b].second, 2));
}

// TSP Problem
double TSP(int start, int visit) {
	if (visit == ((1 << N) - 1)) return dist(start, 0);

	double &ret = cache[start][visit];
	if (ret)	return ret;

	ret = 1e9;
	for (int i = 0; i < N; i++) {
		if (start == i || visit & (1 << i))	continue;

		ret = min(ret, TSP(i, visit | (1 << i)) + dist(start, i));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int y, x;
		cin >> y >> x;
		v.push_back({ y, x });
	}

	cout << fixed;
	cout.precision(10);
	cout << TSP(0, 1);
	return 0;
}