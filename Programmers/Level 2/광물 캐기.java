import java.util.PriorityQueue;

class Solution {
    public int solution(int[] picks, String[] minerals) {
        // 초기화
        int answer = 0;
        int cntPicks = 0;
        int pickIdx = 0;
        PriorityQueue<Integer> mineralQue = new PriorityQueue<>();
        int[][] fatigue = { {1, 1, 1}, {5, 1, 1}, {25, 5, 1} };
        
        for (int pick : picks) {
            cntPicks += pick;
        }
        
        // 1. 우선순위 큐에 광물 5개 묶음씩 넣는다. (다이아: 100, 철: 10, 돌: 1)
        // 현재 가지고 있는 곡괭이 수 * 5 이후로는 버림
        int sum = 0;
        int len = Math.min(minerals.length, cntPicks * 5);
        for (int idx=0; idx<len; idx++) {
            sum -= getMineral(minerals[idx]);
            
            if ((idx+1) % 5 == 0 || idx == len-1) {
                mineralQue.add(sum);
                sum = 0;
            }
        }
        
        // 2. 우선순위 큐에서 나오는 순서대로 가장 높은 곡괭이 선택 후 피로도 계산
        while (!mineralQue.isEmpty()) {
            while (picks[pickIdx] == 0)     pickIdx++;
            
            int sumMineral = -mineralQue.poll();
            int idx = 0;
            int[] mineral = new int[3];
            
            mineral[0] = sumMineral / 100;
            sumMineral -= mineral[0] * 100;
            mineral[1] = sumMineral / 10;
            mineral[2] = sumMineral % 10;
            
            for (int j=0; j<3; j++) {
                if (mineral[j] == 0)    continue;

                answer += fatigue[pickIdx][j];

                mineral[j]--;
                if (mineral[j] > 0)  j--;
            }
            
            picks[pickIdx]--;
        }
        
        // 3. 결과 반환
        return answer;
    }
    
    private int getMineral(String mineral) {
        switch (mineral) {
            case "diamond":
                return 100;
            case "iron":
                return 10;
            case "stone":
                return 1;
        }
        
        return 0;
    }
}
