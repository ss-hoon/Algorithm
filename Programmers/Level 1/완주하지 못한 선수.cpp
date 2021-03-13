#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    multiset<string> hash;
    string answer = "";
    for(int i=0;i<participant.size();i++){
        hash.insert(participant[i]);
    }
    
    for(int i=0;i<completion.size();i++){
        auto it = hash.find(completion[i]);
        hash.erase(it);
    }
    
    answer = *(hash.begin());
    return answer;
}