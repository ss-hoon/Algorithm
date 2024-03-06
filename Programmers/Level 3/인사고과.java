import java.util.Arrays;

class Solution {
    public int solution(int[][] scores) {
        // 초기화
        int[] wanho = scores[0];
        int rank = 1, max = 0;
        
        // 1. 배열 정렬 (내림차순, 오름차순)
        Arrays.sort(scores, (a1, a2) -> a1[0] == a2[0] ? a1[1] - a2[1] : a2[0] - a1[0]);
        
        // 2. 한 사원씩 순회하면서 순위 계산
        for (int[] score : scores) {
            if (score[1] < max) {
                if (score[0] == wanho[0] && score[1] == wanho[1]) {
                    return -1;
                }
                
                continue;
            }
        
            if (wanho[0] + wanho[1] < score[0] + score[1]) {
                rank++;
            }
        
            max = Math.max(max, score[1]);
        }
        
        // 3. 순위 반환
        return rank;
    }
}
