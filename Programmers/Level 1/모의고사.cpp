#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> p1 = {1,2,3,4,5};
vector<int> p2 = {2,1,2,3,2,4,2,5};
vector<int> p3 = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int sum[3] = {0,0,0};
    for(int i=0;i<answers.size();i++){
        if(p1[i % p1.size()] == answers[i]) sum[0]++;
        if(p2[i % p2.size()] == answers[i]) sum[1]++;
        if(p3[i % p3.size()] == answers[i]) sum[2]++;
    }
    int maxScore = *max_element(sum, sum + 3);
    
    for(int i=0;i<3;i++){
        if(sum[i] == maxScore)  answer.push_back(i+1);
    }
    return answer;
}