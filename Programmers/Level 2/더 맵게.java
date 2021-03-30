import java.util.PriorityQueue;

class Solution {
    static PriorityQueue<Integer> pq = new PriorityQueue<>();
    
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        // scoville 배열의 모든 값을 우선순위 큐에 삽입
        for(int item : scoville){
            pq.add(item);
        }
        
        // 우선순위 큐의 크기가 1보다 크고 루트가 K보다 작은경우 반복
        // 두 element를 꺼내 연산을 하고 다시 우선순위 큐에 삽입
        while(pq.size() > 1 && pq.peek() < K){
            answer++;
            int a = pq.poll();                
            int b = pq.poll();

            pq.add(a + b * 2);
        }
        
        // 최종 우선순위 큐의 크기가 2보다 작고 루트가 K보다 작은 경우에는 -1 return
        if(pq.size() < 2 && pq.peek() < K)  return -1;
        else return answer;
    }
}