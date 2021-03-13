#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1단계
    for(int i=0;i<new_id.length();i++)
        answer += tolower(new_id[i]);
    
    // 2단계
    for(int i=0;i<answer.length();i++){
        if(answer[i] >= 97 && answer[i] <= 122) continue;
        else if(answer[i] >= 48 && answer[i] <= 57) continue;
        else if(answer[i] == '-' || answer[i] == '_' || answer[i] == '.')   continue;
        else {
            answer.erase(i, 1);
            i--;
        }
    }
    
    // 3단계
    for(int i=0;i<answer.length()-1;i++){
        if(answer[i] == '.' && answer[i+1] == '.'){
            answer.erase(i, 1);
            i--;
        }
    }
    
    // 4단계
    if(!answer.empty() && answer.front() == '.')    answer.erase(answer.begin());
    if(!answer.empty() && answer.back() == '.')    answer.pop_back();
    
    // 5단계
    if(answer.empty())  answer = "a";
    
    // 6단계
    if(answer.length() >= 16){
        answer = answer.substr(0, 15);
        while(answer.front() == '.') answer.erase(answer.begin());
        while(answer.back() == '.') answer.pop_back();
    }
    
    // 7단계
    while(answer.length() <= 2){
        answer += answer.back();
    }
    
    return answer;
}