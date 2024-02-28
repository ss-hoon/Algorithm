import java.util.PriorityQueue;
import java.util.Arrays;

class Solution {
    public int solution(String[][] book_time) {
        // 초기화
        PriorityQueue<Integer> bookTime = new PriorityQueue<>();
        
        // 1. 시간 순서대로 정렬
        Arrays.sort(book_time, (s1, s2) -> s1[0].compareTo(s2[0]));
        
        // 2. book_time을 하나씩 보면서 우선순위 큐의 가장 위쪽에 있는 노드와 비교
        // 비교할 노드가 우선순위 큐의 가장 위쪽에 있는 노드보다 작은 경우 우선순위 큐에 추가
        // 비교할 노드가 우선순위 큐의 가장 위쪽에 있는 노드보다 크거나 같은 경우 위쪽 노드를 갱신해서 다시 큐에 넣는다.
        for (String[] book : book_time) {
            int startTime = parseTime(book[0]);
            int endTime = parseTime(book[1]) + 10;
            
            if (bookTime.isEmpty()) {
                bookTime.add(endTime);
                continue;
            }
            
            int earlyBookTime = bookTime.peek();
            
            if (startTime >= earlyBookTime) {
                bookTime.poll();
            }
            
            bookTime.add(endTime);
        }
        
        // 3. 우선순위 큐 안에 있는 노드 개수를 반환한다.
        return bookTime.size();
    }
    
    private int parseTime(String time) {
        String hh = time.split(":")[0];
        String mm = time.split(":")[1];
        
        return Integer.parseInt(hh) * 60 + Integer.parseInt(mm);
    }
}
