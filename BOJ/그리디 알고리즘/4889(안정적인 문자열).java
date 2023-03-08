import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int order = 1;
        String line;
        StringBuilder sb = new StringBuilder();
        while((line = br.readLine()).charAt(0) != '-') {
            int open = 0, result = 0;

            for(char token : line.toCharArray()) {
                // 열린 괄호가 없는데 닫힌 괄호가 나온 경우에는 여는 괄호로 바꾼다.
                if(open == 0 && token == '}') {
                    result++;
                    token = '{';
                }

                // 여는 괄호인 경우에는 추가
                // 닫는 괄호인 경우에는 지금까지 열린 괄호 중 하나와 함께 없앤다
                if(token == '{')    open++;
                else open--;
            }

            sb.append(order++).append(". ").append(result + open / 2).append("\n");
        }

        System.out.println(sb);
    }
}