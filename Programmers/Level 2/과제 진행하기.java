import java.util.*;

class Solution {
    public String[] solution(String[][] plans) {
        int len = plans.length;
        int write = 0;
        String[] answer = new String[len];
            
        Stack<String[]> st = new Stack<>();
        PriorityQueue<String[]> pq = new PriorityQueue<>((s1, s2) -> {
            return s1[1].compareTo(s2[1]);
        });
        
        for (int idx=0; idx<len; idx++) {
            pq.add(plans[idx]);
        }
        
        while (!pq.isEmpty()) {
            String[] homework = pq.poll();
            String[] startTime = homework[1].split(":");
            int time = Integer.parseInt(startTime[0]) * 60 + Integer.parseInt(startTime[1]);
            int homeworkTime = Integer.parseInt(homework[2]);
            int nextTime = 0;
            
            // 현재 과제를 할 수 있는 만큼 수행
            if (pq.isEmpty()) {
                answer[write++] = homework[0];
            } else {
                String[] nextStartTime = pq.peek()[1].split(":");
                nextTime = Integer.parseInt(nextStartTime[0]) * 60 + Integer.parseInt(nextStartTime[1]);
                
                // 완료한 경우 -> answer에 추가
                // 완료하지 못한 경우 -> Stack에 추가
                int diff = nextTime - time;
                if (homeworkTime <= diff) {
                    answer[write++] = homework[0];
                } else {
                    st.push(new String[]{ homework[0], String.valueOf(homeworkTime - diff)});
                }
            }
            
            // 밀린 과제 수행
            time += homeworkTime;
            if (nextTime == 0) nextTime = Integer.MAX_VALUE;
            while (!st.isEmpty() && time < nextTime) {
                String[] remainHomework = st.pop();
                
                String name = remainHomework[0];
                int remainTime = Integer.parseInt(remainHomework[1]);
                
                if (remainTime <= nextTime - time) {
                    answer[write++] = name;
                    time += remainTime; 
                } else {
                    st.push(new String[]{name, String.valueOf(remainTime - nextTime + time)});
                    time = nextTime;
                }
            }
        }
        
        return answer;
    }
}