import java.util.Map;
import java.util.HashMap;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        // Initialize
        Map<String, Integer> orderMap = new HashMap<>();
        for (int order=0; order<players.length; order++) {
            orderMap.put(players[order], order);
        }
            
        // Race    
        for (String name : callings) {
            int order = orderMap.get(name);
            swap(players, order-1, order, orderMap);
        }
        
        // Return
        return players;
    }
    
    private void swap(String[] race, int front, int back, Map<String, Integer> orderMap) {
        // Swap
        String temp = race[front];
        race[front] = race[back];
        race[back] = temp;
        
        // Update Map
        orderMap.put(race[front], orderMap.get(race[front]) - 1);
        orderMap.put(race[back], orderMap.get(race[back]) + 1);
    }
}