#include <string>
#include <vector>

using namespace std;

bool comp(int a, int b){
    return a > b;
}

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int posA = 0, posB = 0;
    sort(A.begin(), A.end(), comp);
    sort(B.begin(), B.end(), comp);
    
    while(posA != A.size()){
        if(A[posA] < B[posB]){
            posB++;
            answer++;
        }
        posA++;
    }
    return answer;
}