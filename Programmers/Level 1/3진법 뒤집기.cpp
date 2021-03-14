#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
queue<int> tenToThree;

int solution(int n) {
    int answer = 0;
    while(n>0){
        tenToThree.push(n % 3);
        n /= 3;
    }
    
    int len = tenToThree.size() - 1;
    for(int i=len;i>=0;i--){
        answer += pow(3, i) * tenToThree.front();
        tenToThree.pop();
    }
    return answer;
}