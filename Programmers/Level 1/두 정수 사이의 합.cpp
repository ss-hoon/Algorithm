#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int a, int b) {
    long long diff = abs(b-a);
    long long answer = (a + b) * (diff + 1) / 2;
    return answer;
}