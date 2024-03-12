import java.util.Stack;

class Solution {
    public int solution(int[] order) {
        // 초기화
        Stack<Integer> subBelt = new Stack<>();
        int answer = 0;
        
        // 1. 컨베이어 벨트에서 나오는 상자가 트럭에 넣어야 하는 상자가 아니면 보조 컨베이어 벨트에 넣는다.
        // 보조 컨베이어 벨트에 있는 상자를 넣을 수 있는 만큼 넣는다.
        for (int box=1; box<=order.length; box++) {
            subBelt.push(box);
            
            while (!subBelt.isEmpty()) {
                if (subBelt.peek() == order[answer]) {
                    subBelt.pop();
                    answer++;
                } else {
                    break;
                }
            }
        }
        
        // 2. 넣을 수 있는 상자 수 반환
        return answer;
    }
}
