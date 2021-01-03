#include <iostream>
#include <vector>
using namespace std;
long long N, B;
vector< vector<long long> > A;

vector< vector<long long> > multipleMatrix(vector< vector<long long> > &mat1, vector< vector<long long> > &mat2) {
	vector< vector<long long> > temp(N, vector<long long>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			long long sum = 0;
			for (int k = 0; k < N; k++) {
				sum += (mat1[i][k] * mat2[k][j]) % 1000;
			}
			temp[i][j] = (sum % 1000);
		}
	}
	return temp;
}

vector< vector<long long> > pow(long long n, vector< vector<long long> > &matrix) {
	vector< vector<long long> > temp(N, vector<long long>(N, 0));
	vector< vector<long long> > result(N, vector<long long>(N, 0));

	if (n == 1) return matrix;

	temp = pow(n / 2, matrix);
	
	result = multipleMatrix(temp, temp);

	if (n % 2 == 0)	return result;
	else {
		result = multipleMatrix(result, A);
		return result;
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> B;
	vector< vector<long long> > result(N, vector<long long>(N, 0));
	A.resize(N, vector<long long>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	result = pow(B, A);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << result[i][j] % 1000 << " ";
		}
		cout << "\n";
	}
	return 0;
}