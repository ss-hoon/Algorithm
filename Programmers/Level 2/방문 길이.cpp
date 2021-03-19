#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int RobotY = 5, RobotX = 5;
int colVisit[11][11] = {0};
int rowVisit[11][11] = {0};
int dy[4] = {1, 0, 0, -1};
int dx[4] = {0, -1, 1, 0};

bool outOfRange(int y, int x){
    if(y < 0 || y > 10 || x < 0 || x > 10)  return true;
    return false;
}

int solution(string dirs) {
    int answer = 0, op;
    for(char oper : dirs){
        if(oper == 'U') op = 0;
        else if(oper == 'L') op = 1;
        else if(oper == 'R') op = 2;
        else op = 3;
        
        if(outOfRange(RobotY + dy[op], RobotX + dx[op]))    continue;
        
        if(oper == 'U' && colVisit[RobotY][RobotX] == 0){
            colVisit[RobotY][RobotX] = 1;
            answer++;
        }
        if(oper == 'D' && colVisit[RobotY - 1][RobotX] == 0){
            colVisit[RobotY - 1][RobotX] = 1;
            answer++;
        }
        if(oper == 'L' && rowVisit[RobotY][RobotX - 1] == 0){
            rowVisit[RobotY][RobotX - 1] = 1;
            answer++;
        }
        if(oper == 'R' && rowVisit[RobotY][RobotX] == 0){
            rowVisit[RobotY][RobotX] = 1;
            answer++;
        }
        
        RobotY += dy[op];
        RobotX += dx[op];
    }
    return answer;
}