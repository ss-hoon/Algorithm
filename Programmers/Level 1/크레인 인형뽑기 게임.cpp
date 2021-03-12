#include <string>
#include <vector>
#include <stack>

using namespace std;
stack<int> bucket, line[1001];
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    for(int j = 0; j < board.size(); j++){
        for(int i = board.size() - 1; i >= 0; i--){
            if(board[i][j] == 0)    break;
            
            line[j + 1].push(board[i][j]);
        }
    }
    
    for(int i = 0; i < moves.size(); i++){
        int crane = moves[i];
        
        if(line[crane].empty()) continue;
        
        if(!bucket.empty() && (bucket.top() == line[crane].top())){
            bucket.pop();
            answer += 2;
        }    
        else{
            bucket.push(line[crane].top());
        }
        line[crane].pop();
    }
    return answer;
}