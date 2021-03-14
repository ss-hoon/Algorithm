#include <string>
#include <vector>

using namespace std;
int month[12] = {0,31,29,31,30,31,30,31,31,30,31,30};
string dayOfTheWeek[7] = {"THU","FRI","SAT","SUN","MON","TUE","WED"};

string solution(int a, int b) {
    int day = b;
    while(--a)  day += month[a];
    return dayOfTheWeek[day % 7];
}