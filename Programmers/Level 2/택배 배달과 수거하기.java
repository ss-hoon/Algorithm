class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        // 초기화
        long answer = 0;
        int delivery = 0, pickup = 0;
        
        // 1. 맨 오른쪽 집부터 왼쪽 집까지 반복하며 배달, 수거를 한다.
        for (int idx=n-1; idx>=0; idx--) {
            delivery += deliveries[idx];
            pickup += pickups[idx];
            
            while (delivery > 0 || pickup > 0) {
                delivery -= cap;
                pickup -= cap;
                answer += (idx+1) * 2;
            }
        }
        
        // 2. 최소 거리를 반환한다.
        return answer;
    }
}
