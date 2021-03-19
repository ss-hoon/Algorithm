#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    vector<int> noWifi;
    int answer = 0, pos = 1;
    
    for(int i=0;i<stations.size();i++){
        if(stations[i] - w <= pos){
            pos = stations[i] + w + 1;
            continue;
        }
        
        noWifi.push_back(stations[i] - w - pos);
        pos = stations[i] + w + 1;
    }
    
    if(pos <= n) noWifi.push_back(n - pos + 1);
    
    for(int range : noWifi){
        if(range % (1 + 2 * w) == 0)    answer += (range / (1 + 2 * w));
        else answer += (range / (1 + 2 * w)) + 1;
    }
    return answer;
}