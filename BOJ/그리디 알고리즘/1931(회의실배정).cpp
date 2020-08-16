#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
bool compare(const pair<ll, ll> &a, const pair<ll,ll> &b) {
	if (a.second == b.second)	return a.first < b.first;
	return a.second < b.second;
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	long long start, end, cnt = 0;
	vector <pair<ll, ll> > meet_time;
	int meet;
	cin >> meet;
	for (int i = 0; i < meet; i++) {
		cin >> start >> end;
		meet_time.push_back(make_pair(start, end));
	}
	sort(meet_time.begin(), meet_time.end(), compare);
	if (meet != 0) {
		cnt = 1;
		start = meet_time[0].first;
		end = meet_time[0].second;
	}
	for (int i = 1; i < meet; i++) {
		if (end <= meet_time[i].first) {
			start = meet_time[i].first;
			end = meet_time[i].second;
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}