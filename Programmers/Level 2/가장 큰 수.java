import java.util.Arrays;
import java.util.Comparator;

class Solution {
    // Greedy 방식으로 가장 큰 값부터 하나씩 문자열에 붙인다
    static String getMax(String[] strings){
        if(strings[0].equals("0"))  return "0";
        
        String answer = "";
        for(String s : strings){
            answer += s;
        }
        return answer;
    }
    
    public String solution(int[] numbers) {
        String[] strings = new String[numbers.length];
        
        for(int i=0;i<numbers.length;i++){
            strings[i] = String.valueOf(numbers[i]);
        }
        
        // 문자열을 내림차순으로 정렬
        Arrays.sort(strings, new Comparator<String>(){
            @Override
            public int compare(String o1, String o2) {
                return ((o2 + o1).compareTo(o1 + o2));
            }
        });
        
        return getMax(strings);
    }
}