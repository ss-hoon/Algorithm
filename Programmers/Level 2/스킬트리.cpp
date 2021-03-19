#include <string>
#include <vector>

using namespace std;
int check[26];

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=0;i<skill.length();i++)   check[skill[i] - 'A'] = 1;
    
    for(string str : skill_trees){
        int pos = 0;
        for(int i=0;i<str.length();i++){
            if(check[str[i] - 'A']){
                if(skill[pos++] != str[i])    break;
            }
            if(i == str.length() - 1)   answer++;
        }
    }
    return answer;
}