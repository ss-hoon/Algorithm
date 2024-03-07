import java.util.PriorityQueue;

class Solution {
    public int solution(int n, int k, int[] enemy) {
        // 초기화
        int answer = 0, sum = 0;
        PriorityQueue<Integer> round = new PriorityQueue<>();
        
        for (int soldier : enemy) {
            sum += soldier;
            round.add(-soldier);
            
            // 1. 깰 수 없을 때 무적권을 하나씩 쓴다.
            while (n < sum && k > 0 && !round.isEmpty()) {
                sum += round.poll();
                k--;
            }
            
            // 2-1. 못 막은 경우 반복 중지
            if (n < sum) {
                break;
            }
            
            // 2-2. 막은 경우 라운드 증가 후 다시 반복
            answer++;
        }
        
        // 2. 라운드 반환
        return answer;
    }
}
