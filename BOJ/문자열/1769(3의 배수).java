import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String num = br.readLine();
        int result = 0;

        while(num.length() > 1) {
            int sum = 0;
            for(char token : num.toCharArray())
                sum += (token - '0');

            num = String.valueOf(sum);
            result++;
        }

        System.out.println(result);
        System.out.println(Integer.parseInt(num) % 3 == 0 ? "YES" : "NO");
        br.close();
    }
}