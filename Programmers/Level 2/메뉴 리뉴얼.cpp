#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
unordered_map<string, int> foodMaps[11];
int maxCnt[11];

void comb(string str, int pos, string candidate){
    if(pos == str.length()){
        int len = candidate.length();
        if(len >= 2){
            foodMaps[len][candidate]++;
            maxCnt[len] = max(foodMaps[len][candidate], maxCnt[len]);
        }
        return;
    }
    
    comb(str, pos + 1, candidate + str[pos]);
    comb(str, pos + 1, candidate);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(string str : orders){
        sort(str.begin(), str.end());
        comb(str, 0, "");
    }
    
    for(int len : course){
        for(auto item : foodMaps[len]){
            if(item.second == maxCnt[len] && item.second >= 2){
                answer.push_back(item.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}