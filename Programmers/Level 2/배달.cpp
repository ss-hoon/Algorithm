#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector< pair<int, int> >adj[51];
priority_queue< pair<int,int> > pq;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<int> cache(N + 1, 1e9);
    for(int i=0;i<road.size();i++){
        int start = road[i][0];
        int end = road[i][1];
        int weight = road[i][2];
        
        adj[start].push_back({end, weight});
        adj[end].push_back({start, weight});
    }
    
    cache[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        int dist = -pq.top().first;
        int start = pq.top().second;
        pq.pop();
        
        if(cache[start] < dist) continue;
        
        for(int i=0;i<adj[start].size();i++){
            int next = adj[start][i].first;
            int nextDist = dist + adj[start][i].second;
            
            if(nextDist < cache[next]){
                cache[next] = nextDist;
                pq.push({-nextDist, next});
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        if(cache[i] <= K)   answer++;
    }
    return answer;
}