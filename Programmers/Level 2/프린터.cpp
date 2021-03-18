#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
queue<pair<int,int>> q;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i], i});
    }
    
    while(!q.empty()){
        answer++;
        int max = *max_element(priorities.begin(), priorities.end());
        while(q.front().first != max){
            q.push({q.front().first, q.front().second});
            q.pop();
        }
        
        if(q.front().second == location)    break;
        else {
            priorities[q.front().second] = -1;
            q.pop();
        }
    }    
    return answer;
}