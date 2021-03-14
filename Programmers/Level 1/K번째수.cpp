#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0;i<commands.size();i++){
        int start = commands[i][0];
        int end = commands[i][1];
        int seq = commands[i][2];
        
        vector<int> temp(end-start+1);
        copy(array.begin()+start-1, array.begin()+end, temp.begin());
        sort(temp.begin(), temp.end());
        answer.push_back(temp[seq-1]);
    }
    return answer;
}