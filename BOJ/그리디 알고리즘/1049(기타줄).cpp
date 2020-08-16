#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int line, brand, set, min_money;
	int pac1 = 1001, pac2 = 1001;
	cin >> line >> brand;
	for (int i = 0; i < brand; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		pac1 = min(num1, pac1); // 6개 패키지 가격 중 최소 가격만을 넣는다
		pac2 = min(num2, pac2); // 낱개 가격 중 최소 가격만을 넣는다
	}

	// -- 6개 패키지 가격으로 구매했을 경우 몇개의 set를 사야하는지
	if (line % 6 == 0)	set = line / 6; 
	else set = (line / 6) + 1;
	// --------------------------------------------------------

	min_money = min(pac1 * set, pac2 * line); // 6개 패키지로 구매했을 경우, 낱개로 구매했을 경우 중 최소 가격을 min_money에 넣는다
	min_money = min(min_money, pac1 * (line / 6) + pac2 * (line % 6)); // 6개 패키지와 낱개를 같이 구입했을 경우와 기존 min_money 중 최소 가격을 min_money에 넣는다
	cout << min_money << "\n";
	return 0;
}