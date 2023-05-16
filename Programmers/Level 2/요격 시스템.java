import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        int len = targets.length;        
        Arrays.sort(targets, (a, b) -> a[0] - b[0]);
        
        int answer = 0;
        int last = -1;
        for (int i=0; i<len; i++) {
            int[] missile = targets[i];
            
            if (missile[0] > last) {
                answer++;
                last = missile[1] - 1;
            } 
            
            if (missile[1] < last) {
                last = missile[1] - 1;
            }
        }
        
        return answer;
    }
}