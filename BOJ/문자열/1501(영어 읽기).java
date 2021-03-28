import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;

public class Main {
    static HashMap<String, Integer>  map = new HashMap<>();

    // 문자열 재배치
    // 첫번째 글자 + sort(중간 문자열) + 마지막 글자
    // 문자 길이가 2 이하인 것은 그대로 return
    static String getString(String str){
        if(str.length() <= 2)    return str;
        else{
            char[] mid = str.substring(1, str.length() - 1).toCharArray();
            Arrays.sort(mid);
            return str.charAt(0) + String.valueOf(mid) + str.charAt(str.length() - 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        while(N-- > 0){
            String str = br.readLine();
            String word = getString(str);

            // 맵에 key가 있으면 해당 value에 + 1
            // 없으면 생성
            if(map.containsKey(word)){
                map.put(word, map.get(word) + 1);
            } else {
                map.put(word, 1);
            }
        }

        int M = Integer.parseInt(br.readLine());
        while(M-- > 0){
            boolean check = false;
            int answer = 1;
            String[] strArray = br.readLine().split(" ");

            for(String str : strArray) {
                String word = getString(str);

                // 한 문장의 경우의 수이므로
                // 한 단어당 해석할 수 있는 경우의 수를 모두 곱해야 한다
                if(map.containsKey(word)){
                    answer *= map.get(word);
                    check = true;
                }
            }

            // 모든 단어가 해석될 수 없는 경우는 false
            // 0 출력
            if(!check)
                System.out.println(0);
            else
                System.out.println(answer);
        }
    }
}