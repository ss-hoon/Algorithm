#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Member {
	int age;
	string name;
	int idx;
};

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	vector<Member> list;
	int N;
	cin >> N;
	
	for(int i=0;i<N;i++) {
		int age;	string name;
		cin >> age >> name;
		list.push_back({ age, name, i });
	}

	sort(list.begin(), list.end(), [](Member &a, Member &b) {
		if (a.age != b.age)	return a.age < b.age;
		else return a.idx < b.idx;
	});

	for (auto it = list.begin(); it != list.end(); it++) {
		cout << it->age << " " << it->name << "\n";
	}
	return 0;
}