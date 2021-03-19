#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string, int> m;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    m[words[0]]++;
    for(int i=1;i<words.size();i++){
        string word = words[i];
        string before = words[i-1];
        if(m[word] == 1 || before[before.length() - 1] != word[0]){
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
        else m[word]++;
        if(i == words.size() - 1){
            answer.push_back(0);
            answer.push_back(0);
        }
    }
    return answer;
}