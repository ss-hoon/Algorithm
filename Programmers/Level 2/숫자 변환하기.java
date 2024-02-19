import java.util.Queue;     
import java.util.LinkedList;

class Solution {
    public int solution(int x, int y, int n) {
        int[] cache = new int[1000001];
        Queue<int[]> que = new LinkedList<int[]>();
        
        que.add(new int[] {0, x});
        while (!que.isEmpty()) {
            int[] front = que.poll();
            
            if (front[1] == y) {
                return front[0];
            }
            
            if (front[1] + n <= y && cache[front[1] + n] == 0) {
                cache[front[1] + n] = front[0] + 1;
                que.add(new int[] {front[0] + 1, front[1] + n});
            }
            
            if (front[1] * 2 <= y && cache[front[1] * 2] == 0) {
                cache[front[1] * 2] = front[0] + 1;
                que.add(new int[] {front[0] + 1, front[1] * 2});
            } 
            
            if (front[1] * 3 <= y && cache[front[1] * 3] == 0) {
                cache[front[1] * 3] = front[0] + 1;
                que.add(new int[] {front[0] + 1, front[1] * 3});
            }
        }
        
        return -1;
    }
}
