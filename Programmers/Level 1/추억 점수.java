import java.util.Map;
import java.util.HashMap;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        // Initialize
        Map<String, Integer> scores = new HashMap<>();
        for (int idx=0; idx<name.length; idx++) {
            scores.put(name[idx], yearning[idx]);
        }
        
        // Calculate
        int[] result = new int[photo.length];
        for (int test=0; test<photo.length; test++) {
            for (int idx=0; idx<photo[test].length; idx++) {                
                if (scores.containsKey(photo[test][idx])) {
                    result[test] += scores.get(photo[test][idx]);
                }
            }
        }
        
        // Return
        return result;
    }
}