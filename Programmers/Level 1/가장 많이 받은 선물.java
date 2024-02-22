import java.util.Map;
import java.util.HashMap;

class Solution {
    public int solution(String[] friends, String[] gifts) {
        
        // 초기화
        int answer = 0;
        int len = friends.length;
        Map<String, Integer> friendIdx = new HashMap<>();
        int[][] presents = new int[len][len];
        int[] presentIndex = new int[len];
        
        // 1. friends를 Map으로 저장
        for (int idx=0; idx<len; idx++) {
            friendIdx.put(friends[idx], idx);
        }
        
        // 2. gifts를 순회하며 준 사람/받은 사람을 표기 + 선물 지수 계산
        for (String line : gifts) {
            String[] gift = line.split(" ");
            
            int giveIdx = friendIdx.get(gift[0]);
            int sendIdx = friendIdx.get(gift[1]);
            
            presents[giveIdx][sendIdx]++;
            presentIndex[giveIdx]++;
            presentIndex[sendIdx]--;
        }
        
        // 3. 표기했던 준 사람/받은 사람 테이블을 순회하면서 가장 많이 받은 선물 개수 구하기
        for (int i=0; i<len; i++) {
            int sum = 0;
            
            for (int j=0; j<len; j++) {
                if (i == j)     continue;
                if (presents[i][j] > presents[j][i] ||
                   (presents[i][j] == presents[j][i] && presentIndex[i] > presentIndex[j])) {
                    sum++;
                } 
            }
            
            answer = Math.max(answer, sum);
        }
        
        return answer;
    }
}
