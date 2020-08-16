import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int result = 0;

        String[] line = br.readLine().split("\\-");
        String[] front = line[0].split("\\+");
        for(String tmp : front) result += Integer.parseInt(tmp); // 앞부분(첫번째 - 기준으로 왼쪽) 모두 더해주기

        for(int i=1;i<line.length;i++){ // 뒷부분(첫번째 - 기준으로 오른쪽) 모두 빼주기
            String[] back = line[i].split("\\+");
            for(String tmp : back)  result -= Integer.parseInt(tmp);
        }
        System.out.println(result);
    }
}