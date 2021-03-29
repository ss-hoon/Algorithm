import java.util.Queue;
import java.util.LinkedList;

class Solution {
    static class info{
        int weight, time;
        
        public info(int weight, int time){
            this.weight = weight;
            this.time = time;
        }
    }
    
    static Queue<info> que = new LinkedList<>();
    
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        // init
        int time = 1;
        int idx = 1;
        int bridge_weight = truck_weights[0];
        int bridge_truck = 1;
        
        que.add(new info(truck_weights[0], bridge_length + 1));
        
        // 다리에 트럭이 없을 때까지 반복
        while(!que.isEmpty()){
            time++;
            
            // 현재 시간과 도착 시간이 동일한 경우
            // 큐에서 트럭을 빼주면서 현재 다리 무게, 트럭 개수를 변경한다
            if(que.peek().time == time){
                info front = que.poll();
                bridge_weight -= front.weight;
                bridge_truck--;
            }
            
            // 기다리고 있는 트럭이 다리에 올라갈 수 있는 경우
            // 트럭을 큐에 삽입하고 현재 다리 무게, 트럭 개수를 변경한다
            if(idx < truck_weights.length && bridge_weight + truck_weights[idx] <= weight){
                if(bridge_truck < bridge_length){
                    que.add(new info(truck_weights[idx], time + bridge_length));
                    bridge_weight += truck_weights[idx++];
                    bridge_truck++;
                }
            }
        }
        return time;
    }
}